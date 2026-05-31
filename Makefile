CC := gcc
CFLAGS := -Wall -Wextra -g3 -DADS2_SEPARATE_COMPILATION -Iinclude
TARGET := output/demo
SOURCES := demo.c src/array.c src/file_utils.c src/linked_lists.c src/string_utils.c

# Bonus demo target
BONUS_TARGET := output/dsa_demo
BONUS_SOURCES := Bonus/DSA-Demo.c src/Dataset_Analysis.c src/file_utils.c src/string_utils.c

.PHONY: all clean run windows-x64

all: $(TARGET)

$(TARGET): $(SOURCES) | output
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

output:
	mkdir -p output

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(BONUS_TARGET)

# Cross-compile for Windows (x86_64 MinGW-w64)
windows-x64: CC := x86_64-w64-mingw32-gcc
windows-x64: CFLAGS := -Wall -Wextra -g3 -DADS2_SEPARATE_COMPILATION
windows-x64: TARGET := output/demo.exe
windows-x64: $(SOURCES) | output
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

.PHONY: bonus_demo run_bonus

bonus_demo: $(BONUS_TARGET)

$(BONUS_TARGET): $(BONUS_SOURCES) | output
	$(CC) $(CFLAGS) $(BONUS_SOURCES) -o $(BONUS_TARGET)

run_bonus: $(BONUS_TARGET)
	./$(BONUS_TARGET)