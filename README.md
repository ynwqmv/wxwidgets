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


