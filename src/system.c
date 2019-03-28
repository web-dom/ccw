#include "system.h"

const int SUCCESS = 1;
const int FAIL = 0;

const int TRUE = 1;
const int FALSE = 0;

#ifdef WASM
void stop_wasm_somehow(int code) {}

void *malloc(size_t size) {}
void free(void *__ptr) {}

void console_log(char *text) {}

char *read_file(char *fileName) {}

int write_file(char *fileName, void *contents, size_t len) {}

void assert(int cond, char *msg) {
  if (cond == 0) {
    console_log(msg);
    stop_wasm_somehow(0);
  }
}

#else
void console_log(char *text) { printf(text); }

char *read_file(char *fileName) {
  FILE *file = fopen(fileName, "r");
  char *code;
  size_t n = 0;
  int c;

  if (file == NULL) {
    return (NULL);
  }
  code = malloc(10000);

  while ((c = fgetc(file)) != EOF) {
    code[n++] = (char)c;
  }

  code[n] = '\0';

  return (code);
}

int write_file(char *fileName, void *contents, size_t len) {
  FILE *file = fopen(fileName, "w");

  if (file == NULL) {
    return (0);
  }
  fwrite(contents, len, 1, file);
  fclose(file);

  return (1);
}

void assert(int cond, char *msg) {
  if (cond == 0) {
    console_log(msg);
    exit(0);
  }
}
#endif
