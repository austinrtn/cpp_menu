IF EXIST output.exe (del output.exe)    

cd src
g++ -Iheaders main.cpp Menu.cpp -o ../output.exe
cd ../

if %errorlevel% equ 0 (
    ECHO Running program...
    START output.exe
) else (
    ECHO Compilation failed.  See errors.
)