CC = gcc
CFLAGS = -Wall -Wextra -pedantic -Wno-unused-parameter
CFILES = $(wildcard *.c)
HFILES = $(wildcard *.h)
EXENAME = myPoPc
FILENAME1 = main
FILENAME2 = func

${EXENAME}: ${CFILES} ${HFILES}
	${CC} ${CFLAGS} ${CFILES} ${HFILES} -o ${EXENAME}
clean: ${EXENAME}
	rm -f ${EXENAME}.o ${EXENAME}
	echo Clean done
