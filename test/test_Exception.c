#include <stdint.h>
#include "unity.h"
#include "Token.h"
#include "Error.h"
#include "Exception.h"
#include "CException.h"

void setUp(void) {}

void tearDown(void) {}

void dumpErrorMessage(CEXCEPTION_T ex, int lineNo) {
  Token *token = (Token *)ex->data;
  int i = token->length - 1;
  if(i < 0) i = 0;

  printf("Error %d:\n", lineNo);
  printf("%s\n", ex->msg);
  printf("%s\n", token->originalStr);
  printf("%*s", token->startColumn + 1, "^");
  while(i--)
    printf("~");
  putchar('\n');
}

void test_throwException(void) {
  CEXCEPTION_T ex = NULL;
  char *str = "movwf  0x3 ###########";

  OperatorToken token = {
    .type = TOKEN_OPERATOR_TYPE,
    .startColumn = 11,
    .length = 11,
    .originalStr = str,
    .str = "###########",
  };

  Try {
    throwException(ERR_INVALID_OPERAND, (void *)&token,                     \
                   "Invalid operand, expecting a ',', but received '%s'\n", \
                    token.str);
  } Catch(ex) {
//    dumpException(ex);
    dumpErrorMessage(ex, 3);
  }
  freeException(ex);
}

