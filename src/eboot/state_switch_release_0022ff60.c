/* HSTMATCH module=EBOOT.BIN start=0x0022ff60 end=0x0022ffe4 symbol=FUN_0022ff60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed object struct, if/else-if on the state field rewritten as a switch (cases written 3 then 4, MWCC tests them in reverse), dropped `this` argument of the case-3 callee restored; exact match verified; names and types await human review. */
extern int FUN_001b1f84(void *, int *);
extern void FUN_0022d67c(void *);
extern void FUN_0022dd04(void *);
extern char DAT_0034179c;

typedef struct Obj {
  char pad0[0xac];
  int fac;
  int fb0;
  char pad1[0x414 - 0xb4];
  int state;
} Obj;

void FUN_0022ff60(Obj *self)
{
  switch (self->state) {
  case 3:
    FUN_0022dd04(self);
    break;
  case 4:
    if (self->fb0 >= 0) {
      FUN_001b1f84(&DAT_0034179c, &self->fb0);
      self->fb0 = -1;
    }
    self->fac = -1;
    FUN_0022d67c(self);
    break;
  }
}
