/* HSTMATCH module=EBOOT.BIN start=0x001523fc end=0x00152484 symbol=FUN_001523fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
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

extern undefined DAT_0030840c;
extern undefined DAT_00308c20;
extern void FUN_000009e4();
extern void FUN_00000a00();

undefined4 * FUN_001523fc(undefined4 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00308c20);
    iVar1 = param_1[4];
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      param_1[4] = 0;
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = (unsigned int)(&DAT_0030840c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
