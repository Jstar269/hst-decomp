/* HSTMATCH module=EBOOT.BIN start=0x00117cc4 end=0x00117d38 symbol=FUN_00117cc4 lang=c99 */
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

extern undefined4 DAT_003386b0;
extern void FUN_0001f558();
extern void FUN_00117d70();
extern void FUN_00117dd0();

void FUN_00117cc4(int param_1)
{
  FUN_00117d70(param_1,((*(int *)(param_1 + 0x5c) + 10) - (*(int *)(param_1 + 0x68) + 1) % 9) % 9,
               0xffffffff,0);
  FUN_00117dd0(param_1);
  FUN_0001f558(DAT_003386b0,0x16,0,0);
  return;
}
