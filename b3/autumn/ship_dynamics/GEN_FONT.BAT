setlocal enableextensions disabledelayedexpansion
for %%I in (mktexpk.exe) do set "mktexpk=%%~$PATH:I"
if not defined mktexpk exit 1
for /f "usebackq skip=17 tokens=1,2,3* delims=|" %%I in (%0) do (
  set dpi=%%I
  set bdpi=%%J
  set mag=%%K
  set font=%%L
  goto :sanitize
)
:sanitize
if defined dpi  set "dpi=%dpi:"=%"
if defined bdpi set "bdpi=%bdpi:"=%"
if defined mag  set "mag=%mag:"=%"
if defined font set "font=%font:"=%"
"%mktexpk%" --mfmode / --dpi "%dpi%" --bdpi "%bdpi%" --mag "%mag%" "%font%"
del %0 & exit %errorlevel%
1037|600|1+437/600|txmiaX
1037|600|1+437/600|ntx-Regular-tlf-ot1r
720|600|1+120/600|txmiaX
720|600|1+120/600|ntx-Regular-tlf-ot1r
600|600|600/600|txmiaX
600|600|600/600|ntx-Regular-tlf-ot1r
600|600|600/600|txsys
600|600|600/600|NewTXMI
540|600|540/600|txmiaX
540|600|540/600|ntx-Regular-tlf-ot1r
