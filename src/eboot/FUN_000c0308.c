/* HSTMATCH module=EBOOT.BIN start=0x000c0308 end=0x000c038c symbol=FUN_000c0308 lang=c99 */
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

extern undefined DAT_003073fc;
extern void FUN_00000a00();
extern void FUN_002b78e0();
extern void FUN_002b7900();

undefined4 * FUN_000c0308(undefined4 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003073fc);
    if ((undefined1 *)param_1[4] != (undefined1 *)0x0) {
      *(undefined1 *)param_1[4] = 1;
    }
    iVar1 = param_1[1];
    if (0 < iVar1) {
      FUN_002b78e0(iVar1,0);
      FUN_002b7900(param_1[1]);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
