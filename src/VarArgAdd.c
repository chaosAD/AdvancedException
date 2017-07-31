#include <stdio.h>
#include <stdarg.h>
#include "VarArgAdd.h"

int add(int numOfItems, ...) {
  va_list args;
  int sum = 0, val;
  va_start(args, numOfItems);
  
  while(numOfItems--) {
    val = va_arg(args, int);
    printf("val: %d\n", val);
    sum += val;
  }  
  return sum;
}