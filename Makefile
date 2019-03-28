all: lint build examples
build:
	cc -std=c90 -w -D WASM --pedantic -o ccw src/system.c src/main.c
	cc -std=c90 --pedantic -o ccw src/system.c src/main.c
lint:
	clang-format -i src/system.h src/system.c src/main.c
	clang-format -i examples/helloworld/helloworld.c
examples:
	./ccw -o examples/helloworld/helloworld.wasm examples/helloworld/helloworld.c
serve:
	http-server -p 8080
