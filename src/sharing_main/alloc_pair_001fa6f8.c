/* HSTMATCH module=hstp_trans_main.prx start=0x001fa6f8 end=0x001fa758 symbol=FUN_001fa6f8 lang=c99 */
/* Clone of src/eboot/alloc_pair_001ec3b8.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed merged-store null-checked constructor calls for both allocated objects; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void *FUN_00000bcc(u32 size);
extern void *FUN_001f9a60(void *);
extern void *FUN_001f8e28(void *);

void FUN_001fa6f8(void **param_1)
{
  void *p1 = FUN_00000bcc(316);
  if (p1 != 0) {
    p1 = FUN_001f9a60(p1);
  }
  param_1[0] = p1;

  void *p2 = FUN_00000bcc(992);
  if (p2 != 0) {
    p2 = FUN_001f8e28(p2);
  }
  param_1[1] = p2;
}
