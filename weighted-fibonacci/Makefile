CC = clang
CFLAGS = -Wall -Wextra -Iinclude

SRC_DIR = src
BUILD_DIR = build

RECURSIVE_SRC = $(SRC_DIR)/recursive_fib.c $(SRC_DIR)/print_fib.c $(SRC_DIR)/safe_maths.c $(SRC_DIR)/main.c
ITERATIVE_SRC = $(SRC_DIR)/iterative_fib.c $(SRC_DIR)/print_fib.c $(SRC_DIR)/safe_maths.c $(SRC_DIR)/main.c

RECURSIVE_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(RECURSIVE_SRC))
ITERATIVE_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(ITERATIVE_SRC))

RECURSIVE_TARGET = $(BUILD_DIR)/recursive
ITERATIVE_TARGET = $(BUILD_DIR)/iterative

all: $(RECURSIVE_TARGET) $(ITERATIVE_TARGET)

# Link recursive object files into executable
$(RECURSIVE_TARGET): $(RECURSIVE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Link iterative object files into executable
$(ITERATIVE_TARGET): $(ITERATIVE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile all object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
