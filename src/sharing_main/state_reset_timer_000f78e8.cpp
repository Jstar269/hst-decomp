/* HSTMATCH module=hstp_trans_main.prx start=0x000f78e8 end=0x000f7974 symbol=FUN_000f78e8 lang=c++ */
/* Clone of src/eboot/state_reset_timer_000f2220.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct with unsigned char flag (lbu), range test rewritten as if (v >= 100) / else if (v >= 30) / else; exact match verified; names and types await human review. */
struct Obj {
  char pad0[0x68];
  int f68;
  char pad1[0x70 - 0x6c];
  int f70;
  int f74;
  int f78;
  int f7c;
  int f80;
  unsigned char f84;
};
extern "C" int FUN_0000d548(int);
extern "C" void FUN_00116fd4(int, int);

extern "C" void FUN_000f78e8(Obj *self, int param_2)
{
  if (self->f84 != 0) {
    self->f70 = 0;
    *(unsigned *)&self->f74 = 0x3f800000;
    if (self->f7c != param_2) {
      self->f7c = param_2;
      int v = FUN_0000d548(param_2 - self->f78);
      if (v >= 100) self->f80 = 4;
      else if (v >= 0x1e) self->f80 = 2;
      else self->f80 = 1;
      FUN_00116fd4(self->f68, self->f78);
    }
  }
}
