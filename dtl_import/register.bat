C:
cd C:\Windows\Microsoft.NET\Framework\v4.0.30319

regasm.exe /u D:\DTLSource\DTLSource\DTL-master\DWSIM\bin\Debug\DTL.dll \tlb:D:\DTLSource\DTLSource\DTL-master\DWSIM\bin\Debug\DTL.tlb

regasm.exe  D:\DTLSource\DTLSource\DTL-master\DWSIM\bin\Debug\DTL.dll /codebase /tlb:D:\DTLSource\DTLSource\DTL-master\DWSIM\bin\Debug\DTL.tlb

pause