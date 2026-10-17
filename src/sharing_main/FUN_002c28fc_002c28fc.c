/* HSTMATCH module=hstp_trans_main.prx start=0x002c28fc end=0x002c2988 symbol=FUN_002c28fc lang=c99 */
/* Clone of src/eboot/FUN_002b2e3c_002b2e3c.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: typed the global and helper argument as float; exact match verified; names and types await human review. */
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

extern float DAT_003ac028;
extern char DAT_003ac2d8[];
extern void FUN_00108e6c(float, int);
extern void FUN_001090f4();
extern void FUN_00109a44();

void FUN_002c28fc(int param_1)
{
  int iVar1;
  
  FUN_00109a44(param_1 + 0x3c,DAT_003ac2d8,0);
  FUN_001090f4(param_1 + 0x3c,0xfffffffe);
  FUN_00108e6c(DAT_003ac028,param_1 + 0x3c);
  iVar1 = 0;
  do {
    *(undefined4 *)(param_1 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x138) = 0;
    *(undefined4 *)(param_1 + 0x114) = 0;
    *(undefined4 *)(param_1 + 0x13c) = 0;
    *(undefined4 *)(param_1 + 0x118) = 0;
    *(undefined4 *)(param_1 + 0x140) = 0;
    *(undefined4 *)(param_1 + 0x11c) = 0;
    *(undefined4 *)(param_1 + 0x144) = 0;
    *(undefined4 *)(param_1 + 0x120) = 0;
    iVar1 = iVar1 + 5;
    *(undefined4 *)(param_1 + 0x148) = 0;
    param_1 = param_1 + 0x14;
  } while (iVar1 < 10);
  return;
}
