/* HSTMATCH module=EBOOT.BIN start=0x000def58 end=0x000defb4 symbol=FUN_000def58 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: shared bool result with an inner >= half branch; exact match verified; names and types await human review. */
extern unsigned char DAT_00338b48;
#include "hst/types.h"
bool FUN_000def58(int self) {
  bool result;
  if (DAT_00338b48 != 0) {
    result = *(int *)(self + 0xc8) > 0;
  } else {
  int half = (*(int *)(self + 0xb4) + 1) / 2;
  if (*(int *)(self + 0xb8) < half) {
      if (*(int *)(self + 0xbc) >= half) result = 1;
      else result = 0;
    } else {
      result = 1;
    }
  }
  return result;
}
