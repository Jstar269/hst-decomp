/* HSTMATCH module=hstp_trans_main.prx start=0x00275a88 end=0x00275bc8 symbol=FUN_00275a88 lang=c++ */
/* Clone of src/eboot/check_entries_00264c0c.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ with typed structs, three-flag test with int locals loaded before the first branch (matching idiom: int locals, a uchar local re-normalises with andi), early returns instead of the nested ifs, loop bound as `two ? 2 : 4` with a bool hoisted before the loop, array of four 0x458-byte entries indexed by the loop counter; exact match verified; names and types await human review. */
struct G { char pad[0x190]; int f190; };
struct Mgr;
extern "C" {
extern G *DAT_003e1e04;
extern int FUN_000c0ef8(G *);
extern int FUN_00293668(Mgr *);
extern int FUN_00297314(Mgr *);
}

struct Ent {
  unsigned char f0;
  char pad[0x26 - 1];
  unsigned char f26;
  unsigned char f27;
  char pad2[0x458 - 0x28];
};

struct Mgr {
  char pad[0x1ba8];
  Ent ents[4];
};



struct Obj {
  char pad[0x640];
  Mgr *f640;
  unsigned char f644;
};

extern "C" int FUN_00275a88(Obj *self)
{
  Mgr *m = self->f640;
  bool b = false;
  bool a = false;
  int i;
  if (DAT_003e1e04 != 0 && FUN_000c0ef8(DAT_003e1e04) != 0) {
    a = true;
  }
  if (a) {
    int cap = DAT_003e1e04->f190;
    if (cap >= FUN_00293668(m)) {
      b = true;
    }
  }
  if (!b) return 0;
  if (FUN_00297314(self->f640) == 0) return 0;
  bool two = self->f644 != 0;
  for (i = 0; i < (two ? 2 : 4); i++) {
    Ent *e = &self->f640->ents[i];
    int x = e->f26;
    int y = e->f27;
    int z = e->f0;
    if (z != 0) {
      if (x == 0) return 0;
    } else {
      if (x == 0 || y == 0) return 0;
    }
  }
  return 1;
}
