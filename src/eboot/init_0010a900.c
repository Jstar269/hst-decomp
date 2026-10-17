/* HSTMATCH module=EBOOT.BIN start=0x0010a900 end=0x0010aa08 symbol=FUN_0010a900 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the function returns int (the stripped print call is declared int and its result is stored back into the checked value, which is returned: `if (r) r = print(fmt, r); return r;`), which keeps r in v0 and gives retail beqzl/move a1,v0 shape; exact match verified; names and types await human review. */
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

extern undefined DAT_002d8fcc;
extern char DAT_002d8fd0[];
extern char DAT_002d8fdc[];
extern uint * FUN_000114c0();
extern char * FUN_00014b74();
extern int FUN_0010a4a8(const char *, ...);
extern void FUN_00199280();
extern int FUN_002b7cb0();

int FUN_0010a900(undefined4 *param_1,char *param_2,undefined4 param_3)
{
  int iVar1;
  
  FUN_000114c0(param_1,0,100);
  *param_1 = 100;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x11;
  param_1[4] = 0x13;
  param_1[5] = 0x12;
  param_1[6] = 0x10;
  FUN_00199280(param_1);
  param_1[3] = 0x27;
  param_1[4] = 0x29;
  param_1[5] = 0x28;
  param_1[6] = 0x26;
  FUN_00014b74(param_1 + 0xe,&DAT_002d8fcc,8);
  param_1[0x15] = 1;
  param_1[0x16] = 2;
  param_1[0x17] = (unsigned int)(param_2);
  param_1[0x18] = param_3;
  param_1[0x14] = 0;
  FUN_0010a4a8(DAT_002d8fd0,(int)*param_2,(int)param_2[1],(int)param_2[2],(int)param_2[3]);
  iVar1 = FUN_002b7cb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_0010a4a8(DAT_002d8fdc,iVar1);
  }
  return iVar1;
}
