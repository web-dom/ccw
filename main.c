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

void assert(int cond, char *msg) {
  if (cond == 0) {
    console_log(msg);
    exit(0);
  }
}

/* Constants */
const int SUCCESS = 1;
const int FAIL = 0;

const int TRUE = 1;
const int FALSE = 0;

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

const int TOKEN_TYPE_TEXT = 0;
const int TOKEN_TYPE_SYMBOL = 1;
const int TOKEN_TYPE_NUMBER = 2;

/* Utils */
struct WasmNode {
  void *data;
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

/* Utility functions for creating the bytes of web assembly */

struct WasmNode *w(int w, struct WasmNode *next) {
  struct WasmNode *n;

  n = WasmNode_new();
  n->data = (void *)(long)w;
  n->next = next;
  return n;
}

void wjoin(struct WasmNode *self, struct WasmNode *other) {
  struct WasmNode *wasm;
  struct WasmNode *n;

  n = self;
  while (n->next != NULL) {
    n = n->next;
  }
  n->next = other;
}

struct WasmNode *wbytevec(struct WasmNode *data) {
  if (data == NULL) {
    return w(0, NULL);
  }
  return w((int)WasmNode_length(data), data);
}

struct WasmNode *wstring(char *s, struct WasmNode *next) {
  struct WasmNode *head;
  struct WasmNode *node;
  struct WasmNode *tmp;
  char n;
  node = NULL;
  n = 0;
  while (s[n] != 0) {
    tmp = w(s[n], NULL);
    /* first time lets save head */
    if (node == NULL) {
      node = tmp;
      head = node;
      n += 1;
      continue;
    }
    node->next = tmp;
    node = tmp;
    n += 1;
  }
  if (node == NULL) {
    return w(0, NULL);
  }
  head = wbytevec(head);
  node->next = next;
  return head;
}

struct WasmNode *wsection(int section, struct WasmNode *data) {
  return w(section, wbytevec(data));
}

struct WasmNode *magic_number() {
  return w(0, w(97, w(115, w(109, NULL))));
}

struct WasmNode *version_1() {
  return w(1, w(0, w(0, w(0, NULL))));
}

/* WasmApp - A structure representing a web assembly module */

struct WasmApp {
  void *types;
};

struct WasmApp *WasmApp_new() {
  return (struct WasmApp *)malloc(sizeof(struct WasmApp));
}

int WasmApp_write(struct WasmApp *self, char *file_name) {
  struct WasmNode *wasm;
  size_t i;
  struct WasmNode *n;
  int result;
  int len;
  char *bytes;
  struct WasmNode *main_signature;

  /* build binary */
  wasm = magic_number();
  wjoin(wasm, version_1());
  wjoin(wasm, wsection(SECTION_TYPE, w(1, w(FUNC, w(0, w(1, w(I32, NULL)))))));
  wjoin(wasm, wsection(SECTION_FUNCTION, w(1, w(0, NULL))));
  wjoin(wasm, wsection(SECTION_EXPORT,
                       w(1, wstring("main", w(DESC_FUNCTION, w(0, NULL))))));
  wjoin(wasm,
        wsection(SECTION_CODE,
                 w(1, wbytevec(w(0, w(I32_CONST, w(42, w(END, NULL))))))));

  /* Write out wasm to bytes */
  len = WasmNode_length(wasm);
  bytes = (char *)malloc(len);
  i = 0;
  n = wasm;
  while (n != NULL) {
    bytes[i] = (int)(long)n->data;
    n = n->next;
    i += 1;
  }
  result = write_file("test.wasm", bytes, len);
  if (result == 0) {
    console_log("could not write wasm file");
  }
  return SUCCESS;
}

struct TokenText {
  char *text;
};

struct TokenText *TokenText_new(char *text) {
  struct TokenText *t = (struct TokenText *)malloc(sizeof(struct TokenText));
  t->text = text;
  return t;
}

struct Token {
  int token_type;
  void *data;
  struct Token *next;
};

struct Token *Token_new(int token_type, void *data, struct Token *next) {
  struct Token *t = (struct Token *)malloc(sizeof(struct Token));
  t->token_type = token_type;
  t->data = data;
  t->next = next;
  return t;
}

Token_print(struct Token *self) {
  if (self == NULL) {
    return;
  }
  if (self->token_type == TOKEN_TYPE_TEXT) {
    struct TokenText *t = (struct TokenText *)self->data;
    console_log(t->text);
    console_log(", ");
    Token_print(self->next);
  }
}

struct Token *tokenize(char *bytes) {
  return Token_new(TOKEN_TYPE_TEXT, TokenText_new("hello"),
                   Token_new(TOKEN_TYPE_TEXT, TokenText_new("goodbye"), NULL));
}

struct WasmApp *compile(char *input) {
  struct WasmApp *app;
  char *input_bytes;
  struct Token *tokens;

  app = WasmApp_new();

  input_bytes = read_file(input);
  if (input_bytes == NULL) {
    console_log("could not open file");
    return NULL;
  }

  tokens = tokenize(input_bytes);
  if (tokens == NULL) {
    console_log("file is empty");
    return NULL;
  }
  Token_print(tokens);
  return app;
}

void WasmNode_print(struct WasmNode *self) {
  if (self == NULL) {
    return;
  }
  printf("%d", self->data);
  console_log(", ");
  WasmNode_print(self->next);
}

int WasmNode_equal(struct WasmNode *a, struct WasmNode *b) {
  struct WasmNode *x;
  struct WasmNode *n;
  if (a == NULL && b == NULL) {
    return TRUE;
  } else if (a != NULL && b != NULL) {
    if (WasmNode_length(a) != WasmNode_length(b)) {
      return FALSE;
    }
    x = a;
    n = b;
    while (x != NULL) {
      if (x->data != n->data) {
        return FALSE;
      }
      x = x->next;
      n = n->next;
    }
    return TRUE;
  }
  return FALSE;
}

void unit_tests() {
  struct WasmNode *x;
  struct WasmNode *n;
  assert(FALSE == WasmNode_equal(NULL, w(1, NULL)),
         "null should not equal a list");
  assert(TRUE == WasmNode_equal(NULL, NULL), "null should equal true");
  assert(TRUE == WasmNode_equal(w(1, NULL), w(1, NULL)),
         "similar one element lists should equal");
  assert(FALSE == WasmNode_equal(w(2, NULL), w(1, NULL)),
         "dissimilar one element lists should not equal");
  assert(FALSE == WasmNode_equal(w(1, w(2, NULL)), w(1, NULL)),
         "dissimilar length lists should not equal");
  assert(FALSE == WasmNode_equal(w(1, w(2, NULL)), w(1, w(3, NULL))),
         "dissimilar multi element lists should not equal");
  assert(TRUE == WasmNode_equal(w(1, w(3, NULL)), w(1, w(3, NULL))),
         "similar multi element lists should equal");
  assert(TRUE == WasmNode_equal(w(0, NULL), wstring("", NULL)),
         "empty string should be null");
  assert(TRUE == WasmNode_equal(w(1, w(97, NULL)), wstring("a", NULL)),
         "'a' should be a list");
  assert(TRUE == WasmNode_equal(w(2, w(97, w(97, NULL))), wstring("aa", NULL)),
         "'aa' should be a list");
  assert(TRUE == WasmNode_equal(w(2, w(97, w(97, w(1, NULL)))),
                                wstring("aa", w(1, NULL))),
         "'aa' should be a list extended by 1");
}

int main(int argc, char *argv[]) {
  char *output;
  char *input;
  struct WasmApp *app;
  int result;

  unit_tests();
  /* get args */
  if (argc != 4) {
    console_log("need file: ccw -o <file.wasm> <file.c>");
    return 1;
  }
  output = argv[2];
  input = argv[3];

  /* compile and write to file */
  app = compile(input);
  if (app == NULL) {
    return 1;
  }
  result = WasmApp_write(app, output);
  if (result = FAIL) {
    return 1;
  }

  return (0);
}
