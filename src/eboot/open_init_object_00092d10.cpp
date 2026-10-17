/* HSTMATCH module=EBOOT.BIN start=0x00092d10 end=0x00092dc8 symbol=FUN_00092d10 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed Obj struct, new-with-ctor store through one local, dropped call arguments restored (FUN_0004cfd0 receives the open result, FUN_00057034 receives the two tested members); exact match verified; names and types await human review. */
extern char DAT_002d2a0c[];
struct Sub;
struct Obj {
  char pad0[0x58];
  int f58;
  char pad1[0x68 - 0x5c];
  int f68;
  Sub *f6c;
};
extern "C" void *FUN_00000bcc(int);
extern "C" void FUN_000143b0(char *, char *, int);
extern "C" int FUN_0004ccb8(char *, int, int);
extern "C" void FUN_0004cfd0(int);
extern "C" Sub *FUN_00055df8(void *, char *, int);
extern "C" void FUN_00057034(int, Sub *);
extern "C" void FUN_00092dc8(Obj *);

extern "C" void FUN_00092d10(Obj *self, int param_2)
{
  char buf[256];
  FUN_000143b0(buf, DAT_002d2a0c, param_2);
  int r = FUN_0004ccb8(buf, 1, 1);
  if (r >= 0) {
    FUN_0004cfd0(r);
    FUN_00092dc8(self);
    self->f68 = param_2;
    Sub *mem = (Sub *)FUN_00000bcc(0x10);
    if (mem) mem = FUN_00055df8(mem, buf, 0);
    self->f6c = mem;
    if (self->f58 != 0 && self->f6c != 0) FUN_00057034(self->f58, self->f6c);
  }
}
