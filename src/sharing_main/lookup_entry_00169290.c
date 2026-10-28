/* HSTMATCH module=hstp_trans_main.prx start=0x00169290 end=0x0016947c symbol=FUN_00169290 lang=c99 rodata=0x002d2164 */
/* Ghidra pseudocode (hstgen.py tag v0r) corrected by hand: used address-named 0x28-byte tables and kept the common zero result for out-of-range selectors; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef struct { u8 bytes[0x28]; } Entry28;

extern Entry28 DAT_0038418c[];
extern Entry28 DAT_00384a74[];
extern Entry28 DAT_00384dbc[];
extern Entry28 DAT_0038512c[];
extern Entry28 DAT_00385384[];
extern Entry28 DAT_003854c4[];
extern Entry28 DAT_003854ec[];
extern Entry28 DAT_003849fc[];
extern Entry28 DAT_00384f74[];

extern void FUN_0016916c();

int FUN_00169290(u32 param_1,u32 param_2)
{
  int iVar1;
  u32 local_4;
  u32 local_8;
  
  local_4 = 0;
  local_8 = 0;
  iVar1 = 0;
  FUN_0016916c(param_2,&local_4,&local_8);
  switch(local_4) {
  case 0:
    if (local_8 < 0x36) {
      iVar1 = (int)&DAT_0038418c[local_8];
    }
    break;
  case 1:
    if (local_8 < 0x15) {
      iVar1 = (int)&DAT_00384a74[local_8];
    }
    break;
  case 2:
    if (local_8 < 0xb) {
      iVar1 = (int)&DAT_00384dbc[local_8];
    }
    break;
  case 3:
    if (local_8 < 0xf) {
      iVar1 = (int)&DAT_0038512c[local_8];
    }
    break;
  case 4:
    if (local_8 < 8) {
      iVar1 = (int)&DAT_00385384[local_8];
    }
    break;
  case 5:
    if (local_8 == 0) {
      iVar1 = (int)&DAT_003854c4[local_8];
    }
    break;
  case 6:
    if (local_8 < 5) {
      iVar1 = (int)&DAT_003854ec[local_8];
    }
    break;
  case 7:
  case 8:
  case 9:
    break;
  case 10:
    if (local_8 < 3) {
      iVar1 = (int)&DAT_003849fc[local_8];
    }
    break;
  case 0xb:
    if (local_8 < 0xb) {
      iVar1 = (int)&DAT_00384f74[local_8];
    }
    break;
  default:
    break;
  }
  return iVar1;
}
