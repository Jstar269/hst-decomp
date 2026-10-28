/* HSTMATCH module=EBOOT.BIN start=0x00216f14 end=0x00216fb0 symbol=FUN_00216f14 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
extern int *FUN_001026b8(int, u8 *);
void FUN_00216f14(int *out, int *table, u8 *indices, int count)
{
  int i = 0;
  u8 *input;
  int *cursor;
  if (count <= 0) return;
  input = indices;
  cursor = out;
  do {
    int *result = FUN_001026b8(table[*input], input + 1);
    if (result != 0) {
      cursor[0] = (int)result;
      cursor[1] = result[9];
      cursor[4] = *result;
    }
    ++i;
    input += 0x21;
    cursor += 5;
  } while (i < count);
}
