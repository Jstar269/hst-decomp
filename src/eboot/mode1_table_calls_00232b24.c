/* HSTMATCH module=EBOOT.BIN start=0x00232b24 end=0x00232c08 symbol=FUN_00232b24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed object struct with the two pointer tables, the goto/shared mode re-read written as two successive mode tests, flag bytes unsigned, and the callee FUN_000edec0 declared with its integer and float parameters interleaved as (obj, rect, f, f, f, int, int, f, f) (this declared order, one of ten of the 126 float placements that schedule like retail, fixes the argument setup order); exact match verified; names and types await human review. */
typedef unsigned int uint;
extern void FUN_000edec0(void *, uint *, float, float, float, int, int, float, float);
extern void FUN_001031e8(void *);
extern int DAT_002f3d08[];

typedef struct Obj {
  char pad0[0xc0];
  uint *fc0;
  char pad1[0x168 - 0xc4];
  uint *f168;
  void *tabB[15];
  void *tabA[12];
  unsigned char f1d8;
  unsigned char f1d9;
  char pad3[2];
  int mode;
  int idx;
} Obj;

void FUN_00232b24(Obj *self)
{
  if (self->mode == 1) {
    if (self->f1d9 != 0) {
      FUN_000edec0(self->tabA[self->idx], self->f168, 0.0f, 0.0f, 1.0f, 0, 0, 1.0f, 1.0f);
    }
  }
  if (self->mode == 1 && self->f1d8 != 0) {
    FUN_000edec0(self->tabB[DAT_002f3d08[self->idx]], self->fc0, 0.0f, 0.0f, 1.0f, 0, 0, 1.0f, 1.0f);
  }
  FUN_001031e8(self);
}
