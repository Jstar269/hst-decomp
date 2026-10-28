/* HSTMATCH module=hstp_trans_main.prx start=0x001b6618 end=0x001b66c4 symbol=FUN_001b6618 lang=c99 */
/* Clone of src/eboot/obj_ctor_floats_001a904c.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the four copied globals and the destination fields are float (lwc1/swc1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern float DAT_002d3480;
extern float DAT_002d3484;
extern float DAT_002d3488;
extern float DAT_002d348c;
extern u8 DAT_003b2574;
extern u8 * DAT_003da704;
extern int FUN_0005c2f8();
extern int FUN_0005c688();
extern int FUN_0005c700();
extern void FUN_0005c8e0();

typedef struct O { unsigned int vt; int pad[3]; float a, b, c, d; } O;

O * FUN_001b6618(O *param_1)
{
  int iVar1;
  u8 auStack_2c0 [704];
  
  param_1->vt = (unsigned int)(&DAT_003b2574);
  param_1->a = DAT_002d3480;
  param_1->b = DAT_002d3484;
  param_1->c = DAT_002d3488;
  param_1->d = DAT_002d348c;
  FUN_0005c2f8(auStack_2c0);
  FUN_0005c700(DAT_003da704,auStack_2c0);
  iVar1 = (int)(DAT_003da704);
  *(u32 *)(DAT_003da704 + 0x1e0) = 0;
  *(u32 *)(iVar1 + 0x1e4) = 0;
  *(u32 *)(iVar1 + 0x1e8) = 0xbf800000;
  *(u32 *)(iVar1 + 0x1ec) = 0;
  FUN_0005c8e0(DAT_003da704);
  FUN_0005c688(auStack_2c0,0xffffffff);
  return param_1;
}
