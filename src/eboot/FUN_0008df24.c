/* HSTMATCH module=EBOOT.BIN start=0x0008df24 end=0x0008e01c symbol=FUN_0008df24 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q4); exact match verified; names and types await human review. */
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

extern undefined DAT_0030722c;
extern undefined DAT_00307238;
extern void FUN_00000788();
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern undefined4 * FUN_000510c0();
extern undefined4 * FUN_00056cb0();
extern int FUN_0006e024();
extern int * FUN_00091280();
extern undefined4 * FUN_000c24a8();
extern void FUN_0005aeac();

undefined4 * FUN_0008df24(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030722c);
    param_1[0x78] = (unsigned int)(&DAT_00307238);
    FUN_00000788(param_1 + 0x128,FUN_0005aeac,0x70,2);
    FUN_000510c0(param_1 + 0x114,0xffffffff);
    FUN_0006e024(param_1 + 0x112,0xffffffff);
    FUN_00056cb0(param_1 + 0xa4,0xffffffff);
    if ((char *)param_1 + 0x26c != (char *)0) {
      puVar1 = param_1 + 0x9e;
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_00091280(puVar1,0);
      }
      puVar1 = param_1 + 0x9b;
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_00091280(puVar1,0);
      }
    }
    FUN_0001f0f0(param_1 + 0x78,0);
    FUN_000c24a8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
