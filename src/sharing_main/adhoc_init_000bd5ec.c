/* HSTMATCH module=hstp_trans_main.prx start=0x000bd5ec end=0x000bd6f0 symbol=FUN_000bd5ec lang=c99 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/FUN_000ba2a8.c, same instruction shape: Sharing addresses substituted; its corrections kept: inverted create-result branch, block-scoped cursor and count for the array-clear loop); exact match verified; names and types await human review. */
/* Ad-hoc networking object constructor: vtable DAT_003b06bc, field resets, sceKernelCreateSema("AdhocSema", 0, 1, 1, 0) through FUN_002c7630 with the success/failure log through the next function FUN_000bd6f0. */
#include "hst/types.h"

extern u8 DAT_003b06bc;
extern char DAT_0037b37c[];
extern char DAT_0037b388[];
extern char DAT_0037b3a8[];
extern u32 * FUN_000114c0();
extern void FUN_000bd6f0();
extern void FUN_000bee48();
extern int FUN_002c7630();

u32 * FUN_000bd5ec(u32 *param_1)
{
  int iVar1;
  
  *param_1 = (unsigned int)(&DAT_003b06bc);
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  *(u8 *)(param_1 + 0x5e) = 0;
  param_1[0x5b] = 0xffffffff;
  param_1[0x5f] = 0xffffffff;
  param_1[0x66] = 0xffffffff;
  param_1[0x9c] = 0;
  param_1[0xa1] = 0;
  FUN_000bee48();
  param_1[0xd] = 0xffffffff;
  iVar1 = FUN_002c7630(DAT_0037b37c,0,1,1,0);
  if (iVar1 > 0) {
    param_1[0xd] = iVar1;
    FUN_000bd6f0(DAT_0037b388);
    param_1[0x9b] = 0;
  } else {
    FUN_000bd6f0(DAT_0037b3a8,iVar1);
    param_1[0x9b] = 0;
  }
  {
    int count = 0;
    u32 *cursor = param_1;
    do {
      cursor[0x8b] = 0;
      cursor[0x8c] = 0;
      cursor[0x8d] = 0;
      cursor[0x8e] = 0;
      cursor[0x8f] = 0;
      cursor[0x90] = 0;
      cursor[0x91] = 0;
      count = count + 8;
      cursor[0x92] = 0;
      cursor = cursor + 8;
    } while (count < 0x10);
  }
  *(u8 *)(param_1 + 0x9e) = 0;
  FUN_000114c0(param_1 + 0x9f,0,8);
  return param_1;
}
