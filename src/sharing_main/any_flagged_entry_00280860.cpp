/* HSTMATCH module=hstp_trans_main.prx start=0x00280860 end=0x002809d8 symbol=FUN_00280860 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Twin of EBOOT 0x26f820. Returns 1 when any 48-byte entry of the vector selected by kind (4: +0x90, 1: +0xb4,
   2: +0xa8, 3: +0xc0; the vectors processed by the neighbouring FUN_002809d8) has its flag byte +0 set, else 0.
   The int index compared with the unsigned size() keeps retail's loop: index * 48 recomputed and the bound re-read
   every pass (an unsigned index, or the size field read directly, lets MWCC keep the size in a register). The flag
   test goes through an inline bool predicate (the materialised sltu/xori without andi). All four scans fall out to
   one shared `return 0`; MWCC fills only the first branch to it (Ghidra's separate `return 0` for kind 4 is that
   filled slot). Names provisional. */
struct Elem {
  unsigned char f0;
  char pad1[0x2f];
  bool IsClear() const { return !f0; }
};
struct Vec {
  Elem *data;
  unsigned n;
  unsigned size() const { return n; }
  Elem &operator[](unsigned i) { return data[i]; }
};
struct Obj {
  char pad[0x90];
  Vec v90;
  char pad98[0x10];
  Vec va8;
  char padb0[4];
  Vec vb4;
  char padbc[4];
  Vec vc0;
};

extern "C" int FUN_00280860(Obj *self, int kind)
{
  if (kind == 4) {
    for (int i = 0; i < self->v90.size(); i++)
      if (!self->v90[i].IsClear()) return 1;
  } else if (kind == 1) {
    for (int i = 0; i < self->vb4.size(); i++)
      if (!self->vb4[i].IsClear()) return 1;
  } else if (kind == 2) {
    for (int i = 0; i < self->va8.size(); i++)
      if (!self->va8[i].IsClear()) return 1;
  } else if (kind == 3) {
    for (int i = 0; i < self->vc0.size(); i++)
      if (!self->vc0[i].IsClear()) return 1;
  }
  return 0;
}
