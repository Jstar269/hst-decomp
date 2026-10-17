/* HSTMATCH module=EBOOT.BIN start=0x0010b8cc end=0x0010b980 symbol=FUN_0010b8cc lang=c++ */
/* Clone of src/sharing_main/set_clamped_index_00111aa4.cpp (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int DAT_002d9218;

struct Rec {
  short s0;
  char pad[10];
};

struct Obj {
  char pad0[0xd0];
  int f_d0;
  char pad1[8];
  int f_dc;
  int f_e0;
  int f_e4;
  char pad2[2];
  unsigned char f_ea;
  char pad3[0x114 - 0xeb];
  unsigned char f_114;
  char pad4[0x120 - 0x115];
  Rec *tab;
};

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_0010b8cc(Obj *o, int x, int mode)
{
  int t = Clamp(x, DAT_002d9218, o->f_e4 - o->f_e0);
  if (o->f_dc != t || mode == 1) {
    o->f_d0 = (o->tab[o->f_dc].s0 != o->tab[t].s0) ? 3 : 0;
    o->f_ea = 1;
  }
  o->f_dc = t;
  if (mode == 2) {
    o->f_114 = 1;
  }
}
