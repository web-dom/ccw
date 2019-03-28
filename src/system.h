#ifndef SYSTEM_H
#define SYSTEM_H

const int TRUE;
const int FALSE;
const int SUCCESS;
const int FAIL;

#ifdef WASM
#define NULL ((void *)0)
#define size_t int

void stop_wasm_somehow(int code);
void *malloc(size_t size);
void free(void *__ptr);
void console_log(char *text);
char *read_file(char *fileName);
int write_file(char *fileName, void *contents, size_t len);
void assert(int cond, char *msg);

#else

#include <stdio.h>
#include <stdlib.h>

void console_log(char *text);
char *read_file(char *fileName);
int write_file(char *fileName, void *contents, size_t len);
void assert(int cond, char *msg);

#endif

#endif
