/* HSTMATCH module=EBOOT.BIN start=0x001323e8 end=0x001325d4 symbol=FUN_001323e8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s512a); exact match verified; names and types await human review. */
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

extern undefined DAT_0030820c;
extern undefined DAT_00308228;
extern undefined4 DAT_003402a0;
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern int * FUN_00054554();
extern int * FUN_0005f47c();
extern int * FUN_000e88e4();
extern void FUN_001325d4();
extern int * FUN_0013c908();
extern int * FUN_0013ca1c();
extern int * FUN_0013cac8();
extern int * FUN_0013cb74();
extern int * FUN_0013cc20();
extern int * FUN_0013cccc();
extern int * FUN_0013cd88();
extern int * FUN_0013ce44();
extern int * FUN_0013cf00();
extern int * FUN_0013cfac();
extern undefined4 * FUN_001407f0();

undefined4 * FUN_001323e8(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030820c);
    param_1[0x10] = (unsigned int)(&DAT_00308228);
    FUN_001325d4();
    puVar1 = param_1 + 0x514;
    DAT_003402a0 = 0;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0013cfac(puVar1,0);
    }
    puVar1 = param_1 + 0x50c;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_000e88e4(puVar1,0);
    }
    puVar1 = param_1 + 0x502;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0005f47c(puVar1,0);
    }
    puVar1 = param_1 + 0x4ff;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_00054554(puVar1,0);
    }
    puVar1 = param_1 + 0x4fc;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0013c908(puVar1,0);
    }
    puVar1 = param_1 + 0x4f9;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0013cf00(puVar1,0);
    }
    puVar1 = param_1 + 0x4f6;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0013ce44(puVar1,0);
    }
    puVar1 = param_1 + 0x4f3;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0013cd88(puVar1,0);
    }
    puVar1 = param_1 + 0x4ef;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0013cccc(puVar1,0);
    }
    puVar1 = param_1 + 0x4ec;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0013cc20(puVar1,0);
    }
    puVar1 = param_1 + 0x4e9;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0013cb74(puVar1,0);
    }
    puVar1 = param_1 + 0x4e6;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0013cac8(puVar1,0);
    }
    puVar1 = param_1 + 0x4e3;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0013ca1c(puVar1,0);
    }
    FUN_001407f0(param_1 + 0x10,0);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
