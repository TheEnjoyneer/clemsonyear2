SRC = driver.cpp Image.cpp Header.cpp Color.cpp Pixel.cpp Point.cpp
OBJ = driver.o Image.o Header.o Color.o Pixel.o Point.o
PROG = driver

$(PROG) : $(OBJ)
	g++ $(OBJ) -o $(PROG) -Wall -lm -g

$(OBJ) : $(SRC)


clean:
	rm *.o driver
