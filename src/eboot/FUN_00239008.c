/* HSTMATCH module=EBOOT.BIN start=0x00239008 end=0x002392dc symbol=FUN_00239008 lang=c99 */
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
extern undefined DAT_003098b0;
extern undefined DAT_0034179c;
extern undefined4 DAT_0034a6bc;
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern int * FUN_00054554();
extern int * FUN_00064a08();
extern int FUN_00066338();
extern void FUN_001b338c();
extern int * FUN_0023b17c();
extern undefined4 * FUN_0023bf54();

undefined4 * FUN_00239008(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003098b0);
    FUN_001b338c((int *)&DAT_0034179c,6);
    DAT_0034a6bc = 0;
    if ((char *)param_1 + 0x1904 != (char *)0) {
      puVar1 = param_1 + 0x649;
      param_1[0x641] = (unsigned int)(&DAT_003070bc);
      if ((((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
          (puVar1 != (undefined4 *)0x0)) && (puVar1 != (undefined4 *)0x0)) {
        FUN_00066338((int)puVar1,0);
      }
      puVar1 = param_1 + 0x645;
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_00066338((int)puVar1,0);
      }
      FUN_00064a08(param_1 + 0x641,0);
    }
    if ((char *)param_1 + 0x18d4 != (char *)0) {
      puVar1 = param_1 + 0x63d;
      param_1[0x635] = (unsigned int)(&DAT_003070bc);
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_00066338((int)puVar1,0);
      }
      puVar1 = param_1 + 0x639;
      if ((((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
          (puVar1 != (undefined4 *)0x0)) && (puVar1 != (undefined4 *)0x0)) {
        FUN_00066338((int)puVar1,0);
      }
      FUN_00064a08(param_1 + 0x635,0);
    }
    if ((char *)param_1 + 0x1888 != (char *)0) {
      puVar1 = param_1 + 0x62a;
      param_1[0x622] = (unsigned int)(&DAT_003070bc);
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_00066338((int)puVar1,0);
      }
      puVar1 = param_1 + 0x626;
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_00066338((int)puVar1,0);
      }
      FUN_00064a08(param_1 + 0x622,0);
    }
    if ((char *)param_1 + 0x1858 != (char *)0) {
      puVar1 = param_1 + 0x61e;
      param_1[0x616] = (unsigned int)(&DAT_003070bc);
      if ((((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
          (puVar1 != (undefined4 *)0x0)) && (puVar1 != (undefined4 *)0x0)) {
        FUN_00066338((int)puVar1,0);
      }
      puVar1 = param_1 + 0x61a;
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_00066338((int)puVar1,0);
      }
      FUN_00064a08(param_1 + 0x616,0);
    }
    piVar2 = (int *)(param_1 + 0x611);
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      FUN_00054554(piVar2,0);
    }
    piVar2 = (int *)(param_1 + 0x60e);
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      FUN_00054554(piVar2,0);
    }
    piVar2 = (int *)(param_1 + 0x60b);
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      FUN_00054554(piVar2,0);
    }
    piVar2 = (int *)(param_1 + 0x606);
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      FUN_0023b17c(piVar2,0);
    }
    FUN_0023bf54(param_1 + 0x14,-1);
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
