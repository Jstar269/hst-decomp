/* HSTMATCH module=EBOOT.BIN start=0x00063a30 end=0x00063b20 symbol=FUN_00063a30 lang=c99 */
typedef unsigned int uint;
typedef struct { float x; float y; float z; float w; } Vec4;
typedef struct { uint x; uint y; uint z; uint w; } UInt4;

extern int FUN_00063a0c(void);
extern void FUN_00063554(Vec4 *, char *);
extern void FUN_0004c644(Vec4 *, const Vec4 *);
extern void FUN_000513a0(uint, int);

void FUN_00063a30(char *self, int count, float param_2)
{
  Vec4 transformed;
  UInt4 identity;
  Vec4 input;
  Vec4 *source;

  identity.w = 0x3f800000;
  identity.x = 0;
  identity.y = 0;
  identity.z = 0;

  if (FUN_00063a0c() != 0) {
    source = (Vec4 *)&identity;
  } else {
    FUN_00063554(&input, self);
    source = &input;
  }
  FUN_0004c644(&transformed, source);

  *(float *)(self + 0x20) = transformed.x;
  *(float *)(self + 0x24) = transformed.y;
  *(float *)(self + 0x28) = transformed.z;
  *(float *)(self + 0x2c) = transformed.w;

  *(uint *)(self + 0x30) = 0;
  *(uint *)(self + 0x34) = 0;
  *(uint *)(self + 0x38) = 0;
  *(uint *)(self + 0x3c) = 0;

  *(float *)(self + 8) = (float)count;
  *(float *)(self + 0xc) = (float)count;
  *(uint *)(self + 0x10) = 0xbf800000;

  FUN_000513a0(*(uint *)(self + 4), 0);

  *(unsigned char *)(self + 0x40) = 0;
  *(unsigned char *)(self + 0x41) = 0;
  *(uint *)(self + 0x44) = 0x457a0000;
  *(unsigned char *)(self + 0x50) = 0;
  *(unsigned char *)(self + 0x51) = 0;
  *(unsigned char *)(self + 0x52) = 1;
  *(unsigned char *)(self + 0x53) = 1;
  *(float *)(self + 0x54) = param_2;
}

// lane sx4: 3 of 60 words differ (+0x18..+0x20), EBOOT twin of the Sharing 0x648f4 near miss; whole body matches retail incl. colours (s1=self, s0=count, f20=param_2).
// Only the prologue move order differs: ours move s1,a0 / move s0,a1 / mov.s f20,f12; retail move s0,a1 / mov.s f20,f12 / move s1,a0.
// Ruled out (sx4): param copies via locals in the four orders (count/param_2/self), declaring them after each other.
// near miss from lane sx4 (unreviewed)
