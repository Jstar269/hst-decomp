/* HSTMATCH module=EBOOT.BIN start=0x00049fbc end=0x0004a080 symbol=FUN_00049fbc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rec {
  char pad[48];
  float v;
  char pad2[12];
};

struct VObj {
  virtual void *f0();
  virtual void *f1();
  virtual void *f2();
  virtual void *f3();
  virtual int *f4();
  char pad[132];
  float f88;
};

struct Obj {
  VObj *f0;
  int pad;
  int f8;
  int fC;
  int f10;
  int f14;
  int f18;
  int f1c;
};

extern float DAT_002d0814;
extern float DAT_002d0818;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (v > hi ? hi : v);
}

extern "C" float FUN_00049fbc(Obj *self)
{
  float r;
  if (self->f8 >= 0 && self->f1c >= 0) {
    VObj *obj = self->f0;
    float scale = obj->f88;
    int *rec = obj->f4();
    float val = -((Rec *)rec)[self->f1c].v;
    val = val * scale;
    r = Clamp(val, DAT_002d0814, DAT_002d0818);
  } else {
    r = 1.0f;
  }
  return r;
}
