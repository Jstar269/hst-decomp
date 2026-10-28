/* HSTMATCH module=EBOOT.BIN start=0x00152bec end=0x00152c60 symbol=FUN_00152bec lang=c99 helpers=FUN_0014c610@0x0014c610-0x0014c63c,FUN_0014d044@0x0014d044-0x0014d0a8,FUN_0014fd94@0x0014fd94-0x0014fdc0 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/get_mode_00152bec.c, completed with its same-file static helpers FUN_0014c610, FUN_0014d044, FUN_0014fd94 defined in front of it and placed at their own retail addresses by helpers=); matching idiom: the parameter pointer is reassigned (`param_2 = *param_2`) so it shares s0 with the loaded value; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003402f0;
extern char DAT_002dc6c8[];
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern unsigned int *FUN_0014c384(void *, int);
static void FUN_0014c610(...)
{
}
static void FUN_0014d044(u32 *param_1)
{
  int i;
  if (DAT_003402f0 != 0) {
    FUN_0014c610(DAT_002dc240);
    for (i = 0; i < (int)param_1[6] + 1; i++) {
      FUN_0014c610(DAT_002dc24c);
    }
  }
}
static void FUN_0014fd94(...)
{
}
extern int FUN_00288b68(void *);

u32 FUN_00152bec(char *param_1, void **param_2)
{
  u32 v;
  u32 *p;
  void *obj;
  if (DAT_003402f0 != 0) {
    FUN_0014d044((u32 *)param_2);
    FUN_0014fd94(DAT_002dc6c8, *(int *)(param_1 + 8));
  }
  obj = param_2[3];
  param_2 = (void **)*param_2;
  v = FUN_00288b68(obj) & 0xff;
  p = FUN_0014c384(param_2, *(int *)(param_1 + 8));
  *p = v;
  return 0;
}
