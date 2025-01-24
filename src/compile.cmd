IF EXIST output.exe (del output.exe)
g++ -Iheaders main.cpp Choice.cpp Menu.cpp -o output.exe
start output.exe