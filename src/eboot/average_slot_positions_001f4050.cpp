/* HSTMATCH module=EBOOT.BIN start=0x001f4050 end=0x001f41e8 symbol=FUN_001f4050 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ with Vec4/Mat4 (user ctor) views, the four DAT floats are one extern const Vec4 copied as a unit (retail's pipelined copy), the three sums and the count initialised before it, the translation floats read into locals declared z,y,x but assigned x,y,z before the first-iteration test (matching idiom: it decouples the f1..f3 numbering from the load order), the count kept as a float local for the three divides, and the flag passed as unsigned char (flag != 0) ^ 1; exact match verified; names and types await human review. */
struct Vec4 { float x, y, z, w; Vec4() {} };
struct Mat4 { Vec4 r[4]; };
struct Sub { char pad[0x50]; Vec4 pos; };
struct Slot { char pad[0x58]; Sub *sub; };
struct Obj {
  char pad0[0x3a0];
  Slot *slots[4];
  int ids[4];
  char pad3b0[0x521 - 0x3b0 - 16];
  unsigned char f521;
  char pad522[0x584 - 0x522];
  void *f584;
};
extern const Vec4 DAT_002bc430;
extern char DAT_002ee8d0[];
extern "C" void FUN_0005548c(Mat4 *out, Sub *sub, const char *name);
extern "C" void FUN_001ed4a8(void *a, Vec4 *avg, Vec4 *pos, unsigned char flag);
extern "C" void FUN_001f37e4(Obj *o, Slot *s, int id, int idx, int a, int b);

extern "C" void FUN_001f4050(Obj *param_1)
{
  float sumx;
  float sumy;
  float sumz;
  Vec4 avg;
  Vec4 pos;
  Mat4 m;
  int count;
  int i;

  sumx = 0.0f;
  sumy = 0.0f;
  sumz = 0.0f;
  avg.x = 0.0f;
  avg.y = 0.0f;
  avg.z = 0.0f;
  avg.w = 0.0f;
  pos = DAT_002bc430;
  count = 0;
  for (i = 0; i < 4; i++) {
    Slot *s = param_1->slots[i];
    Sub *sub = s ? s->sub : 0;
    if (sub != 0) {
      if (param_1->f521 != 0) {
        FUN_001f37e4(param_1, s, param_1->ids[i], i, 6, 0);
      }
      FUN_0005548c(&m, sub, DAT_002ee8d0);
      float tz;
      float ty;
      float tx;
      tx = m.r[3].x;
      ty = m.r[3].y;
      tz = m.r[3].z;
      if (count == 0) {
        pos.x = sub->pos.x;
        pos.y = sub->pos.y;
        pos.z = sub->pos.z;
        pos.w = sub->pos.w;
      }
      sumx = sumx + tx;
      count = count + 1;
      sumy = sumy + ty;
      sumz = sumz + tz;
    }
  }
  float n = (float)count;
  avg.w = 1.0f;
  avg.x = sumx / n;
  avg.y = sumy / n;
  avg.z = sumz / n;
  FUN_001ed4a8(param_1->f584, &avg, &pos, (param_1->f521 != 0) ^ 1);
}
