CC = g++
FLAG = --std=c++11
SRC = main.cpp item.cpp lex_parser.cpp genCode.cpp
OUT = md2html


build:
	$(CC) $(SRC) $(FLAG) -o $(OUT)
debug:
	$(CC) $(SRC) $(FLAG) -g -o $(OUT)
clean:
	rm -f $(OUT)