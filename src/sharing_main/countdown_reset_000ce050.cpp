/* HSTMATCH module=hstp_trans_main.prx start=0x000ce050 end=0x000ce1cc symbol=FUN_000ce050 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Countdown field at +0x1b0; when it reaches zero and no slot in [lo, hi] (stride 0x34, float at +0x10c) is
   non-zero the object is reset through four helpers; with the counter already zero a non-zero slot triggers
   0x59e58 and returns 1. Matching idiom: the loop bound is read through the trivial getter Last() (a plain
   `hi` member is hoisted out of the loop, retail reloads it every pass). Names provisional. */
struct Obj;
extern "C" void FUN_0005fe20(Obj *o, int a, float f);
extern "C" unsigned char FUN_000587ac(Obj *o, int a, int b, float f);
extern "C" void FUN_00059ba8(Obj *o, int a, float f);
extern "C" void FUN_00059d68(Obj *o, int a);
extern "C" void FUN_00059e58(Obj *o);

struct Obj {
  char pad0[0x80];
  float f80;
  char pad84[0x40];
  float fc4;
  char padc8[8];
  float fd0;
  char padd4[0x30];
  float f104;
  char pad108[0x50];
  int lo;      // 0x158
  int hi;      // 0x15c
  char pad160[0x50];
  int cnt;     // 0x1b0

  int Last() const { return hi; }
  bool AnyActive() {
    for (int i = lo; i <= Last(); i++) {
      if (*(float *)((char *)this + i * 0x34 + 0x10c) != 0.0f) return true;
    }
    return false;
  }
};

extern "C" int FUN_000ce050(Obj *o)
{
  if (o->cnt > 0) {
    o->cnt = o->cnt - 1;
    if (o->cnt == 0) {
      if (!o->AnyActive()) {
        o->cnt = 0;
        FUN_0005fe20(o, 0, 0.0f);
        FUN_000587ac(o, 0, 0, 0.0f);
        o->fc4 = 1.0f;
        FUN_00059ba8(o, -1, 1.0f);
        o->fc4 = 1.0f;
        o->fd0 = 1.0f;
        FUN_00059d68(o, -1);
      }
    }
    return 0;
  }
  if (o->AnyActive()) {
    FUN_00059e58(o);
    o->f80 = o->f104;
    return 1;
  }
  return 0;
}
