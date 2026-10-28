/* HSTMATCH module=EBOOT.BIN start=0x00089648 end=0x00089724 symbol=FUN_00089648 lang=c99 rodata=0x2be858 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: enumerate the full dense case range (0..24) so MWCC emits the 25-entry jump table, and place .rodata (rodata=0x2be858) so the table address matches; write the case-4 test as nested positive conditions. */
#include "hst/types.h"

extern u8 DAT_003386b8;
extern u8 * DAT_00338ac4;
extern void FUN_00119fb4();
extern void FUN_001f8858();
extern void FUN_002b7960();

u32 FUN_00089648(int param_1,unsigned int param_2)
{
  switch(param_2) {
  case 4:
    if (DAT_003386b8 != 0) {
      if ((DAT_00338ac4 != 0) && (2 >= *(int *)(DAT_00338ac4 + 0x194))) {
        FUN_002b7960(0,0x28);
      }
      else {
        FUN_002b7960(0,0x26);
      }
    }
    break;
  case 8:
    *(u8 *)(param_1 + 0x59) = 0;
    break;
  case 13:
    *(u8 *)(param_1 + 0x59) = 0;
    if (DAT_003386b8 != 0) {
      *(u8 *)(param_1 + 0x68) = 0;
    }
    break;
  case 14:
    *(u8 *)(param_1 + 0x59) = 0;
    break;
  case 18:
    FUN_00119fb4(*(u32 *)(param_1 + 0x98));
    FUN_001f8858(*(u32 *)(param_1 + 0xa0));
    break;
  case 0: case 1: case 2: case 3:
  case 5: case 6: case 7:
  case 9: case 10: case 11: case 12:
  case 15: case 16: case 17:
  case 19: case 20: case 21: case 22: case 23: case 24:
    break;
  }
  return 0;
}
