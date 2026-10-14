SRC=src/*

main: $(SRC)
	gcc -o main $(SRC) -lraylib
