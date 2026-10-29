/* HSTMATCH module=EBOOT.BIN start=0x00187308 end=0x00187424 symbol=FUN_00187308 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512b) corrected by hand: the object parameter typed char * (pointer arithmetic, as struct member addresses compile); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002e09c8;
extern char DAT_002e092c[];
extern char DAT_002e093c[];
extern char DAT_002e094c[];
extern char DAT_002e099c[];
extern char DAT_002e09cc[];
extern char DAT_002e09f8[];
extern void FUN_000143b0();
extern u32 FUN_000ff7d8();
extern void FUN_000ff98c();

/* Three sub-objects of self (offsets 0x2928, 0x28b0, 0x29a0): each is filled from a pair of strings, then handed on. */
void FUN_00187308(char *self)
{
  int ok;
  u8 buf256[256];
  u8 buf128[128];
  
  FUN_000143b0(buf256,DAT_002e099c,0);
  FUN_000143b0(buf128,DAT_002e092c,0);
  ok = FUN_000ff7d8(self + 0x2928,buf256,1,&DAT_002e09c8);
  if (ok != 0) {
    FUN_000ff98c(buf128,self + 0x2928);
  }
  FUN_000143b0(buf256,DAT_002e09cc,0);
  FUN_000143b0(buf128,DAT_002e093c,0);
  ok = FUN_000ff7d8(self + 0x28b0,buf256,1,&DAT_002e09c8);
  if (ok != 0) {
    FUN_000ff98c(buf128,self + 0x28b0);
  }
  FUN_000143b0(buf256,DAT_002e09f8,0);
  FUN_000143b0(buf128,DAT_002e094c,0);
  ok = FUN_000ff7d8(self + 0x29a0,buf256,1,&DAT_002e09c8);
  if (ok != 0) {
    FUN_000ff98c(buf128,self + 0x29a0);
  }
}
