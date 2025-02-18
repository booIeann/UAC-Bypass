# UAC-Bypass (Patched)

This repository contains a proof of concept for bypassing User Account Control (UAC) on Windows using GoLang. The script demonstrates how to elevate privileges without triggering a UAC prompt by exploiting specific characteristics of Windows 10/11. 

## Background

User Account Control (UAC) is a security feature in Windows designed to prevent unauthorized changes to the operating system. When an application tries to perform an action that requires elevated privileges, UAC prompts the user for confirmation.

## Vulnerability Explanation

This proof of concept leverages a characteristic where system32 applications do not hash check any of their DLLs, meaning they can be swapped out without the system detecting the change. This vulnerability exists because the integrity of the DLLs is not verified at runtime, allowing a malicious DLL to be loaded by a legitimate system32 application, thereby gaining elevated privileges.

It is worth noting that this is a design choice rather than a vulnerability in the traditional sense. System32 applications are expected to be protected by overall system integrity mechanisms, and they are updated frequently. If Windows implemented strict DLL verification, it could lead to issues where applications fail to run if they are updated or replaced incorrectly.

## Assumptions

My current assumption is that Microsoft does not plan to change this behaviour, as enforcing strict DLL verification could potentially cause stability issues and impact application compatibility. Ensuring all DLLs are correct and up-to-date would most likely cause performance issues, I believe right now that Windows only does these checks at critical points (system updates or application installations). Therefore, once these have been completed, we can easily bypass this just by swapping out the dlls and moving them and the executable we are targeting, into another directory.

## Contents

- `docs/overview.md`: Detailed overview of the UAC bypass technique.
- `docs/methods.md`: Explanation of the methods used in the script.
- `docs/mitigation.md`: Recommendations for mitigating this type of UAC bypass.
- `src/main.go`: The Go source code for the UAC bypass script.
- `src/dll/main.c`: The C source code for the UAC bypass dll.
- `src/dll/dxgi.dll`: The compiled C source code for the UAC bypass dll.

## Usage

To run the script, compile it using Go and execute the binary:

```sh
go build -o uac-bypass main.go
./uac-bypass
```
