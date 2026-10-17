/* HSTMATCH module=EBOOT.BIN start=0x000f22ac end=0x000f23d0 symbol=FUN_000f22ac lang=c++ */
/* Clone of src/sharing_main/step_toward_target_000f7974.cpp (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Steps a value (+0x78) toward its target (+0x7c) by +0x80 per call, clamped through an inline Clamp(v, lo, hi) taking lo/hi by const reference (the lower bound is the global 0x2d78d8, hence its double load), forwards the new value to 0x116fd4 unless the hold flag (+0x6c) is set, counts the step (+0x70) and notifies 0x108a2c. Names provisional. */
struct Obj {
  char pad0[0x68];
  int handle;            /* 0x68 */
  unsigned char hold;    /* 0x6c */
  char pad1[3];
  int count;             /* 0x70 */
  float rate;            /* 0x74 */
  int cur;               /* 0x78 */
  int target;            /* 0x7c */
  int step;              /* 0x80 */
  unsigned char active;  /* 0x84 */
};
extern "C" int DAT_002d78d8;
extern "C" void FUN_00103128(Obj *);
extern "C" void FUN_0010f5d4(int, int);

inline int Clamp(int v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_000f22ac(Obj *o)
{
  if (o->active != 0 && o->rate > 0.0f) {
    if (o->cur < o->target) {
      o->cur = Clamp(o->cur + o->step, DAT_002d78d8, o->target);
      if (o->hold == 0) FUN_0010f5d4(o->handle, o->cur);
    } else if (o->target < o->cur) {
      o->cur = Clamp(o->cur - o->step, o->target, o->cur);
      if (o->hold == 0) FUN_0010f5d4(o->handle, o->cur);
    }
    o->count++;
    FUN_00103128(o);
  }
}
