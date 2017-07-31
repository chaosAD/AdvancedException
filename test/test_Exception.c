#include <stdint.h>
#include "unity.h"
#include "Token.h"
#include "Error.h"
#include "Exception.h"
#include "CException.h"

void setUp(void) {}

void tearDown(void) {}

void test_throwException(void) {
  CEXCEPTION_T ex = NULL;
  Token token = {
    .type = TOKEN_OPERATOR_TYPE,
    .str = "##",
  };
  
  Try {
    throwException(ERR_INVALID_OPERAND,                                     \
                   "Invalid operand, expecting a ',', but received '%s'\n", \
                    token.str);
  } Catch(ex) {
    dumpException(ex);
  }
  freeException(ex);
}

