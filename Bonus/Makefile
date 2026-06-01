CC := gcc
CFLAGS := -Wall -Wextra -g3 -I../include -DADS2_SEPARATE_COMPILATION

SRC_DIR := ../src
OUTPUT_DIR := output

SOURCES := dataset_analysis.c $(SRC_DIR)/Dataset_Analysis_Header_Code.c $(SRC_DIR)/file_utils.c $(SRC_DIR)/string_utils.c
TARGET := $(OUTPUT_DIR)/dataset_analysis

.PHONY: all clean

all: $(TARGET)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(TARGET): $(SOURCES) | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -rf $(OUTPUT_DIR)
