all:
	gcc -o test src/test/input_buffer_test.c src/main/input_buffer.c
	./test