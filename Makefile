CC       = gcc
CXX      = g++
CPP      = $(CC) -E
CFLAGS   = -W -Wall -Wextra -pedantic -O2 -g
CFLAGSCV = -lcv -lcxcore -lml -lhighgui

SRC	=	src/main.c \
		src/alloc.c \
		src/segment.c \
		src/instructions.c \
		src/lib.c \

main: $(SRC)
	$(CC) $(SRC) -o cexlang src/read_bmp.c $(CFLAGS)
	strip cexlang

opencv: $(SRC)
	$(CC) -D OPENCV -o cexlang $(SRC) src/img.c $(CFLAGS) $(CFLAGSCV)
	strip cexlang

clean:
	-rm -f cexlang cexlang.exe
