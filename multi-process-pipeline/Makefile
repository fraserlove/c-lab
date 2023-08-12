CC = clang
CFLAGS = -Wall -Wextra -Iinclude

SRC_DIR = src
BUILD_DIR = build

SUM_SQUARES_SRC = $(SRC_DIR)/sum_squares.c $(SRC_DIR)/pipeline.c
PRIME_SIEVE_SRC = $(SRC_DIR)/prime_sieve.c $(SRC_DIR)/pipeline.c
SEND_INT_SRC = $(SRC_DIR)/send_int.c $(SRC_DIR)/pipeline.c
DOUBLE_INT_SRC = $(SRC_DIR)/double_int.c $(SRC_DIR)/pipeline.c
FIBONACCI_SEQUENCE_SRC = $(SRC_DIR)/fibonacci_sequence.c $(SRC_DIR)/pipeline.c

SUM_SQUARES_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SUM_SQUARES_SRC))
PRIME_SIEVE_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(PRIME_SIEVE_SRC))
SEND_INT_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SEND_INT_SRC))
DOUBLE_INT_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(DOUBLE_INT_SRC))
FIBONACCI_SEQUENCE_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(FIBONACCI_SEQUENCE_SRC))

SUM_SQUARES_TARGET = $(BUILD_DIR)/sum_squares
PRIME_SIEVE_TARGET = $(BUILD_DIR)/prime_sieve
SEND_INT_TARGET = $(BUILD_DIR)/send_int
DOUBLE_INT_TARGET = $(BUILD_DIR)/double_int
FIBONACCI_SEQUENCE_TARGET = $(BUILD_DIR)/fibonacci_sequence

all: $(SUM_SQUARES_TARGET) $(PRIME_SIEVE_TARGET) $(SEND_INT_TARGET) $(DOUBLE_INT_TARGET) $(FIBONACCI_SEQUENCE_TARGET)

# Link sum squares object files into executable
$(SUM_SQUARES_TARGET): $(SUM_SQUARES_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Link prine sieve object files into executable
$(PRIME_SIEVE_TARGET): $(PRIME_SIEVE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Link send int object files into executable
$(SEND_INT_TARGET): $(SEND_INT_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Link double int object files into executable
$(DOUBLE_INT_TARGET): $(DOUBLE_INT_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Link fibonacci sequence object files into executable
$(FIBONACCI_SEQUENCE_TARGET): $(FIBONACCI_SEQUENCE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile all object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
