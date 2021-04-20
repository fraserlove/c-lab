CC = clang
RM = rm -f
DFLAG = -g
GFLAGS = -Wall -Wextra
CFLAGS = $(DFLAG) $(GFLAGS) -c
LFLAGS = $(DFLAG) $(GFLAGS)

all: SumSquaresPipeline SievePipeline SendIntegerPipeline DoubleIntegerPipeline FibonacciSequencePipeline


SumSquaresPipeline: SumSquaresPipeline.o Pipeline.o
	$(CC) $(LFLAGS) SumSquaresPipeline.o Pipeline.o -o tests/SumSquaresPipeline

SievePipeline: SievePipeline.o Pipeline.o
	$(CC) $(LFLAGS) SievePipeline.o Pipeline.o -o tests/SievePipeline

SendIntegerPipeline: SendIntegerPipeline.o Pipeline.o
	$(CC) $(LFLAGS) SendIntegerPipeline.o Pipeline.o -o tests/SendIntegerPipeline

DoubleIntegerPipeline: DoubleIntegerPipeline.o Pipeline.o
	$(CC) $(LFLAGS) DoubleIntegerPipeline.o Pipeline.o -o tests/DoubleIntegerPipeline

FibonacciSequencePipeline: FibonacciSequencePipeline.o Pipeline.o
	$(CC) $(LFLAGS) FibonacciSequencePipeline.o Pipeline.o -o tests/FibonacciSequencePipeline


SumSquaresPipeline.o: SumSquaresPipeline.c
	$(CC) $(CFLAGS) SumSquaresPipeline.c

SievePipeline.o: SievePipeline.c
	$(CC) $(CFLAGS) SievePipeline.c

SendIntegerPipeline.o: SendIntegerPipeline.c
	$(CC) $(CFLAGS) SendIntegerPipeline.c

DoubleIntegerPipeline.o: DoubleIntegerPipeline.c
	$(CC) $(CFLAGS) DoubleIntegerPipeline.c

FibonacciSequencePipeline.o: FibonacciSequencePipeline.c
	$(CC) $(CFLAGS) FibonacciSequencePipeline.c


Pipeline.o: Pipeline.c Pipeline.h
	$(CC) $(CFLAGS) Pipeline.c


clean:
	$(RM) tests/SumSquaresPipeline tests/SievePipeline tests/SendIntegerPipeline tests/DoubleIntegerPipeline tests/FibonacciSequencePipeline *.o
