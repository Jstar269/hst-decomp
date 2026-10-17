/* HSTMATCH module=hstp_trans_main.prx start=0x00057bdc end=0x00057c2c symbol=FUN_00057bdc lang=c99 */
/* Clone of src/eboot/FUN_00056f88.c (hstclone.py tag u1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: default MWCC profile, natural sequential member null-check and delete; exact match verified; names and types await human review. */
typedef struct Obj Obj;
struct Obj {
  char pad[352];
  void *m1;
  void *m2;
};

extern void FUN_000104e0(void *);

void FUN_00057bdc(Obj *self)
{
  if (self->m1 != 0) {
    FUN_000104e0(self->m1);
    self->m1 = 0;
  }
  if (self->m2 != 0) {
    FUN_000104e0(self->m2);
    self->m2 = 0;
  }
}
