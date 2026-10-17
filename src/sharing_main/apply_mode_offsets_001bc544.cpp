/* HSTMATCH module=hstp_trans_main.prx start=0x001bc544 end=0x001bc66c symbol=FUN_001bc544 lang=c++ */
/* Clone of src/eboot/apply_mode_offsets_001aee6c.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: both mode tests are switches (case 0/case 4 sharing a body, default else/return), typed structs with the info sub-object addressed through a pointer, shared pointer loads; exact match verified; names and types await human review. */
struct Tgt { char pad[0x60]; float v; };
struct Q { char pad[0x24]; int a; int b; };
struct Info { Q *p; int val; };
struct Sh { char pad[4]; short s4; char pad2[2]; short s8; };
struct A {
  char pad0[0x1c];
  Tgt *t;
  char pad1[0x28c - 0x20];
  Info info;
  char pad2[0x3b8 - 0x294];
  Sh *sh;
};
struct B {
  char pad0[0x1c];
  Tgt *t1;
  char pad1[0x28 - 0x20];
  Tgt *t2;
};
struct S { int pad; A *a; B *b; };
struct G {
  char pad0[0x11c];
  unsigned char mode;
  char pad1[0x34c - 0x11d];
  int f34c;
};
extern "C" G *FUN_001aa91c();
extern "C" void FUN_00108558(Tgt *);

extern "C" void FUN_001bc544(S *s)
{
  A *a = s->a;
  unsigned char m = FUN_001aa91c()->mode;
  Info *i = &a->info;
  switch (m) {
  case 0:
  case 4: {
    int n = i->val;
    Q *q = i->p;
    q->a = n;
    q->b = n;
    break;
  }
  default: {
    int n = i->val + 1;
    Q *q = i->p;
    q->a = n;
    q->b = n;
  }
  }
  if (FUN_001aa91c()->f34c == 2) {
    a->t->v = 63.0f;
    FUN_00108558(a->t);
    Sh *sh = a->sh;
    sh->s4 = sh->s4 - 0x3f;
    sh->s8 = sh->s8 - 0x3f;
  }
  B *b = s->b;
  switch (FUN_001aa91c()->mode) {
  case 0:
  case 4:
    break;
  default:
    return;
  }
  b->t1->v = b->t1->v + 6.0f;
  FUN_00108558(b->t1);
  b->t2->v = b->t2->v - 6.0f;
  FUN_00108558(b->t2);
}
