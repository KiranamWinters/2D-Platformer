@echo off

cls

cl -I ../include -Wall ../src/*.c ../libs/raylib.lib winmm.lib gdi32.lib opengl32.lib

echo -------------------------Build_Complete--------------------------