/* HSTMATCH module=EBOOT.BIN start=0x0017e8bc end=0x0017e924 symbol=FUN_0017e8bc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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
typedef float undefined4;

extern int DAT_003313c4;
extern int FUN_0005ba78();
extern void FUN_0005bc58();
extern void FUN_0017e6c0();

void FUN_0017e8bc(int param_1)
{
  int iVar1;
  
  FUN_0017e6c0();
  iVar1 = DAT_003313c4;
  *(undefined4 *)(DAT_003313c4 + 0x1d0) = *(undefined4 *)(param_1 + 0x5a0);
  *(undefined4 *)(iVar1 + 0x1d4) = *(undefined4 *)(param_1 + 0x5a4);
  *(undefined4 *)(iVar1 + 0x1d8) = *(undefined4 *)(param_1 + 0x5a8);
  *(undefined4 *)(iVar1 + 0x1dc) = *(undefined4 *)(param_1 + 0x5ac);
  FUN_0005bc58(DAT_003313c4);
  FUN_0005ba78(param_1 + 0x10,DAT_003313c4);
  return;
}
