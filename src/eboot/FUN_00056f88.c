/* HSTMATCH module=EBOOT.BIN start=0x00056f88 end=0x00056fd8 symbol=FUN_00056f88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: default MWCC profile, natural sequential member null-check and delete; exact match verified; names and types await human review. */
typedef struct Obj Obj;
struct Obj {
  char pad[352];
  void *m1;
  void *m2;
};

extern void FUN_000104e0(void *);

void FUN_00056f88(Obj *self)
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
