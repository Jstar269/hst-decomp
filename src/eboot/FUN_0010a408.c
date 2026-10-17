/* HSTMATCH module=EBOOT.BIN start=0x0010a408 end=0x0010a4a8 symbol=FUN_0010a408 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_0010a408.c; exact match verified; names and types await human review. */
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

extern char DAT_002d8dd0[];
extern uint * FUN_000114c0();
extern void FUN_0010a4a8();
extern void FUN_00199280();
extern int FUN_002b7c20();

int FUN_0010a408(undefined4 *param_1,undefined4 param_2)
{
  uint iVar1;
  
  FUN_000114c0(param_1,0,0x2c4);
  *param_1 = 0x2c4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x11;
  param_1[4] = 0x13;
  param_1[5] = 0x12;
  param_1[6] = 0x10;
  FUN_00199280(param_1);
  param_1[0xe] = param_2;
  param_1[0xd] = 0;
  iVar1 = FUN_002b7c20(param_1);
  if (0 != iVar1) {
    FUN_0010a4a8(DAT_002d8dd0,iVar1);
  }
  return iVar1;
}
