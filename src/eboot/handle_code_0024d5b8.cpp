/* HSTMATCH module=EBOOT.BIN start=0x0024d5b8 end=0x0024d808 symbol=FUN_0024d5b8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Switch on a small code (a1) for the object at a0; always returns 0. Codes 0xe/0x16 set +0x208 = -1, force +0x3c to 1,
   copy the Vec4 at +0x210 to +0x230 and call FUN_000550c8; code 8 calls FUN_0024ba68 and bumps +0x240 (unless the global
   state at +0x3c is 7); code 0xc may set the flag byte at +0x268 (and DAT_0034a778) depending on the state word at +0x20c
   and an LCG draw; the other listed codes do nothing. Case labels are written in the reverse of
   retail's test order (tests run 0x13,0x12,0x15,0xd,0xc,0x14,0xb,0xa,9,8,0xe,0x16,1,0). Matching idioms: the first read
   of +0x20c goes through an inline getter State() while the later tests read the field directly (retail reloads it on
   BOTH paths; a cached local or two direct reads are CSE'd), and the early exit inside case 0xc is a `break`, not a
   `return 0` (one shared epilogue with `move v0,zero` after the restores). Names provisional. */
struct Vec4 { float x, y, z, w; };
struct Game { char pad[0x3c]; int f3c; };
struct Rng { char pad[0x1360]; int seed; };
struct Cfg { char pad[0xa0]; unsigned fa0; };
struct Sub50 { char b[0x1b8]; };
struct Self {
  char pad0[0x3c];
  int f3c;
  char pad40[0x50 - 0x40];
  Sub50 sub50;
  int f208;
  int f20c;
  int State() const { return f20c; }
  Vec4 v210;
  Vec4 v220;
  Vec4 v230;
  int f240;
  char pad244[4];
  unsigned char b248;
  char pad249[0x268 - 0x249];
  unsigned char b268;
};
extern "C" {
extern Game *DAT_003386b0;
extern Cfg *DAT_00338b44;
extern Rng *DAT_003402a0;
extern unsigned char DAT_0034a778;
void FUN_000550c8(Sub50 *, Vec4 *);
void FUN_0024ba68(Self *, Vec4 *, Vec4 *);
}

extern "C" int FUN_0024d5b8(Self *self, int msg)
{
  switch (msg) {
  case 0:
  case 1:
    break;
  case 0x16:
  case 0xe:
    self->f208 = -1;
    if (self->f3c != 1) {
      self->f3c = 1;
      self->b248 = 1;
    }
    self->v230 = self->v210;
    FUN_000550c8(&self->sub50, &self->v210);
    DAT_0034a778 = 0;
    break;
  case 8:
    if (DAT_003386b0->f3c != 7) {
      if (self->f3c != 1) {
        self->f3c = 1;
        self->b248 = 1;
      }
      FUN_0024ba68(self, &self->v210, &self->v220);
      self->f240++;
    }
    DAT_0034a778 = 0;
    break;
  case 9:
  case 10:
  case 11:
  case 0x14:
    break;
  case 0xc: {
    int s = self->State();
    if (s == 1 || (unsigned)(s - 11) < 2) {
      if (DAT_00338b44->fa0 < 2) {
        if (s == 11) {
          int seed = DAT_003402a0->seed * 0x343fd + 0x269ec3;
          DAT_003402a0->seed = seed;
          if (((seed >> 16) & 0x7fff) % 100 < 80) {
            self->b268 = 1;
            DAT_0034a778 = 1;
            break;
          }
        }
        if (self->f20c == 12 && DAT_0034a778 == 0) {
          self->b268 = 1;
        } else if (self->f20c == 1) {
          self->b268 = 1;
        }
      }
    }
    break;
  }
  case 0xd:
  case 0x15:
  case 0x12:
  case 0x13:
    break;
  }
  return 0;
}
