/* HSTMATCH module=hstp_trans_main.prx start=0x00193a54 end=0x00193b70 symbol=FUN_00193a54 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512b) corrected by hand: the object parameter typed char * (pointer arithmetic, as struct member addresses compile); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00388048;
extern char DAT_00387f64[];
extern char DAT_00387f74[];
extern char DAT_00387f84[];
extern char DAT_0038801c[];
extern char DAT_0038804c[];
extern char DAT_00388078[];
extern void FUN_000143b0();
extern u32 FUN_00105070();
extern void FUN_00105224();

/* Three sub-objects of self (offsets 0x2928, 0x28b0, 0x29a0): each is filled from a pair of strings, then handed on. */
void FUN_00193a54(char *self)
{
  int ok;
  u8 buf256[256];
  u8 buf128[128];
  
  FUN_000143b0(buf256,DAT_0038801c,0);
  FUN_000143b0(buf128,DAT_00387f64,0);
  ok = FUN_00105070(self + 0x2928,buf256,1,&DAT_00388048);
  if (ok != 0) {
    FUN_00105224(buf128,self + 0x2928);
  }
  FUN_000143b0(buf256,DAT_0038804c,0);
  FUN_000143b0(buf128,DAT_00387f74,0);
  ok = FUN_00105070(self + 0x28b0,buf256,1,&DAT_00388048);
  if (ok != 0) {
    FUN_00105224(buf128,self + 0x28b0);
  }
  FUN_000143b0(buf256,DAT_00388078,0);
  FUN_000143b0(buf128,DAT_00387f84,0);
  ok = FUN_00105070(self + 0x29a0,buf256,1,&DAT_00388048);
  if (ok != 0) {
    FUN_00105224(buf128,self + 0x29a0);
  }
}
