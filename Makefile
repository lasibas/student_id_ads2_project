CC := gcc
CFLAGS := -Wall -Wextra -g3 -DADS2_SEPARATE_COMPILATION
TARGET := output/demo
SOURCES := demo.c src/array.c src/file_utils.c src/linked_lists.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SOURCES) | output
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

output:
	mkdir -p output

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)