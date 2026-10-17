/* HSTMATCH module=EBOOT.BIN start=0x0010a4d4 end=0x0010a5b0 symbol=FUN_0010a4d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the function returns int (the stripped print call is declared int and its result is stored back into the checked value, which is returned: `if (r) r = print(fmt, r); return r;`), which keeps r in v0 and gives retail beqzl/move a1,v0 shape; exact match verified; names and types await human review. */
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
extern char * FUN_00014b74();
extern int FUN_0010a4a8(const char *, ...);
extern void FUN_00199280();
extern int FUN_002b7c20();

int FUN_0010a4d4(undefined4 *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  
  FUN_000114c0(param_1,0,0x2c4);
  *param_1 = 0x2c4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x11;
  param_1[4] = 0x13;
  param_1[5] = 0x12;
  param_1[6] = 0x10;
  FUN_00199280(param_1);
  param_1[0xd] = 1;
  if (param_3 == 1) {
    param_1[0x8f] = 0x90;
  }
  else if (param_3 == 2) {
    param_1[0x8f] = 0x80;
  }
  FUN_00014b74(param_1 + 0xf,param_2,0x1ff);
  *(undefined1 *)((int)param_1 + 0x23b) = 0;
  iVar1 = FUN_002b7c20(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_0010a4a8(DAT_002d8dd0,iVar1);
  }
  return iVar1;
}
