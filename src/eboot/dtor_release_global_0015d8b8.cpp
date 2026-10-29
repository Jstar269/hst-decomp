/* HSTMATCH module=EBOOT.BIN start=0x0015d8b8 end=0x0015d960 symbol=FUN_0015d8b8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: global virtual-deleting-destructor call written as C++ delete on a struct with virtual ~V(); readability pass; exact match verified; names and types await human review. */
struct V { virtual ~V(); };
struct Obj { void *vptr; };
extern char DAT_00309054;
extern V *DAT_003403f8; /* global instance owned (and deleted) by this holder */
extern int DAT_003403fc;
extern char DAT_0034179c;
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_0001f0f0(Obj *, int);
extern "C" void FUN_001b338c(void *, int);

/* Deleting destructor of the global instance's holder: deletes the instance and clears the globals. */
extern "C" Obj *FUN_0015d8b8(Obj *self, short delete_flag)
{
  if (self) {
    self->vptr = &DAT_00309054;
    DAT_003403fc = 0;
    if (DAT_003403f8) {
      delete DAT_003403f8;
      DAT_003403f8 = 0;
    }
    FUN_001b338c(&DAT_0034179c, 0);
    FUN_0001f0f0(self, 0);
    if (delete_flag > 0) FUN_00000a00(self);
  }
  return self;
}
