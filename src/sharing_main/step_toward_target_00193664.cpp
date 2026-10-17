/* HSTMATCH module=hstp_trans_main.prx start=0x00193664 end=0x00193708 symbol=FUN_00193664 lang=c++ */
/* Clone of src/eboot/step_toward_target_00186f18.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed struct, step held in a non-const float local (value-first add.s), min(step, |target-start|) as a single-sided if, separate locals for the clamp and the sign flip; exact match verified; names and types await human review. */
struct Tgt { char pad[0x60]; float v; };
struct Obj {
  char pad0[0x28];
  Tgt *tgt;
  char pad1[0x1240 - 0x2c];
  int start;
  int target;
  float pos;
  int cnt;
  unsigned char active;
};
extern "C" void FUN_00108558(Tgt *);

extern "C" void FUN_00193664(Obj *o)
{
  if (o->active != 0) {
    o->cnt = o->cnt + 1;
    float step = 15.0f;
    float f = o->pos + step;
    o->pos = f;
    int s = (int)f;
    int t = o->target;
    int d = t - o->start;
    if (d < 0) d = -d;
    int m = s;
    if (d <= s) {
      m = d;
      o->active = 0;
    }
    int base = o->start;
    if (o->target - base < 0) m = -m;
    o->tgt->v = (float)(base + m);
    FUN_00108558(o->tgt);
  }
}
