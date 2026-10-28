/* HSTMATCH module=hstp_trans_main.prx start=0x0015ed74 end=0x0015ede8 symbol=FUN_0015ed74 lang=c99 helpers=FUN_00157280@0x00157280-0x001572ac,FUN_00158b2c@0x00158b2c-0x00158b90,FUN_0015bb68@0x0015bb68-0x0015bb94 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/get_mode_00152bec.c: addresses substituted by hand; its same-file static helpers FUN_00157280, FUN_00158b2c, FUN_0015bb68 are defined in front of it and placed at their own retail addresses by helpers=); matching idiom: the parameter pointer is reassigned (`param_2 = *param_2`) so it shares s0 with the loaded value; exact match verified; names and types await human review. */
#include "hst/types.h"

extern unsigned char DAT_003e9630;
extern char DAT_00383bb0[];
extern char DAT_003836b8[];
extern char DAT_003836c4[];
extern unsigned int *FUN_00157e10(void *, int);
static void FUN_00157280(...)
{
}
static void FUN_00158b2c(u32 *param_1)
{
  int i;
  if (DAT_003e9630 != 0) {
    FUN_00157280(DAT_003836b8);
    for (i = 0; i < (int)param_1[6] + 1; i++) {
      FUN_00157280(DAT_003836c4);
    }
  }
}
static void FUN_0015bb68(...)
{
}
extern int FUN_0029a304(void *);

u32 FUN_0015ed74(char *param_1, void **param_2)
{
  u32 v;
  u32 *p;
  void *obj;
  if (DAT_003e9630 != 0) {
    FUN_00158b2c((u32 *)param_2);
    FUN_0015bb68(DAT_00383bb0, *(int *)(param_1 + 8));
  }
  obj = param_2[3];
  param_2 = (void **)*param_2;
  v = FUN_0029a304(obj) & 0xff;
  p = FUN_00157e10(param_2, *(int *)(param_1 + 8));
  *p = v;
  return 0;
}
