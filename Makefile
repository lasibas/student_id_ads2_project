CC := gcc
CFLAGS := -Wall -Wextra -g3 -DADS2_SEPARATE_COMPILATION
TARGET := output/demo
SOURCES := demo.c src/array.c src/file_utils.c src/linked_lists.c src/string_utils.c

.PHONY: all clean run windows-x64

all: $(TARGET)

$(TARGET): $(SOURCES) | output
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

output:
	mkdir -p output

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

# Cross-compile for Windows (x86_64 MinGW-w64)
windows-x64: CC := x86_64-w64-mingw32-gcc
windows-x64: CFLAGS := -Wall -Wextra -g3 -DADS2_SEPARATE_COMPILATION
windows-x64: TARGET := output/demo.exe
windows-x64: $(SOURCES) | output
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)