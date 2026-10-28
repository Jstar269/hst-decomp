/* HSTMATCH module=EBOOT.BIN start=0x00130174 end=0x00130274 symbol=FUN_00130174 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
extern char DAT_002db094[]; extern char DAT_002db0a4[]; extern char DAT_002db0b0[]; extern char DAT_002db0bc; extern char DAT_002db0c4[]; extern char DAT_002db0d4[]; extern char DAT_002db0dc[];
extern int FUN_00014d64(const char *, const char *);
int FUN_00130174(u32 unused, const char *name) {
  int result = 0;
  if (name == 0) {
    result = 0;
  } else {
    if (FUN_00014d64(name,DAT_002db094) != 0) result = 1;
    else if (FUN_00014d64(name,DAT_002db0a4) != 0) result = 2;
    else if (FUN_00014d64(name,DAT_002db0b0) != 0) result = 3;
    else if (FUN_00014d64(name,&DAT_002db0bc) != 0) result = 5;
    else if (FUN_00014d64(name,DAT_002db0c4) != 0) result = 4;
    else if (FUN_00014d64(name,DAT_002db0d4) != 0) result = 6;
    else if (FUN_00014d64(name,DAT_002db0dc) != 0) result = 7;
  }
  return result;
}
