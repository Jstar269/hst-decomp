/* HSTMATCH module=EBOOT.BIN start=0x00050a10 end=0x00050a80 symbol=FUN_00050a10 lang=c99 */
/* Clone of src/sharing_main/clear_status_00051324.c (hstclone.py tag u5fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0) corrected by hand: typed struct member offsets and assert argument propagation; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d0d40;
extern u8 DAT_002d0a6c;
extern u8 DAT_00311170;
extern int FUN_0003420c(void);
extern int FUN_0003ca88(int, int);
extern void FUN_0004f010(void *, int, void *, int, void *);

typedef struct {
  char pad[0x1a00c];
  int f1a00c;
  int f1a010;
} BigObj;

void FUN_00050a10(BigObj *param_1)
{
  int r;

  r = FUN_0003ca88(param_1->f1a00c, FUN_0003420c());
  if (r != 0) {
    FUN_0004f010(&DAT_00311170, r, &DAT_002d0a6c, 2021, &DAT_002d0d40);
  }
  param_1->f1a010 = 0;
}
