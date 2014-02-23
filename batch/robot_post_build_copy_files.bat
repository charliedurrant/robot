setlocal enabledelayedexpansion
set source=%~1
set destination=%~2

if NOT exist "%source%" goto no_files
if NOT exist "%destination%" goto no_files


:files

echo -----  COPY FILES RESOURCES to "%destination%" ------
echo on

robocopy "%source%Resources" "%destination%\" /xo /e
echo ----- COPY LIRARY DLLS to flat directory -----
for /r %source% %%F in (.) do ROBOCOPY "%%F" %destination% *.dll /COPYALL /R:0 /xo 



echo -----  DELETE OLD FILES from "%destination%" ------
rem del "%destination%\AbacusServerClient.*" /F /Q
rem del "%destination%\AbacusServerService.*" /F /Q
rem del "%destination%\AbacusServerShared.*" /F /Q

:no_files

echo ------- CLEAR ERROR LEVEL for ROBOCOPY ----------
ver > nul