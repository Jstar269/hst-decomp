/* HSTMATCH module=EBOOT.BIN start=0x00126c2c end=0x00126d1c symbol=FUN_00126c2c lang=c99 data=0x002da7d4 */
/* Ghidra pseudocode (hstgen.py tag q2) corrected by hand: the member sub-object null test restored (Ghidra folded its offset into the compared constant); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002da7d4-0x002da7f0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined DAT_00308050;
extern undefined DAT_00308064;
extern void FUN_00000a00();
extern undefined4 * FUN_000918ac();
extern int FUN_000d7e30();
extern int * FUN_000e88e4();
extern void FUN_00126d1c();
extern undefined4 * FUN_0028686c();

undefined4 * FUN_00126c2c(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00308050);
    param_1[0x38] = (unsigned int)(&DAT_00308064);
    FUN_00126d1c("Avatar: destructor called.\n");
    puVar1 = param_1 + 0x105;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_000e88e4(puVar1,0);
    }
    puVar1 = param_1 + 0xdc;
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = param_1 + 0xfd;
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_000e88e4(puVar1,0);
      }
      puVar1 = param_1 + 0xf8;
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_000e88e4(puVar1,0);
      }
    }
    FUN_000d7e30(param_1 + 0x96,0xffffffff);
    FUN_0028686c(param_1 + 0x38,0);
    FUN_000918ac(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
