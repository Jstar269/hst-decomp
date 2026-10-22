/* HSTMATCH module=hstp_trans_main.prx start=0x000f97f4 end=0x000f9954 symbol=FUN_000f97f4 lang=c99 */
/* Clone of src/eboot/reset_slot_flags_000f4100.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad00[0x68];
  void *f68[2];
  char pad70[0x1f0 - 0x70];
  unsigned char f1f0[2];
  unsigned char f1f2[2];
  unsigned char f1f4[2];
  unsigned char f1f6[2];
} Obj;

extern int FUN_000e2c0c(void *p, int i);
extern int FUN_000e2708(void *p, int i);
extern int FUN_000e24b4(void *p, int i);
extern int FUN_000e25dc(void *p, int i);
extern void FUN_00105470(void *p, int n);
extern void *DAT_003e1e84;

void FUN_000f97f4(Obj *self)
{
  int i;

  for (i = 0; i < 2; i++) {
    /* matching idiom: each flag byte is cleared when its helper returns 0; the
       four checks are && chains (the byte test and the helper call), and the
       final test is one && chain over the four bytes. */
    if (self->f1f0[i] != 0 && FUN_000e2c0c(DAT_003e1e84, i) == 0) {
      self->f1f0[i] = 0;
    }
    if (self->f1f2[i] != 0 && FUN_000e2708(DAT_003e1e84, i) == 0) {
      self->f1f2[i] = 0;
    }
    if (self->f1f4[i] != 0 && FUN_000e24b4(DAT_003e1e84, i) == 0) {
      self->f1f4[i] = 0;
    }
    if (self->f1f6[i] != 0 && FUN_000e25dc(DAT_003e1e84, i) == 0) {
      self->f1f6[i] = 0;
    }
    if (self->f1f0[i] == 0 && self->f1f2[i] == 0 && self->f1f4[i] == 0 && self->f1f6[i] == 0) {
      FUN_00105470(self->f68[i], 1);
      *(int *)self->f68[i] = 0x808080;
    }
  }
}
