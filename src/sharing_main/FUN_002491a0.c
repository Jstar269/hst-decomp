/* HSTMATCH module=hstp_trans_main.prx start=0x002491a0 end=0x00249474 symbol=FUN_002491a0 lang=c99 */
/* Clone of src/eboot/FUN_00239008.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0388;
extern undefined DAT_003b2b7c;
extern undefined DAT_003eaad8;
extern undefined4 DAT_003f39ec;
extern void FUN_00000a00();
extern undefined4 * FUN_0001ed28();
extern int * FUN_000550a0();
extern int * FUN_000658cc();
extern int FUN_0006778c();
extern void FUN_001c170c();
extern int * FUN_0024b314();
extern undefined4 * FUN_0024c0ec();

undefined4 * FUN_002491a0(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2b7c);
    FUN_001c170c((int *)&DAT_003eaad8,6);
    DAT_003f39ec = 0;
    if ((char *)param_1 + 0x1904 != (char *)0) {
      puVar1 = param_1 + 0x649;
      param_1[0x641] = (unsigned int)(&DAT_003b0388);
      if ((((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
          (puVar1 != (undefined4 *)0x0)) && (puVar1 != (undefined4 *)0x0)) {
        FUN_0006778c((int)puVar1,0);
      }
      puVar1 = param_1 + 0x645;
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      FUN_000658cc(param_1 + 0x641,0);
    }
    if ((char *)param_1 + 0x18d4 != (char *)0) {
      puVar1 = param_1 + 0x63d;
      param_1[0x635] = (unsigned int)(&DAT_003b0388);
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      puVar1 = param_1 + 0x639;
      if ((((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
          (puVar1 != (undefined4 *)0x0)) && (puVar1 != (undefined4 *)0x0)) {
        FUN_0006778c((int)puVar1,0);
      }
      FUN_000658cc(param_1 + 0x635,0);
    }
    if ((char *)param_1 + 0x1888 != (char *)0) {
      puVar1 = param_1 + 0x62a;
      param_1[0x622] = (unsigned int)(&DAT_003b0388);
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      puVar1 = param_1 + 0x626;
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      FUN_000658cc(param_1 + 0x622,0);
    }
    if ((char *)param_1 + 0x1858 != (char *)0) {
      puVar1 = param_1 + 0x61e;
      param_1[0x616] = (unsigned int)(&DAT_003b0388);
      if ((((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
          (puVar1 != (undefined4 *)0x0)) && (puVar1 != (undefined4 *)0x0)) {
        FUN_0006778c((int)puVar1,0);
      }
      puVar1 = param_1 + 0x61a;
      if (((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) &&
         ((puVar1 != (undefined4 *)0x0 && (puVar1 != (undefined4 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      FUN_000658cc(param_1 + 0x616,0);
    }
    piVar2 = (int *)(param_1 + 0x611);
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      FUN_000550a0(piVar2,0);
    }
    piVar2 = (int *)(param_1 + 0x60e);
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      FUN_000550a0(piVar2,0);
    }
    piVar2 = (int *)(param_1 + 0x60b);
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      FUN_000550a0(piVar2,0);
    }
    piVar2 = (int *)(param_1 + 0x606);
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      FUN_0024b314(piVar2,0);
    }
    FUN_0024c0ec(param_1 + 0x14,-1);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
