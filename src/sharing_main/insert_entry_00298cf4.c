/* HSTMATCH module=hstp_trans_main.prx start=0x00298cf4 end=0x00298d9c symbol=FUN_00298cf4 lang=c99 */
/* Clone of src/eboot/insert_entry_002875f8.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: 24-byte record struct, !(0 < param_3) condition, and exact local declaration order; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_003f3610;
extern void FUN_00235074(int, int, int, int, int);
extern int FUN_0029a6c8(int, int *);
extern int FUN_0029ace0(void *, int, void *, void *);

struct Rec {
  int f0;
  int f4;
  int f8;
  int fc;
  int f10;
  int f14;
};

void FUN_00298cf4(int param_1, int param_2, u32 param_3, int param_4)
{
  int local_4;
  struct Rec rec;
  int out;
  int p28;

  if (param_4 <= 0) {
    local_4 = 0;
    int r = FUN_0029a6c8(param_1, &local_4);
    if (r < 0) {
      return;
    }
    if (local_4 == 0) {
      return;
    }
    FUN_00235074(DAT_003f3610, param_2, local_4, r, !(0 < param_3));
    return;
  }

  rec.fc = param_3 & 0xff;
  rec.f0 = 61;
  rec.f4 = param_4;
  p28 = param_1 + 104;
  rec.f8 = param_2;
  FUN_0029ace0(&out, param_1 + 100, &p28, &rec);
}
