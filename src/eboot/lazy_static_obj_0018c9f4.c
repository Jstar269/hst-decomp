/* HSTMATCH module=EBOOT.BIN start=0x0018c9f4 end=0x0018ca94 symbol=FUN_0018c9f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the function-local static guard DAT_003415b4 is a signed char and DAT_003415c4 a struct {char; int} (sb/sw), the registration record is passed as a symbol address; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc560;
extern u8 * DAT_003415b0;
extern char DAT_003415b4;
extern char DAT_003415b8[];
typedef struct T { char c; int i; } T;
extern T DAT_003415c4;
extern u32 FUN_00000f74();
extern u32 FUN_0010ad1c();
extern void FUN_000fcb7c();

u8 * FUN_0018c9f4(int param_1)
{
  u8 *puVar1;
  
  if ((DAT_003415b0 == 0) && (param_1 == 0x10)) {
    if (DAT_003415b4 == 0) {
      DAT_003415c4.c = 0;
      DAT_003415c4.i = 0;
      FUN_00000f74(&DAT_003415c4,FUN_000fcb7c,DAT_003415b8);
      DAT_003415b4 = 1;
    }
    FUN_0010ad1c(&DAT_003415c4,&DAT_002cc560);
    puVar1 = (unsigned char *)(&DAT_003415c4);
  }
  else {
    puVar1 = (u8 *)(DAT_003415b0 + param_1 * 0x10);
  }
  return puVar1;
}
