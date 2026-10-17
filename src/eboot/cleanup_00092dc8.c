/* HSTMATCH module=EBOOT.BIN start=0x00092dc8 end=0x00092e1c symbol=FUN_00092dc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: test the first field directly before loading the second; exact match verified; names and types await human review. */
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

extern int FUN_00055e48();
extern void FUN_0005734c();

void FUN_00092dc8(int param_1)
{
  int iVar1;

  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_0005734c(*(int *)(param_1 + 0x58));
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 != 0) {
    FUN_00055e48(iVar1,1);
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  *(undefined4 *)(param_1 + 0x68) = 0xffffffff;
  return;
}
