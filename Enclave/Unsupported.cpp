#include "Unsupported.h"
char* strcpy(char* d, const char* s) {
  char* res;
  strcpy_OCALL(&res, d, s);
  return res;
}

char* strdup(const char* str) {
  char* res;
  strdup_OCALL(&res, str);
  return res;
}
