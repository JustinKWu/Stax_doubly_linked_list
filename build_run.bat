echo off

echo Delete main.exe if it exists
del main.exe

echo Compile main.exe (doubly_linked_list.cpp)
g++ doubly_linked_list.cpp -o main.exe 

echo Running main.exe (doubly_linked_list.cpp)
echo ====================================
main.exe