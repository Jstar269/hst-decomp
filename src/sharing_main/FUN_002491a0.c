/* HSTMATCH module=hstp_trans_main.prx start=0x002491a0 end=0x00249474 symbol=FUN_002491a0 lang=c99 */
/* Clone of src/eboot/FUN_00239008.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0388;
extern u8 DAT_003b2b7c;
extern u8 DAT_003eaad8;
extern u32 DAT_003f39ec;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int * FUN_000550a0();
extern int * FUN_000658cc();
extern int FUN_0006778c();
extern void FUN_001c170c();
extern int * FUN_0024b314();
extern u32 * FUN_0024c0ec();

u32 * FUN_002491a0(u32 *param_1,short param_2)
{
  u32 *puVar1;
  int *piVar2;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2b7c);
    FUN_001c170c((int *)&DAT_003eaad8,6);
    DAT_003f39ec = 0;
    if ((char *)param_1 + 0x1904 != (char *)0) {
      puVar1 = param_1 + 0x649;
      param_1[0x641] = (unsigned int)(&DAT_003b0388);
      if ((((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
          (puVar1 != (u32 *)0x0)) && (puVar1 != (u32 *)0x0)) {
        FUN_0006778c((int)puVar1,0);
      }
      puVar1 = param_1 + 0x645;
      if (((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
         ((puVar1 != (u32 *)0x0 && (puVar1 != (u32 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      FUN_000658cc(param_1 + 0x641,0);
    }
    if ((char *)param_1 + 0x18d4 != (char *)0) {
      puVar1 = param_1 + 0x63d;
      param_1[0x635] = (unsigned int)(&DAT_003b0388);
      if (((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
         ((puVar1 != (u32 *)0x0 && (puVar1 != (u32 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      puVar1 = param_1 + 0x639;
      if ((((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
          (puVar1 != (u32 *)0x0)) && (puVar1 != (u32 *)0x0)) {
        FUN_0006778c((int)puVar1,0);
      }
      FUN_000658cc(param_1 + 0x635,0);
    }
    if ((char *)param_1 + 0x1888 != (char *)0) {
      puVar1 = param_1 + 0x62a;
      param_1[0x622] = (unsigned int)(&DAT_003b0388);
      if (((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
         ((puVar1 != (u32 *)0x0 && (puVar1 != (u32 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      puVar1 = param_1 + 0x626;
      if (((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
         ((puVar1 != (u32 *)0x0 && (puVar1 != (u32 *)0x0)))) {
        FUN_0006778c((int)puVar1,0);
      }
      FUN_000658cc(param_1 + 0x622,0);
    }
    if ((char *)param_1 + 0x1858 != (char *)0) {
      puVar1 = param_1 + 0x61e;
      param_1[0x616] = (unsigned int)(&DAT_003b0388);
      if ((((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
          (puVar1 != (u32 *)0x0)) && (puVar1 != (u32 *)0x0)) {
        FUN_0006778c((int)puVar1,0);
      }
      puVar1 = param_1 + 0x61a;
      if (((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) &&
         ((puVar1 != (u32 *)0x0 && (puVar1 != (u32 *)0x0)))) {
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
