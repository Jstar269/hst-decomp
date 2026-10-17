/* HSTMATCH module=EBOOT.BIN start=0x001b8224 end=0x001b8260 symbol=FUN_001b8224 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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

extern undefined DAT_0034179c;
extern int FUN_001b1c44();

void FUN_001b8224(char *param_1)
{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x8c)) &&
     (iVar1 = *(int *)(param_1 + 0x8c) + -1, *(int *)(param_1 + 0x8c) = iVar1, iVar1 < 1)) {
    FUN_001b1c44((int *)&DAT_0034179c,0x45);
  }
  return;
}
