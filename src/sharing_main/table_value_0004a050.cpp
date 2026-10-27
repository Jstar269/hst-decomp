/* HSTMATCH module=hstp_trans_main.prx start=0x0004a050 end=0x0004a110 symbol=FUN_0004a050 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/table_value_0004a080.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Sibling of FUN_00049f8c (same table, same layout): reads the signed index at +0x1c of the
   object, takes the record at that index from the array returned by the object's fifth virtual
   (the records are 0x40 bytes apart, the value sits at +0x34), negates it, scales it with the
   object's float at +0x88 and clamps the result between the two globals. */
struct Rec {
  char pad[52];
  float v;
  char pad2[8];
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

extern float DAT_0037601c;
extern float DAT_00376020;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (v > hi ? hi : v);
}

extern "C" float FUN_0004a050(Obj *self)
{
  float r;
  if (self->f8 >= 0 && self->f1c >= 0) {
    VObj *obj = self->f0;
    float scale = obj->f88;
    int *rec = obj->f4();
    float val = -((Rec *)rec)[self->f1c].v;
    val = val * scale;
    r = Clamp(val, DAT_0037601c, DAT_00376020);
  } else {
    r = 0.0f;
  }
  return r;
}
