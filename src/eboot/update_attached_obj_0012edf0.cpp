/* HSTMATCH module=EBOOT.BIN start=0x0012edf0 end=0x0012eebc symbol=FUN_0012edf0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: unsigned char flag (lbu), nested bit tests merged into one && condition, virtual call at slot 1 through a struct with a dummy virtual; exact match verified; names and types await human review. */
struct C { virtual void d0(); virtual void m(int); };
struct G { char pad[0x8b]; char bits; };
struct Obj {
  char pad[0xe0];
  C *c;
  unsigned char flag;
};
extern G *DAT_002cfc8c;
extern int DAT_003313c4;
extern int DAT_0033b578;
extern "C" void FUN_000612dc(C *, int);
extern "C" void FUN_0012f248(Obj *);
extern "C" void FUN_0015e704(C *);

extern "C" void FUN_0012edf0(Obj *self)
{
  if (DAT_0033b578 == 1 && self->c != 0) {
    if (self->flag == 0) {
      self->flag = 1;
      FUN_000612dc(self->c, DAT_003313c4);
    }
    if (((int)DAT_002cfc8c->bits << 0x1c) >> 0x1e == 0 && ((int)DAT_002cfc8c->bits << 0x18) >> 0x1e == 1) {
      FUN_0012f248(self);
      FUN_000612dc(self->c, DAT_003313c4);
    }
    FUN_0015e704(self->c);
    self->c->m(DAT_003313c4);
  }
}
