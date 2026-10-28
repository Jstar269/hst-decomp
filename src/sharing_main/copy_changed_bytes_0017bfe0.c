/* HSTMATCH module=hstp_trans_main.prx start=0x0017bfe0 end=0x0017c0b0 symbol=FUN_0017bfe0 lang=c99 */
/* Clone of src/eboot/copy_changed_bytes_0016fd94.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: byte pointers typed unsigned char (lbu), renamed src/dst with src declared first for register choice; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00177d4c();

void FUN_0017bfe0(int param_1)
{
  int iVar1;
  u8 *src;
  u8 *dst;
  
  iVar1 = FUN_00177d4c();
  dst = (u8 *)(iVar1 + 0x84c);
  src = (u8 *)(param_1 + 0x63b);
  iVar1 = 0;
  do {
    if (*src != *dst) {
      *dst = *src;
    }
    iVar1 = iVar1 + 1;
    src = src + 1;
    dst = dst + 1;
  } while (iVar1 < 0x280);
  iVar1 = FUN_00177d4c();
  dst = (u8 *)(iVar1 + 0xacc);
  src = (u8 *)(param_1 + 0x8bb);
  iVar1 = 0;
  do {
    if (*src != *dst) {
      *dst = *src;
    }
    iVar1 = iVar1 + 1;
    src = src + 1;
    dst = dst + 1;
  } while (iVar1 < 0x280);
  iVar1 = FUN_00177d4c();
  src = (u8 *)(param_1 + 0xb3b);
  dst = (u8 *)(iVar1 + 0xd4c);
  iVar1 = 0;
  do {
    if (*src != *dst) {
      *dst = *src;
    }
    iVar1 = iVar1 + 1;
    src = src + 1;
    dst = dst + 1;
  } while (iVar1 < 0x280);
}
