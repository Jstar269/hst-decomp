/* HSTMATCH module=hstp_trans_main.prx start=0x0018ac8c end=0x0018ad48 symbol=FUN_0018ac8c lang=c99 */
/* Clone of src/eboot/obj_ctor_two_subobjs_0017e598.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: typed struct with float globals/fields (lwc1/swc1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern float DAT_002d2570;
extern float DAT_002d2574;
extern float DAT_002d2578;
extern float DAT_002d257c;
extern u8 DAT_003b23a0;
extern u8 * DAT_003da704;
extern int FUN_0005c2f8();
extern int FUN_0005c688();
extern int FUN_0005c700();

typedef struct O {
  unsigned int vt; int pad[3];
  char o1[0x2c0];
  float f2d0; unsigned char c2d4; char pad2[11];
  char o2[0x2c0];
  float a, b, c, d;
} O;

O * FUN_0018ac8c(O *param_1)
{
  int iVar1;
  u8 auStack_2c0 [704];
  
  param_1->vt = (unsigned int)(&DAT_003b23a0);
  FUN_0005c2f8(param_1->o1);
  FUN_0005c2f8(param_1->o2);
  param_1->a = DAT_002d2570;
  param_1->b = DAT_002d2574;
  param_1->c = DAT_002d2578;
  param_1->d = DAT_002d257c;
  FUN_0005c2f8(auStack_2c0);
  FUN_0005c700(DAT_003da704,auStack_2c0);
  iVar1 = (int)(DAT_003da704);
  *(u32 *)(DAT_003da704 + 0x1e0) = 0;
  *(u32 *)(iVar1 + 0x1e4) = 0;
  *(u32 *)(iVar1 + 0x1e8) = 0xbf800000;
  *(u32 *)(iVar1 + 0x1ec) = 0;
  param_1->f2d0 = 1.0f;
  param_1->c2d4 = 0;
  FUN_0005c688(auStack_2c0,0xffffffff);
  return param_1;
}
