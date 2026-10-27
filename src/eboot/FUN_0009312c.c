/* HSTMATCH module=EBOOT.BIN start=0x0009312c end=0x00093194 symbol=FUN_0009312c lang=c99 data=0x002d2a54 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d2a54-0x002d2a63) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern char * FUN_00014d64();

undefined4 FUN_0009312c(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = (int)(FUN_00014d64(param_1,"Bip01R"));
    if (iVar1 == param_1) {
      *(undefined1 *)(param_1 + 5) = 0x4c;
    }
    else {
      iVar1 = (int)(FUN_00014d64(param_1,"Bip01L"));
      if (iVar1 == param_1) {
        *(undefined1 *)(param_1 + 5) = 0x52;
      }
    }
  }
  return 0;
}
