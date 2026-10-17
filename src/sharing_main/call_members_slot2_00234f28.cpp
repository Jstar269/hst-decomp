/* HSTMATCH module=hstp_trans_main.prx start=0x00234f28 end=0x00235024 symbol=FUN_00234f28 lang=c++ */
/* Clone of src/eboot/call_members_slot2_002259b4.cpp (hstclone.py tag c034907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls virtual slot 2 (vtable +0x10) on the objects (+0, +4, +8, +0xc, +0x10, +0x18..+0x24) held in the context at +0x3c (the first pair only when the +0x28 member's kind is 11, otherwise FUN_0022a228 on it), then FUN_000fc270 on the word at +0x30. */
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
extern "C" void FUN_0022a228(Sub40 *);
extern "C" void FUN_000fc270(int);

extern "C" void FUN_00234f28(Obj *o)
{
  Ctx *c = o->ctx;
  if (c->m10->kind != 11) {
    FUN_0022a228(c->m10);
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
  FUN_000fc270(c->f30);
}
