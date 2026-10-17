/* HSTMATCH module=hstp_trans_main.prx start=0x002a45ac end=0x002a46ac symbol=FUN_002a45ac lang=c++ */
/* Clone of src/eboot/consume_step_00292fa0.cpp (hstclone.py tag s10170158a1r2s): addresses substituted; exact match verified; names and types await human review. */
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

extern float DAT_003a8a94;

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

extern "C" void FUN_002a45ac(Obj *o)
{
  if (o->f4d != 0 && o->f4c == 0) {
    if (o->f48 == 1) {
      Consume(o, DAT_003a8a94);
    } else {
      Consume(o, o->f54 != 0 ? 2.0f : 1.0f);
    }
  }
}
