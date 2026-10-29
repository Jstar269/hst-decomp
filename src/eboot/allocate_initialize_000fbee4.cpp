/* HSTMATCH module=EBOOT.BIN start=0x000fbee4 end=0x000fbf84 symbol=FUN_000fbee4 lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idiom: an inline constructor in the new-expression keeps allocation failure on the early exit path; exact match verified; names and types await human review. */
extern "C" void FUN_000fc0a0(void *);
extern "C" void FUN_00056098(void *);
extern "C" void FUN_000fc00c(void *,void *);
extern "C" void FUN_000fbf84(void *,void *);
extern "C" char DAT_0030779c;
extern "C" char DAT_002bc410;

struct NewObject {
  void *vtbl;             /* 0x00 */
  char pad4[0x2c];
  char sub30[0x40];       /* 0x30 sub-object */
  int unk70;              /* 0x70 */
  int unk74;              /* 0x74 -1 when unset */
  float unk78;            /* 0x78 */
  float unk7c;            /* 0x7c */
  char sub80[0x40];       /* 0x80 sub-object */
  unsigned value;         /* 0xc0 */
  char padc4[0xc];
  NewObject(unsigned v) {
    FUN_000fc0a0(this);
    FUN_00056098(sub30);
    vtbl = &DAT_0030779c;
    unk70 = 0;
    unk74 = 0xffffffff;
    unk78 = 1.0f;
    unk7c = 1.0f;
    FUN_00056098(sub80);
    value = v;
    FUN_000fc00c(this,&DAT_002bc410);
    FUN_000fbf84(sub80,&DAT_002bc410);
  }
};

/* Allocate and construct the object with `value`; clears *out. */
extern "C" NewObject *FUN_000fbee4(unsigned, unsigned value, unsigned char *out) {
  *out = 0;
  return new NewObject(value);
}
