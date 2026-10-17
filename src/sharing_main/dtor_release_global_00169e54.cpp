/* HSTMATCH module=hstp_trans_main.prx start=0x00169e54 end=0x00169efc symbol=FUN_00169e54 lang=c++ */
/* Clone of src/eboot/dtor_release_global_0015d8b8.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: global virtual-deleting-destructor call written as C++ delete on a struct with virtual ~V(); exact match verified; names and types await human review. */
struct V { virtual ~V(); };
struct Obj { void *vptr; };
extern char DAT_003b2320;
extern V *DAT_003e9738;
extern int DAT_003e973c;
extern char DAT_003eaad8;
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_0001ed28(Obj *, int);
extern "C" void FUN_001c170c(void *, int);

extern "C" Obj *FUN_00169e54(Obj *self, short flag)
{
  if (self) {
    self->vptr = &DAT_003b2320;
    DAT_003e973c = 0;
    if (DAT_003e9738) {
      delete DAT_003e9738;
      DAT_003e9738 = 0;
    }
    FUN_001c170c(&DAT_003eaad8, 0);
    FUN_0001ed28(self, 0);
    if (flag > 0) FUN_00000a00(self);
  }
  return self;
}
