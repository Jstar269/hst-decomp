/* HSTMATCH module=hstp_trans_main.prx start=0x000f6c38 end=0x000f6e24 symbol=FUN_000f6c38 lang=c++ */
/* Clone of src/eboot/three_digit_items_set_000f1570.cpp (hstclone.py tag s10170158a4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls virtual slot 1 on the two objects of the side array at +0x54 (arguments 0 and 1) and on the object at +0x60, stores the value, then for each decimal digit of the three-digit value (hundreds, tens, units) either sets the words at +0x24/+0x28 of the matching item to digit + a per-side table entry or, for a leading zero, calls 0xffb3c on the item. Matching idioms: the sum is its own local stored twice (no reload after the first store), computed before the item pointer is read; the digits live in an address-taken int[3]. */
struct VC {
  virtual void s0();
  virtual void s1(int);
};
struct Item {
  char pad[0x24];
  int f24;
  int f28;
};
struct Obj {
  char pad0[0x54];
  VC *w[2];
  char pad1[4];
  VC *f60;
  Item *d[2];
  Item *e[2];
  Item *g[2];
  char pad2[0x30];
  int fac;
  float fb0;
  int fb4;
};
extern int DAT_0037e48c[];
extern int DAT_0037e4a4[];
extern int DAT_0037e4bc[];
extern "C" void FUN_00105470(Item *, int);

extern "C" void FUN_000f6c38(Obj *self, int value, unsigned side)
{
  self->w[side]->s1(0);
  self->w[side ^ 1]->s1(1);
  self->f60->s1(1);
  self->fac = 0;
  self->fb0 = 1.0f;
  self->fb4 = value;
  int digit[3] = {0};
  digit[0] = (value / 100) % 10;
  digit[1] = (value / 10) % 10;
  digit[2] = value % 10;
  if (digit[0] != 0) {
    int base = DAT_0037e48c[side * 3];
    int v = digit[0] + base;
    Item *it = self->d[side];
    it->f24 = v;
    it->f28 = v;
  } else {
    FUN_00105470(self->d[side], 1);
  }
  if (digit[1] != 0 || digit[0] != 0) {
    int base = DAT_0037e4a4[side * 3];
    int v = digit[1] + base;
    Item *it = self->e[side];
    it->f24 = v;
    it->f28 = v;
  } else {
    FUN_00105470(self->e[side], 1);
  }
  int base = DAT_0037e4bc[side * 3];
  int v = digit[2] + base;
  Item *it = self->g[side];
  it->f24 = v;
  it->f28 = v;
}
