/* HSTMATCH module=EBOOT.BIN start=0x002111cc end=0x00211270 symbol=FUN_002111cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: compared the parameter from the variable side and retained the scaled random factor with a compound multiply; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

#define RAND_MASK 0xfffff800u   /* low bits of the random word dropped before the int-to-float conversion */
#define RAND_SCALE 4.656613e-10f /* about 1 / 2^31 */

extern u32 FUN_0001342c();

/* Random float: from [-b, a] when a > 0, else from [a, b]. */
float FUN_002111cc(float a,float b)
{
  u32 bits;
  float randValue;
  float scaled;
  float result;
  
  if (a > 0.0f) {
    bits = FUN_0001342c();
    randValue = (float)(int)(bits & RAND_MASK);
    scaled = (a + b) * RAND_SCALE;
    scaled *= randValue;
    result = -b + scaled;
  }
  else {
    bits = FUN_0001342c();
    randValue = (float)(int)(bits & RAND_MASK);
    scaled = (b - a) * RAND_SCALE;
    scaled *= randValue;
    result = a + scaled;
  }
  return result;
}
