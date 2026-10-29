/* HSTMATCH module=EBOOT.BIN start=0x0018c9f4 end=0x0018ca94 symbol=FUN_0018c9f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the function-local static guard DAT_003415b4 is a signed char and DAT_003415c4 a struct {char; int} (sb/sw), the registration record is passed as a symbol address; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/text_bank_lookup.h"

#define LAZY_BANK_ID 0x10 /* bank served from a lazily built object while the table is not loaded */

extern u8 DAT_002cc560;
extern TextBank * DAT_003415b0;
extern char DAT_003415b4;
extern char DAT_003415b8[];
typedef struct T { char c; int i; } T;
extern T DAT_003415c4;
extern u32 FUN_00000f74();
extern u32 FUN_0010ad1c();
extern void FUN_000fcb7c();

/* Returns the text bank with the given id. */
TextBank * FUN_0018c9f4(int bank_id)
{
  TextBank *bank;
  
  if ((DAT_003415b0 == 0) && (bank_id == LAZY_BANK_ID)) {
    if (DAT_003415b4 == 0) {
      DAT_003415c4.c = 0;
      DAT_003415c4.i = 0;
      FUN_00000f74(&DAT_003415c4,FUN_000fcb7c,DAT_003415b8);
      DAT_003415b4 = 1;
    }
    FUN_0010ad1c(&DAT_003415c4,&DAT_002cc560);
    bank = (TextBank *)(&DAT_003415c4);
  }
  else {
    bank = (TextBank *)(DAT_003415b0 + bank_id);
  }
  return bank;
}
