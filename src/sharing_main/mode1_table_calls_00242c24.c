/* HSTMATCH module=hstp_trans_main.prx start=0x00242c24 end=0x00242d08 symbol=FUN_00242c24 lang=c99 */
/* Clone of src/eboot/mode1_table_calls_00232b24.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed object struct with the two pointer tables, the goto/shared mode re-read written as two successive mode tests, flag bytes unsigned, and the callee FUN_000f3588 declared with its integer and float parameters interleaved as (obj, rect, f, f, f, int, int, f, f) (this declared order, one of ten of the 126 float placements that schedule like retail, fixes the argument setup order); exact match verified; names and types await human review. */
#include "hst/types.h"
extern void FUN_000f3588(void *, u32 *, float, float, float, int, int, float, float);
extern void FUN_00108aec(void *);
extern int DAT_0039c5cc[];

typedef struct Obj {
  char pad0[0xc0];
  u32 *fc0;
  char pad1[0x168 - 0xc4];
  u32 *f168;
  void *tabB[15];
  void *tabA[12];
  unsigned char f1d8;
  unsigned char f1d9;
  char pad3[2];
  int mode;
  int idx;
} Obj;

void FUN_00242c24(Obj *self)
{
  if (self->mode == 1) {
    if (self->f1d9 != 0) {
      FUN_000f3588(self->tabA[self->idx], self->f168, 0.0f, 0.0f, 1.0f, 0, 0, 1.0f, 1.0f);
    }
  }
  if (self->mode == 1 && self->f1d8 != 0) {
    FUN_000f3588(self->tabB[DAT_0039c5cc[self->idx]], self->fc0, 0.0f, 0.0f, 1.0f, 0, 0, 1.0f, 1.0f);
  }
  FUN_00108aec(self);
}
