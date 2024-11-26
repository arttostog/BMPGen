OUTPUT = bmpgen

$(OUTPUT) :
	gcc -Wall ./src/main.c -o $(OUTPUT)

clean:
	del $(OUTPUT).exe