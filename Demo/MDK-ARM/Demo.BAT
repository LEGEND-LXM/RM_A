SET PATH=E:\keil_v5\ARM\ARMCC\Bin;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\dotnet\;C:\Program Files\Microsoft SQL Server\Client SDK\ODBC\110\Tools\Binn\;C:\Program Files (x86)\Microsoft SQL Server\120\Tools\Binn\;C:\Program Files\Microsoft SQL Server\120\Tools\Binn\;C:\Program Files\Microsoft SQL Server\120\DTS\Binn\;C:\Program Files (x86)\Windows Kits\8.1\Windows Performance Toolkit\;C:\Users\张卫国\AppData\Local\Microsoft\WindowsApps;C:\Users\张卫国\AppData\Local\GitHubDesktop\bin
SET CPU_TYPE=STM32F427IIHx
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Demo
SET CPU_CLOCK=0x0A037A00
"E:\keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via "demo\startup_stm32f427xx._ia"
"E:\keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "demo\main.__i"
"E:\keil_v5\ARM\ARMCC\Bin\ArmLink" --Via "Demo\Demo.lnp"
