/* HSTMATCH module=EBOOT.BIN start=0x000f1570 end=0x000f175c symbol=FUN_000f1570 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls virtual slot 1 on the two objects of the side array at +0x54 (arguments 0 and 1) and on the object at +0x60, stores the value, then for each decimal digit of the three-digit value (hundreds, tens, units) either sets the words at +0x24/+0x28 of the matching item to digit + a per-side table entry or, for a leading zero, calls 0xffb3c on the item. Matching idioms: the sum is its own local stored twice (no reload after the first store), computed before the item pointer is read; the digits live in an address-taken int[3]. */
struct VC {
  virtual void s0();
  virtual void s1(int);
};
#define DIGIT_BASE 10
#define SIDES 2

struct Item {
  char pad[0x24];
  int unk24;   /* both words receive the same digit value */
  int unk28;
};
struct Obj {
  char pad0[0x54];
  VC *w[SIDES];          /* 0x54 one per side */
  char pad1[4];
  VC *extra;             /* 0x60 */
  Item *hundreds[SIDES]; /* 0x64 digit items, one per side */
  Item *tens[SIDES];     /* 0x6c */
  Item *units[SIDES];    /* 0x74 */
  char pad2[0x30];
  int unkac;             /* 0xac */
  float unkb0;           /* 0xb0 */
  int value;             /* 0xb4 the three-digit value */
};
extern int DAT_002d76b4[];
extern int DAT_002d76cc[];
extern int DAT_002d76e4[];
extern "C" void FUN_000ffb3c(Item *, int);

/* Shows a three-digit value for one side: leading-zero digits hide their item, the others get the digit plus that side's table entry. */
extern "C" void FUN_000f1570(Obj *self, int value, unsigned side)
{
  self->w[side]->s1(0);
  self->w[side ^ 1]->s1(1);
  self->extra->s1(1);
  self->unkac = 0;
  self->unkb0 = 1.0f;
  self->value = value;
  int digit[3] = {0};
  digit[0] = (value / 100) % DIGIT_BASE;
  digit[1] = (value / 10) % DIGIT_BASE;
  digit[2] = value % DIGIT_BASE;
  if (digit[0] != 0) {
    int base = DAT_002d76b4[side * 3];
    int v = digit[0] + base;
    Item *it = self->hundreds[side];
    it->unk24 = v;
    it->unk28 = v;
  } else {
    FUN_000ffb3c(self->hundreds[side], 1);
  }
  if (digit[1] != 0 || digit[0] != 0) {
    int base = DAT_002d76cc[side * 3];
    int v = digit[1] + base;
    Item *it = self->tens[side];
    it->unk24 = v;
    it->unk28 = v;
  } else {
    FUN_000ffb3c(self->tens[side], 1);
  }
  int base = DAT_002d76e4[side * 3];
  int v = digit[2] + base;
  Item *it = self->units[side];
  it->unk24 = v;
  it->unk28 = v;
}
