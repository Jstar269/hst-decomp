/* HSTMATCH module=hstp_trans_main.prx start=0x00111aa4 end=0x00111b58 symbol=FUN_00111aa4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int DAT_0037ffec;

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

extern "C" void FUN_00111aa4(Obj *o, int x, int mode)
{
  int t = Clamp(x, DAT_0037ffec, o->f_e4 - o->f_e0);
  if (o->f_dc != t || mode == 1) {
    o->f_d0 = (o->tab[o->f_dc].s0 != o->tab[t].s0) ? 3 : 0;
    o->f_ea = 1;
  }
  o->f_dc = t;
  if (mode == 2) {
    o->f_114 = 1;
  }
}
