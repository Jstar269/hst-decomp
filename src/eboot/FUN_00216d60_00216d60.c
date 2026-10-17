/* HSTMATCH module=EBOOT.BIN start=0x00216d60 end=0x00216de0 symbol=FUN_00216d60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: placed the nonzero dispatch arm first to match the target branch layout; exact match verified; names and types await human review. */
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

extern undefined4 DAT_002c983c;
extern undefined4 DAT_002c9840;
extern undefined4 DAT_002c9844;
extern undefined4 DAT_002c9848;
extern void FUN_000513a0();

void FUN_00216d60(undefined1 *param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_000513a0(*(undefined4 *)(param_1 + 4),1);
    *(undefined4 *)(param_1 + 0x108) = DAT_002c9840;
    *(undefined4 *)(param_1 + 0x10c) = DAT_002c983c;
    *param_1 = 1;
  }
  else {
    FUN_000513a0(*(undefined4 *)(param_1 + 4),2);
    *(undefined4 *)(param_1 + 0x108) = DAT_002c9848;
    *(undefined4 *)(param_1 + 0x10c) = DAT_002c9844;
    *param_1 = 1;
  }
  return;
}

