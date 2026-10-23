/* HSTMATCH module=EBOOT.BIN start=0x0019dc20 end=0x0019dd0c symbol=FUN_0019dc20 lang=c99 */

struct Obj { char pad[4]; short *f4; char pad2[0x10 - 8]; char body; };

extern char DAT_002e1b68[];
void FUN_000149a8(void *, ...);
unsigned char *FUN_00193474(int);

void FUN_0019dc20(struct Obj *self, int x, short p3, short p4, short p5, short p6, short p7,
                  unsigned char p8, unsigned int p9, int p10, int p11)
{
  unsigned char *rec;
  int off;

  if (self->f4 != 0) {
    self->f4[0] = (short)x;
    self->f4[1] = p3;
    self->f4[2] = p4;
    self->f4[3] = p5;
    self->f4[4] = p6;
    self->f4[5] = p7;
    off = p10 * 3;
    *(char *)((char *)self->f4 + off + 0x7d) = p8;
    *(char *)((char *)self->f4 + 0x7c) = p9;
  }
  if (p11 != 0) {
    FUN_000149a8((char *)self + 0x10);
  } else {
    FUN_000149a8((char *)self + 0x10, DAT_002e1b68);
  }
  if (x >= 0 && x < 0xf) {
    rec = FUN_00193474(x);
    *((char *)self->f4 + 0xe) = 3;
    *((char *)self->f4 + 0xc) = rec[0xc];
    *((char *)self->f4 + 0xd) = rec[0xd];
  }
}
// NEAR 10/59 words (0x0019dc20). Signature and body match: 11 params (the 9th read as a word, the
// 10th used as a *3 byte index, the 11th selecting the two FUN_000149a8 calls), all six `sh` field
// stores through repeated `self->f4` reloads, the +0x7d/+0x7c byte stores, and the 0..14 range check
// with FUN_00193474 filling f4[0xe]=3, f4[0xc], f4[0xd].
// FIXED this session: `FUN_00193474` returns `unsigned char *` (was `char *`) - that is what turns
// retail's `lbu a0,12(v0)` / `lbu a0,13(v0)` into place (two words).
// Left: pure colouring - retail keeps the running offset 3*p10 in v0 and loads the base pointer into
// a0 for each store, ours keeps the offset in a0 and the base in v0; the 9th parameter likewise
// comes out in v0 instead of retail's a1. Tried: a local `int off`, the inline expression, `3 * p10`
// and `p10 * 3` (all identical).
// near miss from lane fm5 (unreviewed)
