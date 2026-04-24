CC := gcc
CFLAGS := -Wall -Wextra -g3
TARGET := output/demo
SOURCES := demo.c src/array.c

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