/* HSTMATCH module=EBOOT.BIN start=0x001fd2e0 end=0x001fd46c symbol=FUN_001fd2e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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

extern undefined DAT_003070bc;
extern undefined DAT_003095b0;
extern undefined4 DAT_0034a13c;
extern void FUN_00000788();
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern int * FUN_00064a08();
extern int FUN_00066338();
extern int FUN_001ffcc0();
extern int FUN_00201a44();
extern void FUN_00204394();
extern void FUN_0005ba00();

undefined4 * FUN_001fd2e0(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003095b0);
    FUN_00204394();
    DAT_0034a13c = 0;
    if ((char *)param_1 + 0x12c4 != (char *)0) {
      puVar1 = param_1 + 0x4b9;
      param_1[0x4b1] = (unsigned int)(&DAT_003070bc);
      if ((((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
          (puVar1 != (undefined4 *)0x0)) && (puVar1 != (undefined4 *)0x0)) {
        FUN_00066338((int)puVar1,0);
      }
      puVar1 = param_1 + 0x4b5;
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_00066338((int)puVar1,0);
      }
      FUN_00064a08(param_1 + 0x4b1,0);
    }
    if ((char *)param_1 + 0x1294 != (char *)0) {
      puVar1 = param_1 + 0x4ad;
      param_1[0x4a5] = (unsigned int)(&DAT_003070bc);
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_00066338((int)puVar1,0);
      }
      puVar1 = param_1 + 0x4a9;
      if ((((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
          (puVar1 != (undefined4 *)0x0)) && (puVar1 != (undefined4 *)0x0)) {
        FUN_00066338((int)puVar1,0);
      }
      FUN_00064a08(param_1 + 0x4a5,0);
    }
    FUN_00201a44((int)(param_1 + 0x494),-1);
    FUN_00000788((int)(param_1 + 0x334),FUN_0005ba00,0x2c0,2);
    FUN_001ffcc0((int)(param_1 + 0x32),-1);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
