all: lint build examples
build:
	cc -std=c90 -w -D WASM --pedantic -o ccw system.c main.c
	cc -std=c90 --pedantic -o ccw system.c main.c
lint:
	clang-format -i main.c
	clang-format -i test.c
examples:
	./ccw -o test.wasm test.c
serve:
	http-server -p 8080
