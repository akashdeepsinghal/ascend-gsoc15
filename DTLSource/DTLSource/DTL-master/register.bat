C:
cd C:\Windows\Microsoft.NET\Framework\v4.0.30319

regasm.exe /u C:\DTLSource\DTLSource\DTL-master\DWSIM\bin\Debug\DTL.dll \tlb:C:\DTLSource\DTLSource\DTL-master\DWSIM\bin\Debug\DTL.tlb

regasm.exe  C:\DTLSource\DTLSource\DTL-master\DWSIM\bin\Debug\DTL.dll /codebase /tlb:C:\DTLSource\DTLSource\DTL-master\DWSIM\bin\Debug\DTL.tlb
pause