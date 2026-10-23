/* HSTMATCH module=EBOOT.BIN start=0x0010f394 end=0x0010f5d4 symbol=FUN_0010f394 lang=c++ */
extern int DAT_002d9210;

extern "C" void FUN_00101630(void *, void *, int);
extern "C" void FUN_000ffca4(void *);
extern "C" void FUN_0010f5d4(void *, int);

struct VObj {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual int Get(unsigned int);
};

struct Rec {
  int f00;
  int f04;
  int f08;
  int f0c;
  short f10;
  short f12;
  short f14;
  short f16;
  short f18;
  short pad;
  int f1c;
  int f20;
};

struct In {
  int f00;
  int f04;
  int f08;
  int f0c;
  short f10;
  short f12;
  short f14;
  short f16;
  short f18;
  short f1a;
  int f1c;
};

struct Obj {
  char pad0[4];
  VObj **list;
  char pad1[8];
  int **f10;
  char pad2[0x60 - 0x14];
  float f60;
  float f64;
  char pad3[0xfc - 0x68];
  int ffc;
  unsigned int f100;
  int f104;
  int f108;
  int f10c;
  int f110;
  char pad4[0x11c - 0x114];
  int f11c;
  int f120;
  int f124;
  int f12c;
};

extern "C" void FUN_0010f394(Obj *self, In *in, int count)
{
  Rec recs[10];
  short s5;
  short s6;
  unsigned int u13;
  int i12;
  int u11;
  int u10;
  short s1;
  short s2;
  short u3;
  unsigned int n;
  short s;
  short half;
  short y;
  int i;
  short q;

  s5 = in->f10;
  s6 = in->f14;
  u13 = in->f00;
  i12 = in->f08;
  u11 = in->f0c;
  u10 = in->f1c;
  s1 = in->f12;
  s2 = in->f16;
  u3 = in->f18;

  self->f60 = (float)s5;
  self->f64 = (float)s1;
  self->f10c = (short)(s6 - s5);
  self->f110 = (short)(s2 - s1);

  y = 0;
  n = self->list[i12]->Get(u11) & 0xffff;
  self->f100 = n;
  s = (short)(self->f10c - n * count);
  if (s <= 0) {
    if (count >= 2) {
      self->f100 = n + s / (count - 1);
      self->f108 = 0;
    } else {
      self->f108 = 0;
    }
  } else {
    q = s / (short)count;
    self->f108 = q;
    half = (short)(q / 2);
    y = (short)(y + half);
  }
  self->f104 = self->f110;
  i = 0;
  if (count > 0) {
    do {
      recs[i].f00 = u13;
      recs[i].f04 = 0;
      recs[i].f08 = i12;
      recs[i].f0c = u11;
      recs[i].f10 = (short)(y + self->f100 * i);
      recs[i].f12 = 0;
      recs[i].f14 = (short)(self->f100 + recs[i].f10);
      recs[i].f16 = (short)(self->f104 + recs[i].f12);
      recs[i].f18 = u3;
      recs[i].f1c = u10;
      recs[i].f20 = (int)&DAT_002d9210;
      i++;
    } while (i < count);
  }
  FUN_00101630(self, recs, count);
  self->f12c = *(short *)(*self->f10 + 1);
  FUN_000ffca4(*self->f10);
  i = (*self->f10)[9];
  self->ffc = i;
  self->f11c = i + 10;
  self->f120 = self->ffc + 11;
  self->f124 = self->ffc + 12;
  FUN_0010f5d4(self, 0x7fffffff);
}
// NEAR MISS: 141/144 words. The overall shape, the vtable call (5th virtual at +0x18), the
// 36-byte record fill loop, the bgtzl arm layout and the tail all match; the whole tail is
// shifted 3 words because the `y += q / 2` accumulation emits one `seh` fewer than retail
// (`band`: retail has `seh v0,v0` on the half and then `addu v0,s7,v0; seh s7,v0`, while
// ours folds the two short truncations into one) and the else arm's trailing `b`+`nop`
// (retail) vs `b`+`sw` delay.
// Ruled out: half as short/int/initialised; q as short/int; y as int; explicit casts on both
// halves of the sum; declaration order of q/half/y.
// near miss from lane fm7 (unreviewed)
