/* HSTMATCH module=EBOOT.BIN start=0x0013110c end=0x0013115c symbol=FUN_0013110c lang=c99 */
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
typedef unsigned int undefined4;

extern void FUN_0001f1fc();
extern void FUN_001240fc();
extern undefined4 FUN_00125218();

void FUN_0013110c(int param_1)
{
  undefined4 uVar1;
  
  FUN_0001f1fc(*(undefined4 *)(param_1 + 0x80),1);
  FUN_001240fc(*(undefined4 *)(param_1 + 0x80),0,0);
  uVar1 = FUN_00125218(*(undefined4 *)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x88) = uVar1;
  *(undefined4 *)(param_1 + 0x8c) = 3;
  return;
}
