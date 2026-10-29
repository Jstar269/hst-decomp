/* HSTMATCH module=EBOOT.BIN start=0x00236890 end=0x00236ce4 symbol=FUN_00236890 lang=c++ */
typedef unsigned char uchar;
struct Vec4 {
/* PARKED NEAR: 276/277 words, 98 differ. Everything up to the char[15] member copy at 0x10c matches,including
   all six FUN_00236ce4 sub-object calls and the s2 base-pointer pattern (d = self->sub; ...; d = self->sub + 0x18; ...),
   and the three Vec4 members at 0x1c/0x2c/0x3c that make mwcc batch four lwc1 then four swc1.
   Remaining: the char[15] copy loop colours (retail a1=src, a0=dst, v1=counter; ours a2/a1/a0) and the later
   int[24] copy at 0x160, so every following word is shifted by one. Ruled out: separate Post assignment, nested
   Head struct, pointer-arithmetic destination, explicit src pointer local (that one costs s3 and a 32-byte frame).
   This is the same colour-cascade wall the lane documents for generated copies; calls and branches agree. */
  float x, y, z, w;
};
struct Pre {
  int m000;
  char m04[16];
  float m014;
  float m018;
  Vec4 v01c;
  Vec4 v02c;
  Vec4 v03c;
  short m04c;
  short m04e;
  float m050;
  int m054;
  float m058;
  float m05c;
  short m60[9];
  float m074;
  float m078;
  float m07c;
  float m080;
  float m084;
  int m088;
  float m08c;
  float m090;
  int m094;
  float m098;
  float m09c;
  float m0a0;
  float m0a4;
  short m0a8;
  short m0aa;
  short m0ac;
  short m0ae;
  float m0b0;
  float m0b4;
  float m0b8;
  char m0bc;
  char m0bd;
  char m0be;
  char m0bf;
  char m0c0;
  char m0c1;
  char m0c2;
  char m0c3;
};

struct Post {
  char m10c[15];
  float m11c;
  float m120;
  float m124;
  float m128;
  Vec4 v12c;
  float m13c;
  float m140;
  float m144;
  float m148;
  float m14c;
  float m150;
  float m154;
  char m158;
  char m159;
  float m15c;
  int m160[24];
  float m1c0;
  float m1c4;
  float m1c8;
  float m1cc;
  float m1d0;
  float m1d4;
  float m1d8;
  float m1dc;
  float m1e0;
  float m1e4;
  char m1e8;
  float m1ec;
  float m1f0;
  float m1f4;
  float m1f8;
  float m1fc;
  float m200;
  float m204;
  float m208;
  float m20c;
  float m210;
  float m214;
  float m218;
  float m21c;
  float m220;
  uchar m224;
  uchar m225;
  uchar m226;
  uchar m227;
  uchar m228;
  uchar m229;
  uchar m22a;
  uchar m22b;
  uchar m22c;
};

struct Big {
  Pre pre;
  char sub[0x48];
  Post post;
};

extern "C" void FUN_00236ce4(void *dst, const void *src);

extern "C" void FUN_00236890(Big *self, const Big *o)
{
  self->pre = o->pre;
  char *d = self->sub;
  FUN_00236ce4(d + 0x00, o->sub + 0x00);
  FUN_00236ce4(d + 0x0c, o->sub + 0x0c);
  d = self->sub + 0x18;
  FUN_00236ce4(d + 0x00, o->sub + 0x18);
  FUN_00236ce4(d + 0x0c, o->sub + 0x24);
  d = self->sub + 0x30;
  FUN_00236ce4(d + 0x00, o->sub + 0x30);
  FUN_00236ce4(d + 0x0c, o->sub + 0x3c);
  self->post = o->post;
}
// near miss from lane dsn3 (unreviewed)
