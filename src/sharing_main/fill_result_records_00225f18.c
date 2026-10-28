/* HSTMATCH module=hstp_trans_main.prx start=0x00225f18 end=0x00225fb4 symbol=FUN_00225f18 lang=c99 */
/* Clone of src/eboot/fill_result_records_00216f14.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
extern int *FUN_00108124(int, u8 *);
void FUN_00225f18(int *out, int *table, u8 *indices, int count)
{
  int i = 0;
  u8 *input;
  int *cursor;
  if (count <= 0) return;
  input = indices;
  cursor = out;
  do {
    int *result = FUN_00108124(table[*input], input + 1);
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
