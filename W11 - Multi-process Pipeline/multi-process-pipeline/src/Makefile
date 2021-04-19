CC = clang
RM = rm -f
DFLAG = -g
GFLAGS = -Wall -Wextra
CFLAGS = $(DFLAG) $(GFLAGS) -c
LFLAGS = $(DFLAG) $(GFLAGS)

all: SumSquaresPipeline SievePipeline SendIntegerTest DoubleIntegerTest


SumSquaresPipeline: SumSquaresPipeline.o Pipeline.o
	$(CC) $(LFLAGS) SumSquaresPipeline.o Pipeline.o -o SumSquaresPipeline

SievePipeline: SievePipeline.o Pipeline.o
	$(CC) $(LFLAGS) SievePipeline.o Pipeline.o -o SievePipeline

SendIntegerTest: SendIntegerTest.o Pipeline.o
	$(CC) $(LFLAGS) SendIntegerTest.o Pipeline.o -o SendIntegerTest

DoubleIntegerTest: DoubleIntegerTest.o Pipeline.o
	$(CC) $(LFLAGS) DoubleIntegerTest.o Pipeline.o -o DoubleIntegerTest


SumSquaresPipeline.o: SumSquaresPipeline.c
	$(CC) $(CFLAGS) SumSquaresPipeline.c

SievePipeline.o: SievePipeline.c
	$(CC) $(CFLAGS) SievePipeline.c

SendIntegerTest.o: SendIntegerTest.c
	$(CC) $(CFLAGS) SendIntegerTest.c

DoubleIntegerTest.o: DoubleIntegerTest.c
	$(CC) $(CFLAGS) DoubleIntegerTest.c


Pipeline.o: Pipeline.c Pipeline.h
	$(CC) $(CFLAGS) Pipeline.c


clean:
	$(RM) SumSquaresPipeline SievePipeline SendIntegerTest DoubleIntegerTest *.o
