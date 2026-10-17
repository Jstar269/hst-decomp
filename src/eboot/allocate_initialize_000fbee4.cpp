/* HSTMATCH module=EBOOT.BIN start=0x000fbee4 end=0x000fbf84 symbol=FUN_000fbee4 lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idiom: an inline constructor in the new-expression keeps allocation failure on the early exit path; exact match verified; names and types await human review. */
extern "C" void FUN_000fc0a0(void *);
extern "C" void FUN_00056098(void *);
extern "C" void FUN_000fc00c(void *,void *);
extern "C" void FUN_000fbf84(void *,void *);
extern "C" char DAT_0030779c;
extern "C" char DAT_002bc410;
struct Object_fbee4 {
  char pad0[0x30];
  int at30;
  char pad34[0x4c];
  int at80;
  char pad84[0x3c];
  unsigned value;
  char padc4[0xc];
  Object_fbee4(unsigned v) {
    FUN_000fc0a0(this);
    FUN_00056098(&at30);
    *(void **)this = &DAT_0030779c;
    ((unsigned *)this)[0x1c] = 0;
    ((unsigned *)this)[0x1d] = 0xffffffff;
    ((unsigned *)this)[0x1e] = 0x3f800000;
    ((unsigned *)this)[0x1f] = 0x3f800000;
    FUN_00056098(&at80);
    value = v;
    FUN_000fc00c(this,&DAT_002bc410);
    FUN_000fbf84((char *)this + 0x80,&DAT_002bc410);
  }
};
extern "C" Object_fbee4 *FUN_000fbee4(unsigned, unsigned value, unsigned char *out) {
  *out = 0;
  return new Object_fbee4(value);
}
