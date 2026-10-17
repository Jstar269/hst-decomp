/* HSTMATCH module=hstp_trans_main.prx start=0x000f7974 end=0x000f7a98 symbol=FUN_000f7974 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Steps a value (+0x78) toward its target (+0x7c) by +0x80 per call, clamped through an inline Clamp(v, lo, hi) taking lo/hi by const reference (the lower bound is the global 0x37e6b0, hence its double load), forwards the new value to 0x116fd4 unless the hold flag (+0x6c) is set, counts the step (+0x70) and notifies 0x108a2c. Names provisional. */
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
extern "C" int DAT_0037e6b0;
extern "C" void FUN_00108a2c(Obj *);
extern "C" void FUN_00116fd4(int, int);

inline int Clamp(int v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_000f7974(Obj *o)
{
  if (o->active != 0 && o->rate > 0.0f) {
    if (o->cur < o->target) {
      o->cur = Clamp(o->cur + o->step, DAT_0037e6b0, o->target);
      if (o->hold == 0) FUN_00116fd4(o->handle, o->cur);
    } else if (o->target < o->cur) {
      o->cur = Clamp(o->cur - o->step, o->target, o->cur);
      if (o->hold == 0) FUN_00116fd4(o->handle, o->cur);
    }
    o->count++;
    FUN_00108a2c(o);
  }
}
