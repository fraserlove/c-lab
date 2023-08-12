CC = clang
CFLAGS = -Wall -Wextra -Iinclude

SRC_DIR = src
BUILD_DIR = build

TEST_STACK_SRC = $(SRC_DIR)/stack.c $(SRC_DIR)/test_stack.c
CALCULATOR_SRC = $(SRC_DIR)/stack.c $(SRC_DIR)/calculator.c $(SRC_DIR)/main.c

TEST_STACK_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_STACK_SRC))
CALCULATOR_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(CALCULATOR_SRC))

TEST_STACK_TARGET = $(BUILD_DIR)/test_stack
CALCULATOR_TARGET = $(BUILD_DIR)/calculator

all: $(TEST_STACK_TARGET) $(CALCULATOR_TARGET)

# Link test stack object files into executable
$(TEST_STACK_TARGET): $(TEST_STACK_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Link calculator object files into executable
$(CALCULATOR_TARGET): $(CALCULATOR_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile all object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
