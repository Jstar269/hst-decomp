/* HSTMATCH module=hstp_trans_main.prx start=0x0013f724 end=0x0013f85c symbol=FUN_0013f724 lang=c99 rodata=0x002d1a00 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0013f85c();
extern void FUN_0013fa60();
extern void FUN_0013fb94();
extern void FUN_00140468();
extern void FUN_00140e28();
extern void FUN_001416cc();
extern void FUN_00142074();
extern void FUN_001421a8();
extern void FUN_001422dc();
extern void FUN_001424e0();
extern void FUN_00142614();
extern void FUN_00142748();
extern void FUN_0014294c();
extern void FUN_00142954();
extern void FUN_00142a88();
extern void FUN_00142bbc();

void FUN_0013f724(int param_1)
{
  switch(*(u32 *)(param_1 + 0x1364)) {
  case 0:
  case 10:
  case 0xb:
  case 0xc:
  case 0x13:
    break;
  case 1:
    FUN_0013f85c(param_1);
    break;
  case 2:
    FUN_0013fa60(param_1);
    break;
  case 3:
    FUN_0013fb94(param_1);
    break;
  case 4:
    FUN_00140468(param_1);
    break;
  case 5:
    FUN_00140e28(param_1);
    break;
  case 6:
    FUN_001416cc(param_1);
    break;
  case 7:
    FUN_00142074(param_1);
    break;
  case 8:
    FUN_001421a8(param_1);
    break;
  case 9:
    FUN_001422dc(param_1);
    break;
  case 0xd:
    FUN_001424e0(param_1);
    break;
  case 0xe:
    FUN_00142614(param_1);
    break;
  case 0xf:
    FUN_00142748(param_1);
    break;
  case 0x10:
    FUN_0014294c();
    break;
  case 0x11:
    FUN_00142954(param_1);
    break;
  case 0x12:
    FUN_00142a88(param_1);
    break;
  case 0x14:
    FUN_00142bbc(param_1);
    break;
  default:
    goto switchD_0013f750_default;
  }
switchD_0013f750_default:
  return;
}
