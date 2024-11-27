OUTPUT = bmpgen
GCC_FLAGS = -Wall -std=c17 -pedantic -I./include

ifeq ($(OS), Windows_NT)
	CLEAN_COMMAND = del $(OUTPUT).exe
else
	CLEAN_COMMAND = rm $(OUTPUT)
endif

$(OUTPUT) :
	gcc -Wall $(wildcard ./src/*.c) -o $(OUTPUT)

clean:
	$(CLEAN_COMMAND)