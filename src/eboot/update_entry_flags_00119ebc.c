/* HSTMATCH module=EBOOT.BIN start=0x00119ebc end=0x00119fb4 symbol=FUN_00119ebc lang=c99 */
/* Clone of src/sharing_main/update_entry_flags_00125090.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
// Update status flags on entry based on team matching and queries

#include "hst/types.h"

extern u32 DAT_003386b0;
extern u8 * DAT_00338b44;
extern u32 DAT_00338c20;
extern u8 DAT_003417bf;
extern u8 DAT_003417c0;
extern u32 FUN_000fb874();
extern u32 FUN_001eaaf4();
extern int FUN_001eab08();

void FUN_00119ebc(int param_1)
{
  u32 uVar1;
  int iVar2;
  u32 uVar3;
  u32 uVar4;
  int cond;
  char *ptr;
  int idx;

  *(char *)(param_1 + 0x2c8) = 0;
  *(char *)(param_1 + 0x2c9) = 0;
  *(char *)(param_1 + 0x2ca) = 0;

  ptr = (char *)DAT_00338b44;
  idx = *(int *)(ptr + 0x50);
  idx = idx * 4;
  idx += DAT_003386b0;
  uVar4 = *(u32 *)(*(int *)(idx + 0x70) + 0x144);
  uVar3 = *(u32 *)(ptr + 0xa0);

  if (uVar3 == uVar4 || uVar3 == (uVar4 ^ 1)) {
    cond = (uVar3 != 0);
    uVar1 = FUN_000fb874(DAT_00338c20);
    iVar2 = FUN_001eab08(uVar1);
    if (iVar2 == 0) {
      if (cond != uVar4) {
        *(char *)(param_1 + 0x2c9) = 1;
      }
      else {
        *(char *)(param_1 + 0x2c8) = 1;
      }
    }
    uVar1 = FUN_000fb874(DAT_00338c20);
    iVar2 = FUN_001eaaf4(uVar1, cond ^ 1);
    if (iVar2 == 0 && DAT_003417bf == 0 && DAT_003417c0 == 0) {
      *(char *)(param_1 + 0x2ca) = 1;
    }
  }
}
