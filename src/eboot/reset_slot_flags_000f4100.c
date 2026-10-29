/* HSTMATCH module=EBOOT.BIN start=0x000f4100 end=0x000f4260 symbol=FUN_000f4100 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad00[0x68];
  void *pane[2];          /* 0x68 */
  char pad70[0x1f0 - 0x70];
  unsigned char flagsA[2]; /* 0x1f0 per-slot flags */
  unsigned char flagsB[2];
  unsigned char flagsC[2];
  unsigned char flagsD[2];
} Obj;

extern int FUN_000dea20(void *p, int i);
extern int FUN_000de51c(void *p, int i);
extern int FUN_000de2c8(void *p, int i);
extern int FUN_000de3f0(void *p, int i);
extern void FUN_000ffb3c(void *p, int n);
extern void *DAT_00338b44;

void FUN_000f4100(Obj *self)
{
  int i;

  for (i = 0; i < 2; i++) {
    /* matching idiom: each flag byte is cleared when its helper returns 0; the
       four checks are && chains (the byte test and the helper call), and the
       final test is one && chain over the four bytes. */
    if (self->flagsA[i] != 0 && FUN_000dea20(DAT_00338b44, i) == 0) {
      self->flagsA[i] = 0;
    }
    if (self->flagsB[i] != 0 && FUN_000de51c(DAT_00338b44, i) == 0) {
      self->flagsB[i] = 0;
    }
    if (self->flagsC[i] != 0 && FUN_000de2c8(DAT_00338b44, i) == 0) {
      self->flagsC[i] = 0;
    }
    if (self->flagsD[i] != 0 && FUN_000de3f0(DAT_00338b44, i) == 0) {
      self->flagsD[i] = 0;
    }
    if (self->flagsA[i] == 0 && self->flagsB[i] == 0 && self->flagsC[i] == 0 && self->flagsD[i] == 0) {
      FUN_000ffb3c(self->pane[i], 1);
      *(int *)self->pane[i] = 0x808080;
    }
  }
}
