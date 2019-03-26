all: lint build examples
build:
	cc -std=c90 --pedantic -o ccw main.c
lint:
	clang-format -i main.c
	clang-format -i test.c
examples:
	./ccw -o test.wasm test.c
serve:
	http-server -p 8080
