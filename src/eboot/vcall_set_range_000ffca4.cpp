/* HSTMATCH module=EBOOT.BIN start=0x000ffca4 end=0x000ffcfc symbol=FUN_000ffca4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC {
  virtual void d0();
  virtual void d1();
  virtual void d2();
  virtual void d3();
  virtual short m4(int);
  virtual short m5(int);
};
struct S {
  int pad0;
  short a, b, c, d;
  int pad1[4];
  VC *obj;
  int pad2;
  int arg;
};
extern "C" void FUN_000ffca4(S *s)
{
  s->a = 0;
  s->b = 0;
  s->c = s->obj->m4(s->arg);
  s->d = s->obj->m5(s->arg);
}
