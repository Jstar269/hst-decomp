/* HSTMATCH module=hstp_trans_main.prx start=0x00051324 end=0x00051394 symbol=FUN_00051324 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0) corrected by hand: typed struct member offsets and assert argument propagation; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003767fc;
extern u8 DAT_003763c8;
extern u8 DAT_003ba4b0;
extern int FUN_00034234(void);
extern int FUN_0003cab0(int, int);
extern void FUN_0004f864(void *, int, void *, int, void *);

typedef struct {
  char pad[0x1a00c];
  int f1a00c;
  int f1a010;
} BigObj;

void FUN_00051324(BigObj *param_1)
{
  int r;

  r = FUN_0003cab0(param_1->f1a00c, FUN_00034234());
  if (r != 0) {
    FUN_0004f864(&DAT_003ba4b0, r, &DAT_003763c8, 2021, &DAT_003767fc);
  }
  param_1->f1a010 = 0;
}
