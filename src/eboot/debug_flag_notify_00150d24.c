/* HSTMATCH module=EBOOT.BIN start=0x00150d24 end=0x00150d6c symbol=FUN_00150d24 lang=c99 data=0x002dc46c */
/* Clone of src/eboot/debug_flag_notify_00150cdc.c (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc46c-0x002dc47a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu), not undefined4; exact match verified; names and types await human review. */
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

extern unsigned char DAT_003402f0;
extern undefined4 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd3d8();

undefined4 FUN_00150d24(undefined4 param_1,undefined4 param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("DisableInput\n");
  }
  FUN_001cd3d8(DAT_0034a114);
  return 0;
}
