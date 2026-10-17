/* HSTMATCH module=hstp_trans_main.prx start=0x00101620 end=0x001016c0 symbol=FUN_00101620 lang=c++ */
/* Clone of src/eboot/allocate_initialize_000fbee4.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: an inline constructor in the new-expression keeps allocation failure on the early exit path; exact match verified; names and types await human review. */
extern "C" void FUN_001017dc(void *);
extern "C" void FUN_00056cac(void *);
extern "C" void FUN_00101748(void *,void *);
extern "C" void FUN_001016c0(void *,void *);
extern "C" char DAT_003b0a68;
extern "C" char DAT_002cc260;
struct Object_fbee4 {
  char pad0[0x30];
  int at30;
  char pad34[0x4c];
  int at80;
  char pad84[0x3c];
  unsigned value;
  char padc4[0xc];
  Object_fbee4(unsigned v) {
    FUN_001017dc(this);
    FUN_00056cac(&at30);
    *(void **)this = &DAT_003b0a68;
    ((unsigned *)this)[0x1c] = 0;
    ((unsigned *)this)[0x1d] = 0xffffffff;
    ((unsigned *)this)[0x1e] = 0x3f800000;
    ((unsigned *)this)[0x1f] = 0x3f800000;
    FUN_00056cac(&at80);
    value = v;
    FUN_00101748(this,&DAT_002cc260);
    FUN_001016c0((char *)this + 0x80,&DAT_002cc260);
  }
};
extern "C" Object_fbee4 *FUN_00101620(unsigned, unsigned value, unsigned char *out) {
  *out = 0;
  return new Object_fbee4(value);
}
