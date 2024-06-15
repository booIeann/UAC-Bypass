# Overview

User Account Control (UAC) is a security feature in Windows designed to prevent unauthorized changes to the operating system. This proof of concept script demonstrates a technique to bypass UAC, allowing an attacker to execute processes with elevated privileges without triggering a UAC prompt.

The script achieves this by creating a mock directory called ```'C:\\Windows \\System32'``` within your drive, we then move any [auto-elevating](https://imgur.com/a/5r2vp3X) executable to the System32 mock directory with the correct DLL that the executable runs and you will be able to completely bypass the UAC prompt. See examples of executables and the DLLs that they automatically run [here](https://github.com/booIeann/Windows-DLL-Vulnerabilities).
