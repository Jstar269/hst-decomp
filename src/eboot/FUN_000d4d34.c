/* HSTMATCH module=EBOOT.BIN start=0x000d4d34 end=0x000d4ddc symbol=FUN_000d4d34 lang=c99 */
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

extern undefined DAT_0030744c;
extern void FUN_00000788();
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern int FUN_00053718();
extern int FUN_00055e48();
extern void FUN_00056cb0();

undefined4 * FUN_000d4d34(undefined4 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030744c);
    if (param_1[0xf] != 0) {
      FUN_00053718(param_1[0xf],1);
      param_1[0xf] = 0;
    }
    iVar1 = param_1[0x10];
    if (iVar1 != 0) {
      FUN_00055e48(iVar1,1);
      param_1[0x10] = 0;
    }
    FUN_00000788(param_1 + 0x14,FUN_00056cb0,0x1b0,4);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
