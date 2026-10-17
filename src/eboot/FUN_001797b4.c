/* HSTMATCH module=EBOOT.BIN start=0x001797b4 end=0x001797fc symbol=FUN_001797b4 lang=c99 */
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

extern void FUN_0017ce84();
extern void FUN_00180edc();

void FUN_001797b4(int param_1)
{
  undefined4 uVar1;
  
  if (0 < *(int *)(param_1 + 0x6c)) {
    uVar1 = (**(code **)(param_1 + 0x558))();
    FUN_00180edc(*(undefined4 *)(param_1 + 0x174),uVar1);
    FUN_0017ce84(*(undefined4 *)(param_1 + 0x178));
  }
  return;
}
