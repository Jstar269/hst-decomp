/* HSTMATCH module=hstp_trans_main.prx start=0x00094ba4 end=0x00094c5c symbol=FUN_00094ba4 lang=c++ */
/* Clone of src/eboot/open_init_object_00092d10.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed Obj struct, new-with-ctor store through one local, dropped call arguments restored (FUN_0004d2c4 receives the open result, FUN_00057c88 receives the two tested members); exact match verified; names and types await human review. */
extern char DAT_00378cd0[];
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
extern "C" int FUN_0004cfac(char *, int, int);
extern "C" void FUN_0004d2c4(int);
extern "C" Sub *FUN_000569a4(void *, char *, int);
extern "C" void FUN_00057c88(int, Sub *);
extern "C" void FUN_00094c5c(Obj *);

extern "C" void FUN_00094ba4(Obj *self, int param_2)
{
  char buf[256];
  FUN_000143b0(buf, DAT_00378cd0, param_2);
  int r = FUN_0004cfac(buf, 1, 1);
  if (r >= 0) {
    FUN_0004d2c4(r);
    FUN_00094c5c(self);
    self->f68 = param_2;
    Sub *mem = (Sub *)FUN_00000bcc(0x10);
    if (mem) mem = FUN_000569a4(mem, buf, 0);
    self->f6c = mem;
    if (self->f58 != 0 && self->f6c != 0) FUN_00057c88(self->f58, self->f6c);
  }
}
