#include <stdio.h>
#include "unity.h"
#include "VarArgAdd.h"

void setUp(void) {}

void tearDown(void) {}

void test_add_1_2_3_4_5(void) {
  int result = add(5, 1,9,3,10,5);
  
  TEST_ASSERT_EQUAL(28, result);
}