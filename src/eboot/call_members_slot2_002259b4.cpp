/* HSTMATCH module=EBOOT.BIN start=0x002259b4 end=0x00225ab0 symbol=FUN_002259b4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls virtual slot 2 (vtable +0x10) on the objects (+0, +4, +8, +0xc, +0x10, +0x18..+0x24) held in the context at +0x3c (the first pair only when the +0x28 member's kind is 11, otherwise FUN_0021acb4 on it), then FUN_000f6b7c on the word at +0x30. */
struct VC {
  virtual void s0();
  virtual void s1();
  virtual void s2();
};
struct Sub40 {
  int f0;
  int kind;
};
struct Ctx {
  VC *m0;
  VC *m1;
  VC *m2;
  VC *m3;
  VC *m4;
  int f14;
  VC *m6;
  VC *m7;
  VC *m8;
  VC *m9;
  Sub40 *m10;
  int f2c;
  int f30;
};
struct Obj {
  char pad[0x3c];
  Ctx *ctx;
};
extern "C" void FUN_0021acb4(Sub40 *);
extern "C" void FUN_000f6b7c(int);

extern "C" void FUN_002259b4(Obj *o)
{
  Ctx *c = o->ctx;
  if (c->m10->kind != 11) {
    FUN_0021acb4(c->m10);
  } else {
    c->m0->s2();
    c->m1->s2();
  }
  c->m2->s2();
  c->m3->s2();
  c->m4->s2();
  c->m6->s2();
  c->m7->s2();
  c->m8->s2();
  c->m9->s2();
  FUN_000f6b7c(c->f30);
}
