/* HSTMATCH module=EBOOT.BIN start=0x002932b8 end=0x002933fc symbol=FUN_002932b8 lang=c++ */
/* Clone of src/sharing_main/apply_mode_002a48c4.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Mode 5 re-initialises the DAT_00331b88 object (FUN_00063d08(obj, (int)DAT_002ffb8c, 65535.0f, 300000.0f)); any
   other mode calls virtual slot 1 and resets the state bytes, then a mode 0..6 picks the table entry and the f44 flag.
   The flag switch lists its labels ascending (retail tests 4, 3, 2, 1, 0) with ONE shared `case 0: case 1:` body:
   separate bodies are both threaded into likely slots (3 words short). */
struct Obj {
  virtual void v0();
  virtual void v1();
  char pad4[0x14 - 4];
  int f14;
  int arr[7];
  char pad34[0x38 - 0x34];
  float f38;
  char pad3c[0x40 - 0x3c];
  unsigned char f40;
  unsigned char f41;
  char pad42[2];
  int f44;
  int f48;
  unsigned char f4c;
  unsigned char f4d;
  char pad4e[2];
  float f50;
  unsigned char f54;
};
struct Ctx {
  char pad[0xc];
  int f0c;
  char pad10[0x52 - 0x10];
  unsigned char f52;
};
extern "C" {
extern Ctx *DAT_00331b88;
extern float DAT_002ffb8c;
extern void FUN_00063d08(Ctx *c, int n, float a, float b);
}
extern "C" void FUN_002932b8(Obj *o, int mode, float f)
{
  if (mode == 5) {
    FUN_00063d08(DAT_00331b88, (int)DAT_002ffb8c, 65535.0f, 300000.0f);
  } else {
    o->v1();
    o->f40 = 1;
    o->f41 = 0;
    o->f38 = 31.0f;
    o->f4c = 0;
    o->f4d = 1;
    o->f50 = f;
    o->f54 = 0;
    if (mode == 4)
      o->f54 = 1;
    if (mode >= 0 && mode < 7) {
      o->f14 = o->arr[mode];
      o->f48 = mode;
      switch (mode) {
      case 0:
      case 1:
        o->f44 = 0;
        break;
      case 2:
      case 3:
      case 4:
        o->f44 = 1;
        break;
      }
    }
    Ctx *c = DAT_00331b88;
    c->f0c = 0;
    c->f52 = 0;
  }
}
