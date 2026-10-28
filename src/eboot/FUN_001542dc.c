/* HSTMATCH module=EBOOT.BIN start=0x001542dc end=0x0015435c symbol=FUN_001542dc lang=c99 data=0x002dc8a0 */
/* Ghidra pseudocode (hstgen.py tag a1v0) corrected by hand: DAT_003402f0 is unsigned char (lbu), the *param_2 load is hoisted into a local before the value test, and the value is selected with if (x != 0) val else 0 so the branch stays non-likely; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc8a0-0x002dc8b2) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

typedef struct { int pad0; int pad4; int f8; int fc; } S154;
extern unsigned char DAT_003402f0;
extern u8 * DAT_0034a118;
extern int FUN_0014c384(int a,int b);
extern void FUN_0014d044(void *p);
extern void FUN_0014fd94(const char *fmt,int b);

u32 FUN_001542dc(S154 *s,int *p)
{
  u32 *puVar1;
  u32 uVar2;

  if (DAT_003402f0 != '\0') {
    FUN_0014d044(p);
    FUN_0014fd94("GetPcNumber [%d]\n",s->f8);
  }
  int a = *p;
  if (*(int *)(DAT_0034a118 + 0x50) != 0) {
    uVar2 = *(u32 *)(*(int *)(DAT_0034a118 + 0x50) + 0x1b4);
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (u32 *)FUN_0014c384(a,s->f8);
  *puVar1 = uVar2;
  return 0;
}
