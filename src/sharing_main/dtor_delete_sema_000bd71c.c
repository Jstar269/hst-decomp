/* HSTMATCH module=hstp_trans_main.prx start=0x000bd71c end=0x000bd7d0 symbol=FUN_000bd71c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-adapted clone of src/eboot/FUN_000ba3d8.c (EXACT EBOOT sibling, same instruction shape; that source corrected the Ghidra pseudocode by passing the tested field to the sema-delete call, typing the variadic log helper and reversing the result branch): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b06bc;
extern char DAT_0037b3d4[];
extern char DAT_0037b400[];
extern void FUN_00000a00();
extern void FUN_000bd6f0(const char *, ...);
extern void FUN_000bebf4();
extern void FUN_000bee48();
extern void FUN_000bf394();
extern void FUN_000bf998();
extern void FUN_000bfba0();
extern int FUN_002c7688(int);

int * FUN_000bd71c(int *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    *param_1 = (unsigned int)(&DAT_003b06bc);
    FUN_000bf998();
    FUN_000bfba0(param_1);
    FUN_000bf394(param_1);
    FUN_000bebf4(param_1);
    FUN_000bee48(param_1);
    if (param_1[0xd] > 0) {
      iVar1 = FUN_002c7688(param_1[0xd]);
      if (iVar1 != 0) {
        FUN_000bd6f0(DAT_0037b3d4,iVar1);
      } else {
        FUN_000bd6f0(DAT_0037b400);
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
