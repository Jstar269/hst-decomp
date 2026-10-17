/* HSTMATCH module=EBOOT.BIN start=0x0018aa0c end=0x0018ab04 symbol=FUN_0018aa0c lang=c++ */
/* Clone of src/sharing_main/state_set_switch_00197158.cpp (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sub {
  virtual void s0();
  virtual void s1(int on);
  char pad[0x60];
  float f64;
};

struct Obj {
  char pad0[0x54];
  int state;
  int f58;
  int f5c;
  int f60;
  int f64;
  char pad68[4];
  unsigned char b6c;
  char pad6d[4];
  unsigned char b71;
  char pad72[6];
  Sub *p78;
  Sub *p7c;
  Sub *p80;
  char pad84[4];
  float f88;
  float f8c;
  float f90;
};

extern "C" void FUN_0018aa0c(Obj *o, int s)
{
  o->state = s;
  o->b71 = 0;
  switch (o->state) {
  case 0:
    o->f58 = 0;
    break;
  case 1:
    o->p78->s1(0);
    o->p7c->s1(0);
    o->f58 = 0;
    o->f5c = 0;
    o->f60 = 0;
    o->f64 = 0;
    o->b6c = 0;
    o->p78->f64 = o->f88;
    o->p7c->f64 = o->f8c;
    o->p80->f64 = o->f90;
    break;
  case 2:
    break;
  case 3:
  case 4:
    o->p78->s1(1);
    o->p7c->s1(1);
    o->f58 = 0;
    break;
  }
}
