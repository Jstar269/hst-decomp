/* HSTMATCH module=EBOOT.BIN start=0x00151d68 end=0x00151eb4 symbol=FUN_00151d68 lang=c99 */

struct Obj { char pad[8]; int f8; int fc; int f10; };

extern unsigned char DAT_003402f0;
extern int *DAT_0034a118;
extern char DAT_002dc5e0[];
void FUN_0014d044(int *);
void FUN_0014fd94(char *, int, int, int);
int *FUN_0014c384(int, int);

int FUN_00151d68(struct Obj *self, int *param_2)
{
  int i;
  unsigned char v;
  int key;

  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94(DAT_002dc5e0, self->f8, self->fc, self->f10);
  }
  i = self->fc;
  key = *param_2;
  switch (i) {
  case 1:
    v = self->f10 == *(int *)(*(int *)((char *)DAT_0034a118 + 0x54) + 0x1b4);
    break;
  case 2:
    v = self->f10 == *(int *)(*(int *)((char *)DAT_0034a118 + 0x58) + 0x1b4);
    break;
  case 3: {
    unsigned char b1;
    unsigned char b2;

    b1 = 0;
    if (*(int *)((char *)DAT_0034a118 + 0x5c) != 0 &&
        self->f10 == *(int *)(*(int *)((char *)DAT_0034a118 + 0x5c) + 0x1b4)) {
      b1 = 1;
    }
    if (b1) {
      v = 1;
    } else {
      b2 = 0;
      if (*(int *)((char *)DAT_0034a118 + 0x60) != 0 &&
          self->f10 == *(int *)(*(int *)((char *)DAT_0034a118 + 0x60) + 0x1b4)) {
        b2 = 1;
      }
      v = b2;
    }
    break;
  }
  default:
    v = 0;
    break;
  }
  *(int *)FUN_0014c384(key, self->f8) = v;
  return 0;
}
// NEAR 65/83 words (0x00151d68). Sibling of the exact 0x00151acc: same debug block, same hoisted
// `key = *param_2`, same `*(int *)FUN_0014c384(key, self->f8) = v;` tail, and the same descending
// switch chain (3,2,1 with the 0 default) once the cases are written ascending.
// What differs: retail stores v as a byte through TWO conversions (`andi a1,a3,0xff` inside the
// bnezl delay and a second `andi s1,a1,0xff` before the store) and keeps the constant 1 in a3 from
// the start of case 3, so its case-3 body carries both bool accumulators (a2 for the 0x5c slot, a1
// for the 0x60 slot). Ours converts once. Tried: `unsigned char v` alone (65), the two-`b1`/`b2`
// nested form Ghidra shows (75), and the single `if (a || b) v = 1;` form (70, worst).
// near miss from lane fm5 (unreviewed)
