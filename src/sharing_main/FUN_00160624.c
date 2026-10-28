/* HSTMATCH module=hstp_trans_main.prx start=0x00160624 end=0x001606a4 symbol=FUN_00160624 lang=c99 data=0x00383d88 */
/* Clone of src/eboot/FUN_001542dc.c (hstclone.py tag u3r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383d88-0x00383d9a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1v0) corrected by hand: DAT_003e9630 is unsigned char (lbu), the *param_2 load is hoisted into a local before the value test, and the value is selected with if (x != 0) val else 0 so the branch stays non-likely; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct { int pad0; int pad4; int f8; int fc; } S154;
extern unsigned char DAT_003e9630;
extern u8 * DAT_003f3450;
extern int FUN_00157e10(int a,int b);
extern void FUN_00158b2c(void *p);
extern void FUN_0015bb68(const char *fmt,int b);

u32 FUN_00160624(S154 *s,int *p)
{
  u32 *puVar1;
  u32 uVar2;

  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(p);
    FUN_0015bb68("GetPcNumber [%d]\n",s->f8);
  }
  int a = *p;
  if (*(int *)(DAT_003f3450 + 0x50) != 0) {
    uVar2 = *(u32 *)(*(int *)(DAT_003f3450 + 0x50) + 0x1b4);
  }
  else {
    uVar2 = 0;
  }
  puVar1 = (u32 *)FUN_00157e10(a,s->f8);
  *puVar1 = uVar2;
  return 0;
}
