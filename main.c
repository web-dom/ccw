/* Copyright @ 2019 Richard Anaya. All rights reserved. */

/* STANDARD LIBRARY SPECIFIC CODE */
/* THESE FUNCTIONS ARE THE ONLY ENTRY POINTS */
#include <stdio.h>
#include <stdlib.h>

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

/*-------------------------------------------*/

/* Constants */

const int I32 = 127;
const int I64 = 126;
const int F32 = 125;
const int F64 = 124;
const int ANYFUNC = 112;
const int FUNC = 96;
const int EMPTY = 64;
const int SECTION_CUSTOM = 0;
const int SECTION_TYPE = 1;
const int SECTION_IMPORT = 2;
const int SECTION_FUNCTION = 3;
const int SECTION_TABLE = 4;
const int SECTION_MEMORY = 5;
const int SECTION_GLOBAL = 6;
const int SECTION_EXPORT = 7;
const int SECTION_START = 8;
const int SECTION_ELEMENT = 9;
const int SECTION_CODE = 10;
const int SECTION_DATA = 11;
const int UNREACHABLE = 0;
const int NOP = 1;
const int BLOCK = 2;
const int LOOP = 3;
const int IF = 4;
const int ELSE = 5;
const int END = 11;
const int BR = 12;
const int BR_IF = 13;
const int BR_TABLE = 14;
const int RETURN = 15;
const int CALL = 16;
const int CALL_INDIRECT = 17;
const int DROP = 26;
const int SELECT = 27;
const int LOCAL_GET = 32;
const int LOCAL_SET = 33;
const int LOCAL_TEE = 34;
const int GLOBAL_GET = 35;
const int GLOBAL_SET = 36;
const int I32_LOAD = 40;
const int I64_LOAD = 41;
const int F32_LOAD = 42;
const int F64_LOAD = 43;
const int I32_LOAD8_S = 44;
const int I32_LOAD8_U = 45;
const int I32_LOAD16_S = 46;
const int I32_LOAD16_U = 47;
const int I64_LOAD8_S = 48;
const int I64_LOAD8_U = 49;
const int I64_LOAD16_S = 50;
const int I64_LOAD16_U = 51;
const int I64_LOAD32_S = 52;
const int I64_LOAD32_U = 53;
const int I32_STORE = 54;
const int I64_STORE = 55;
const int F32_STORE = 56;
const int F64_STORE = 57;
const int I32_STORE8 = 58;
const int I32_STORE16 = 59;
const int I64_STORE8 = 60;
const int I64_STORE16 = 61;
const int I64_STORE32 = 62;
const int CURRENT_MEMORY = 63;
const int GROW_MEMORY = 64;
const int I32_CONST = 65;
const int I64_CONST = 66;
const int F32_CONST = 67;
const int F64_CONST = 68;
const int I32_EQZ = 69;
const int I32_EQ = 70;
const int I32_NE = 71;
const int I32_LT_S = 72;
const int I32_LT_U = 73;
const int I32_GT_S = 74;
const int I32_GT_U = 75;
const int I32_LE_S = 76;
const int I32_LE_U = 77;
const int I32_GE_S = 78;
const int I32_GE_U = 79;
const int I64_EQZ = 80;
const int I64_EQ = 81;
const int I64_NE = 82;
const int I64_LT_S = 83;
const int I64_LT_U = 84;
const int I64_GT_S = 85;
const int I64_GT_U = 86;
const int I64_LE_S = 87;
const int I64_LE_U = 88;
const int I64_GE_S = 89;
const int I64_GE_U = 90;
const int F32_EQ = 91;
const int F32_NE = 92;
const int F32_LT = 93;
const int F32_GT = 94;
const int F32_LE = 95;
const int F32_GE = 96;
const int F64_EQ = 97;
const int F64_NE = 98;
const int F64_LT = 99;
const int F64_GT = 100;
const int F64_LE = 101;
const int F64_GE = 102;
const int I32_CLZ = 103;
const int I32_CTZ = 104;
const int I32_POPCNT = 105;
const int I32_ADD = 106;
const int I32_SUB = 107;
const int I32_MUL = 108;
const int I32_DIV_S = 109;
const int I32_DIV_U = 110;
const int I32_REM_S = 111;
const int I32_REM_U = 112;
const int I32_AND = 113;
const int I32_OR = 114;
const int I32_XOR = 115;
const int I32_SHL = 116;
const int I32_SHR_S = 117;
const int I32_SHR_U = 118;
const int I32_ROTL = 119;
const int I32_ROTR = 120;
const int I64_CLZ = 121;
const int I64_CTZ = 122;
const int I64_POPCNT = 123;
const int I64_ADD = 124;
const int I64_SUB = 125;
const int I64_MUL = 126;
const int I64_DIV_S = 127;
const int I64_DIV_U = 128;
const int I64_REM_S = 129;
const int I64_REM_U = 130;
const int I64_AND = 131;
const int I64_OR = 132;
const int I64_XOR = 133;
const int I64_SHL = 134;
const int I64_SHR_S = 135;
const int I64_SHR_U = 136;
const int I64_ROTL = 137;
const int I64_ROTR = 138;
const int F32_ABS = 139;
const int F32_NEG = 140;
const int F32_CEIL = 141;
const int F32_FLOOR = 142;
const int F32_TRUNC = 143;
const int F32_NEAREST = 144;
const int F32_SQRT = 145;
const int F32_ADD = 146;
const int F32_SUB = 147;
const int F32_MUL = 148;
const int F32_DIV = 149;
const int F32_MIN = 150;
const int F32_MAX = 151;
const int F32_COPYSIGN = 152;
const int F64_ABS = 153;
const int F64_NEG = 154;
const int F64_CEIL = 155;
const int F64_FLOOR = 156;
const int F64_TRUNC = 157;
const int F64_NEAREST = 158;
const int F64_SQRT = 159;
const int F64_ADD = 160;
const int F64_SUB = 161;
const int F64_MUL = 162;
const int F64_DIV = 163;
const int F64_MIN = 164;
const int F64_MAX = 165;
const int F64_COPYSIGN = 166;
const int I32_WRAP_F64 = 167;
const int I32_TRUNC_S_F32 = 168;
const int I32_TRUNC_U_F32 = 169;
const int I32_TRUNC_S_F64 = 170;
const int I32_TRUNC_U_F64 = 171;
const int I64_EXTEND_S_I32 = 172;
const int I64_EXTEND_U_I32 = 173;
const int I64_TRUNC_S_F32 = 174;
const int I64_TRUNC_U_F32 = 175;
const int I64_TRUNC_S_F64 = 176;
const int I64_TRUNC_U_F64 = 177;
const int F32_CONVERT_S_I32 = 178;
const int F32_CONVERT_U_I32 = 179;
const int F32_CONVERT_S_I64 = 180;
const int F32_CONVERT_U_I64 = 181;
const int F32_DEMOTE_F64 = 182;
const int F64_CONVERT_S_I32 = 183;
const int F64_CONVERT_U_I32 = 184;
const int F64_CONVERT_S_I64 = 185;
const int F64_CONVERT_U_I64 = 186;
const int F64_PROMOTE_F32 = 187;
const int I32_REINTERPRET_F32 = 188;
const int I64_REINTERPRET_F64 = 189;
const int F32_REINTERPRET_I32 = 190;
const int F64_REINTERPRET_I64 = 191;
const int DESC_FUNCTION = 0;
const int DESC_TABLE = 1;
const int DESC_MEMORY = 2;
const int DESC_GLOBAL = 3;
const int LIMIT_MIN = 0;
const int LIMIT_MIN_MAX = 1;
const int IMMUTABLE = 0;
const int MUTABLE = 1;
const int EMPTY_VEC = 0;

/* Utils */

struct WasmNode {
  int data;
  struct WasmNode *next;
};

struct WasmNode *WasmNode_new() {
  return (struct WasmNode *)malloc(sizeof(struct WasmNode));
}

size_t WasmNode_length(struct WasmNode *n) {
  size_t i;

  i = 0;
  while (n != NULL) {
    i += 1;
    n = n->next;
  }
  return i;
}

struct WasmNode *w(int w, struct WasmNode *next) {
  struct WasmNode *n;

  n = WasmNode_new();
  n->data = w;
  n->next = next;
  return n;
}

struct WasmNode *magic_number() {
  return w(0, w(97, w(115, w(109, NULL))));
}

struct WasmNode *version_1() {
  return w(1, w(0, w(0, w(0, NULL))));
}

struct WasmApp {
  void *types;
};

struct WasmApp *WasmApp_new() {
  return (struct WasmApp *)malloc(sizeof(struct WasmApp));
}

char *WasmApp_write(struct WasmApp *self, char *file_name) {
  struct WasmNode *wasm;
  size_t i;
  struct WasmNode *n;
  int result;
  int len;
  char *bytes;

  /* build binary */
  wasm = magic_number();

  /* Write out wasm to bytes */
  len = WasmNode_length(wasm);
  bytes = (char *)malloc(len);
  i = 0;
  n = wasm;
  while (n != NULL) {
    bytes[i] = n->data;
    n = n->next;
    i += 1;
  }
  result = write_file("test.wasm", bytes, len);
  if (result == 0) {
    console_log("could not write wasm file");
  }
}

struct WasmApp *compile(char *input) {
  struct WasmApp *app = WasmApp_new();
  char *c;

  c = read_file(input);
  if (c == NULL) {
    console_log("could not open file");
  }
  return app;
}

int main(int argc, char *argv[]) {
  char *output;
  char *input;
  struct WasmApp *app;

  if (argc != 4) {
    console_log("need file: ccw -o <file.wasm> <file.c>");
    return 1;
  }
  output = argv[2];
  input = argv[3];
  app = compile(input);
  WasmApp_write(app, output);
  return (0);
}
