/* HSTMATCH module=EBOOT.BIN start=0x00199e0c end=0x00199f78 symbol=FUN_00199e0c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj58 { virtual void d0(); virtual void v1(int); };
struct Obj54 { virtual void d0(); virtual void v1(int); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void v10();
  char pad[0x118]; short a; short b; };
struct Obj { char pad[0x54]; Obj54 *o54; Obj58 *o58; int f5c; };

extern int DAT_002cfc8c;
extern int DAT_003417a4;
extern char DAT_002e1a54[];
extern char DAT_002e1a60[];
extern char DAT_002e1a70[];
extern "C" void FUN_0001dfe8(int, int);
extern "C" void FUN_0001e23c(int, int, int);
extern "C" void FUN_000ffb3c(void *, int);
extern "C" void *FUN_001026b8(Obj58 *, char *);
extern "C" void FUN_0010b8cc(Obj54 *, int, int);
extern "C" void FUN_00199f78(Obj *);

extern "C" void FUN_00199e0c(Obj *p)
{
  p->f5c = 0;
  FUN_0001dfe8(DAT_002cfc8c, 0x2000);
  FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
  p->o58->v1(0);
  FUN_000ffb3c(FUN_001026b8(p->o58, DAT_002e1a54), 0);
  FUN_000ffb3c(FUN_001026b8(p->o58, DAT_002e1a60), 1);
  FUN_000ffb3c(FUN_001026b8(p->o58, DAT_002e1a70), 1);
  if (DAT_003417a4 - 2U < 2) {
    FUN_000ffb3c(FUN_001026b8(p->o58, DAT_002e1a54), 1);
    FUN_000ffb3c(FUN_001026b8(p->o58, DAT_002e1a60), 0);
    FUN_000ffb3c(FUN_001026b8(p->o58, DAT_002e1a70), 1);
  }
  p->o54->v1(0);
  p->o54->v10();
  Obj54 *q = p->o54;
  q->a = -12;
  q->b = 0;
  FUN_0010b8cc(p->o54, 0, 2);
  FUN_00199f78(p);
}
