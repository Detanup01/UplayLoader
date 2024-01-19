_d.dll's are built with Debug mode!

The path.txt use to communicate to all uplay style dll file in ClientApp
Place your path to the txt
Example:
G:\CustomUplay\Client

The dll must in that directory, if you dont place the path.txt It automaticly try to use path next to the file (Currently no exit if fail)

main.crt file to know the file was signed by me.
(If you add this as Root CA you can sure all app are signed & tested by me | NOT NEEDED)

upc_r2 can be renamed to uplay_r2
upc_r1 can be renamed to uplay_r1

wintrust_o.dll
this DLL is the original of the wintrust.dll (from C:\Windows\System32\wintrust.dll) currently used as middleware to bypass WinVerifyTrust

wintrust.dll
this dll is the bypass for WinVerifyTrust. Make sure you add next to your .exe file and next to wintrust_o.dll!