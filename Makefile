build/main:
	gcc *.c -o build/main

run:
	gcc *.c -o build/main && ./build/main