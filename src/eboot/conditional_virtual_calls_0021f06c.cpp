/* HSTMATCH module=EBOOT.BIN start=0x0021f06c end=0x0021f0f8 symbol=FUN_0021f06c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Handler { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); };
struct Obj {
    char pad000[0x16c];
    Handler *extra;       /* 0x16c optional second handler */
    char pad170[4];
    Handler sub;          /* 0x174 embedded handler (vtable only) */
    char pad178[0x1d8 - 0x178];
    float unk1d8;         /* 0x1d8 */
    char pad1dc[0x1e4 - 0x1dc];
    unsigned char unk1e4; /* 0x1e4 non-zero: nothing to do */
    char pad1e5[3];
    int unk1e8;           /* 0x1e8 */
    char pad1ec[0x208 - 0x1ec];
    unsigned char unk208; /* 0x208 */
};
extern "C" void FUN_001031e8();
/* Conditionally run FUN_001031e8, then call slot 3 of the embedded handler (when unk1e8 >= 0) and of the extra one. */
extern "C" void FUN_0021f06c(Obj *self)
{
  if (self->unk1e4 != 0) return;
  if (!(self->unk1d8 > 0.0f)) return;
  if (self->unk208 == 0) return;
  FUN_001031e8();
  if (self->unk1e8 >= 0) {
    self->sub.m3();
  }
  Handler *p = self->extra;
  if (p != 0) p->m3();
}
