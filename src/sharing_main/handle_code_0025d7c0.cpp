/* HSTMATCH module=hstp_trans_main.prx start=0x0025d7c0 end=0x0025da10 symbol=FUN_0025d7c0 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/handle_code_0024d5b8.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Switch on a small code (a1) for the object at a0; always returns 0. Codes 0xe/0x16 set +0x208 = -1, force +0x3c to 1,
   copy the Vec4 at +0x210 to +0x230 and call FUN_00055be8; code 8 calls FUN_0025bc70 and bumps +0x240 (unless the global
   state at +0x3c is 7); code 0xc may set the flag byte at +0x268 (and DAT_003f3aa8) depending on the state word at +0x20c
   and an LCG draw; the other listed codes do nothing. Case labels are written in the reverse of
   retail's test order (tests run 0x13,0x12,0x15,0xd,0xc,0x14,0xb,0xa,9,8,0xe,0x16,1,0). Matching idioms: the first read
   of +0x20c goes through an inline getter State() while the later tests read the field directly (retail reloads it on
   BOTH paths; a cached local or two direct reads are CSE'd), and the early exit inside case 0xc is a `break`, not a
   `return 0` (one shared epilogue with `move v0,zero` after the restores). Names provisional. */
struct Vec4 { float x, y, z, w; };
struct Game { char pad[0x3c]; int unk3c; };
struct Rng { char pad[0x1360]; int seed; };

/* Linear congruential generator step and the chance (percent) of setting the flag at +0x268. */
#define RNG_MUL 0x343fd
#define RNG_ADD 0x269ec3
#define FLAG_CHANCE_PERCENT 80

struct Cfg { char pad[0xa0]; unsigned unka0; };
struct Sub50 { char b[0x1b8]; };
struct Self {
  char pad0[0x3c];
  int unk3c;
  char pad40[0x50 - 0x40];
  Sub50 sub50;
  int unk208;
  int unk20c; /* state word */
  int State() const { return unk20c; }
  Vec4 vec210;
  Vec4 vec220;
  Vec4 vec230;
  int unk240;
  char pad244[4];
  unsigned char unk248;
  char pad249[0x268 - 0x249];
  unsigned char unk268;
};
extern "C" {
extern Game *DAT_003e19f0;
extern Cfg *DAT_003e1e84;
extern Rng *DAT_003e95e0;
extern unsigned char DAT_003f3aa8;
void FUN_00055be8(Sub50 *, Vec4 *);
void FUN_0025bc70(Self *, Vec4 *, Vec4 *);
}

extern "C" int FUN_0025d7c0(Self *self, int code)
{
  switch (code) {
  case 0:
  case 1:
    break;
  case 0x16:
  case 0xe:
    self->unk208 = -1;
    if (self->unk3c != 1) {
      self->unk3c = 1;
      self->unk248 = 1;
    }
    self->vec230 = self->vec210;
    FUN_00055be8(&self->sub50, &self->vec210);
    DAT_003f3aa8 = 0;
    break;
  case 8:
    if (DAT_003e19f0->unk3c != 7) {
      if (self->unk3c != 1) {
        self->unk3c = 1;
        self->unk248 = 1;
      }
      FUN_0025bc70(self, &self->vec210, &self->vec220);
      self->unk240++;
    }
    DAT_003f3aa8 = 0;
    break;
  case 9:
  case 10:
  case 11:
  case 0x14:
    break;
  case 0xc: {
    int state = self->State();
    if (state == 1 || (unsigned)(state - 11) < 2) {
      if (DAT_003e1e84->unka0 < 2) {
        if (state == 11) {
          int seed = DAT_003e95e0->seed * RNG_MUL + RNG_ADD;
          DAT_003e95e0->seed = seed;
          if (((seed >> 16) & 0x7fff) % 100 < FLAG_CHANCE_PERCENT) {
            self->unk268 = 1;
            DAT_003f3aa8 = 1;
            break;
          }
        }
        if (self->unk20c == 12 && DAT_003f3aa8 == 0) {
          self->unk268 = 1;
        } else if (self->unk20c == 1) {
          self->unk268 = 1;
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
