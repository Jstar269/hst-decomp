/* HSTMATCH module=hstp_trans_main.prx start=0x00068850 end=0x000688a0 symbol=FUN_00068850 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3(int);
  int pad[2];
  float timer;
};

extern "C" void FUN_00068850(float dt, Obj *o)
{
  if (o->timer > 0.0f) {
    o->timer = o->timer - dt;
    if (o->timer <= 0.0f) {
      o->s3(0);
    }
  }
}
