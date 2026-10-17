/* HSTMATCH module=EBOOT.BIN start=0x000673fc end=0x0006744c symbol=FUN_000673fc lang=c++ */
/* Clone of src/sharing_main/timer_expire_virtual_00068850.cpp (hstclone.py tag s10170158a1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3(int);
  int pad[2];
  float timer;
};

extern "C" void FUN_000673fc(float dt, Obj *o)
{
  if (o->timer > 0.0f) {
    o->timer = o->timer - dt;
    if (o->timer <= 0.0f) {
      o->s3(0);
    }
  }
}
