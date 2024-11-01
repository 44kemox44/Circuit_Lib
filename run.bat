@echo off
cd /d "%~dp0"  // Change to the directory where the batch file is located
g++ -o circuit_simulation examples/main.cpp src/Circuit.cpp src/Resistor.cpp -I include
if errorlevel 1 (
    echo Compilation failed.
    pause
    exit /b
)
circuit_simulation
pause
