/* HSTMATCH module=EBOOT.BIN start=0x00130274 end=0x00130304 symbol=FUN_00130274 lang=c99 */
/* Clone of src/sharing_main/probe_string_modes_0013b82c.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: tested each string match as the nonzero path with one shared result; exact match verified; names and types await human review. */
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

extern char DAT_002db0e4[];
extern char DAT_002db0ec[];
extern char DAT_002db0f8[];
extern char * FUN_00014d64();

undefined4 FUN_00130274(undefined4 param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2 = 0;
  if (param_2 == 0) {
    uVar2 = 0;
  } else {
    iVar1 = (int)FUN_00014d64(param_2,DAT_002db0e4);
    if (iVar1 != 0) {
      uVar2 = 0x32;
    } else {
      iVar1 = (int)FUN_00014d64(param_2,DAT_002db0ec);
      if (iVar1 != 0) {
        uVar2 = 0x3c;
      } else {
        iVar1 = (int)FUN_00014d64(param_2,DAT_002db0f8);
        if (iVar1 != 0) uVar2 = 999;
      }
    }
  }
  return uVar2;
}
