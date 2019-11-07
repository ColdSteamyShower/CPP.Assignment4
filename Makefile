EXECUTABLE := RegistrarSimulator

SOURCES := registrarDriver.cpp fileLoader.cpp ./Simulation/Simulation.cpp ./Simulation/Student.cpp ./Simulation/Window.cpp

INCLUDES := -I ..\include
EXT := exe
CC := g++

syntax:
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)
