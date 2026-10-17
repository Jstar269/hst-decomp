/* HSTMATCH module=hstp_trans_main.prx start=0x00169290 end=0x0016947c symbol=FUN_00169290 lang=c99 rodata=0x002d2164 */
/* Ghidra pseudocode (hstgen.py tag v0r) corrected by hand: used address-named 0x28-byte tables and kept the common zero result for out-of-range selectors; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef struct { undefined1 bytes[0x28]; } Entry28;

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

int FUN_00169290(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 local_4;
  uint local_8;
  
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
