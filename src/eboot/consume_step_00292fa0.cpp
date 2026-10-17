/* HSTMATCH module=EBOOT.BIN start=0x00292fa0 end=0x002930a0 symbol=FUN_00292fa0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
  char pad0[8];
  float f8;
  char pad1[0x38 - 0xc];
  float f38;
  float f3c;
  char pad2[0x48 - 0x40];
  int f48;
  unsigned char f4c;
  unsigned char f4d;
  char pad3[0x54 - 0x4e];
  unsigned char f54;
};

extern float DAT_002ffb88;

static inline void Consume(Obj *o, float step)
{
  float r = o->f8;
  if (r < 0.0f) return;
  if (r > 0.0f) {
    float d = step;
    if (r < step) d = r;
    o->f8 = o->f8 - d;
    o->f38 = o->f38 + d;
    o->f3c = d;
  } else {
    o->f8 = 0.0f;
  }
}

extern "C" void FUN_00292fa0(Obj *o)
{
  if (o->f4d != 0 && o->f4c == 0) {
    if (o->f48 == 1) {
      Consume(o, DAT_002ffb88);
    } else {
      Consume(o, o->f54 != 0 ? 2.0f : 1.0f);
    }
  }
}
