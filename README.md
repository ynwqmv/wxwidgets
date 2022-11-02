# Tetris Game

## Used:
`CXX 11`  
`wxWidgets 3.0.1`  
`Makefile`  
____

## Build | Linux
#### Makefile
```bash
make
./Tetris

```

```bash
g++ -o Tetris Piece.o Board.o TetrisGame.o main.o `wx-config --libs`
g++ `wx-config --cppflags` -Wall -c TetrisGame.cpp
g++ -Wall -MM Piece.cpp Board.cpp TetrisGame.cpp main.cpp > .depend
g++ -o foo foo.cc  `wx-config --cxxflags` `wx-config  --libs` -lglut -lGL -lGLU

```
____

```cmake
cmake_minimum_required(VERSION 3.7.1)
project(main)


find_package(wxWidgets 3.0.5 REQUIRED)
find_package(OpenGL)
find_package(GLUT)
include(${wxWidgets_USE_FILE})


link_libraries(${wxWidgets_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE main.cpp)


```

