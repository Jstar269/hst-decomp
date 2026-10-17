/* HSTMATCH module=hstp_trans_main.prx start=0x000d3f60 end=0x000d417c symbol=FUN_000d3f60 lang=c++ */
/* Hand-written reconstruction from the disassembly (the countdown part follows src/sharing_main/countdown_reset_000ce050.cpp); exact match verified; names and types await human review. */
/* Countdown at +0x1b0 as in 0xce050; with the counter at zero and an active slot, a second inlined search over slots [lo, hi] (pointer at +0xf4 -> float at +8 against the float at +0x104) decides between the finish path (0x59ca4, 0x5ff00, return 1) and the retry path (0x5fec8, 0x59e58). The loop bound is read through the trivial getter Last() as in 0xce050. Names provisional. */
struct Obj;
extern "C" void FUN_0005fe20(Obj *o, int a, float f);
extern "C" unsigned char FUN_000587ac(Obj *o, int a, int b, float f);
extern "C" void FUN_00059ba8(Obj *o, int a, float f);
extern "C" void FUN_00059d68(Obj *o, int a);
extern "C" void FUN_00059e58(Obj *o);
extern "C" void FUN_00059ca4(Obj *o, int a);
extern "C" void FUN_0005fec8(Obj *o);
extern "C" void FUN_0005ff00(float f, Obj *o);

struct Target {
  char pad0[8];
  float f8;
};
struct Handle {
  Target *target;
};

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
  bool AllReady() {
    for (int i = lo; i <= Last(); i++) {
      Handle *h = *(Handle **)((char *)this + i * 0x34 + 0xf4);
      float t = h ? h->target->f8 : 0.0f;
      if (*(float *)((char *)this + i * 0x34 + 0x104) < t) return false;
    }
    return true;
  }
};

extern "C" int FUN_000d3f60(Obj *o)
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
    if (o->AllReady()) {
      FUN_00059ca4(o, -1);
      FUN_0005ff00(0.0f, o);
      o->fd0 = 0.0f;
      return 1;
    }
    FUN_0005fec8(o);
    FUN_00059e58(o);
    o->f80 = o->f104;
  }
  return 0;
}
