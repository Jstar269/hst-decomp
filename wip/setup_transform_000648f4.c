/* HSTMATCH module=hstp_trans_main.prx start=0x000648f4 end=0x000649e4 symbol=FUN_000648f4 lang=c99 */
/* WIP near miss: 60/60 words, 3 differ (+0x18, +0x1c, +0x20).
   The entire body (57 words) matches retail exactly, including register colors:
   s1 = self, s0 = count, $f20 = param_2.
   The only difference is the prologue move order:
   ours:   move s1, a0; move s0, a1; mov.s $f20, $f12
   retail: move s0, a1; mov.s $f20, $f12; move s1, a0
   Tried: declaration order variations, type-converted locals (as in sibling 0x649e4),
   register keywords, signed/unsigned permutations, and C++ member functions.
*/

typedef unsigned int uint;
typedef struct { float x; float y; float z; float w; } Vec4;
typedef struct { uint x; uint y; uint z; uint w; } UInt4;

extern int FUN_000648d0(void);
extern void FUN_00064418(Vec4 *, char *);
extern Vec4 FUN_0004c898(const Vec4 *);
extern void FUN_00051d40(uint, int);

void FUN_000648f4(char *self, int count, float param_2)
{
  Vec4 transformed;
  UInt4 identity;
  Vec4 input;
  Vec4 *source;

  identity.w = 0x3f800000;
  identity.x = 0;
  identity.y = 0;
  identity.z = 0;

  if (FUN_000648d0() != 0) {
    source = (Vec4 *)&identity;
  } else {
    FUN_00064418(&input, self);
    source = &input;
  }
  transformed = FUN_0004c898(source);

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

  FUN_00051d40(*(uint *)(self + 4), 0);

  *(unsigned char *)(self + 0x40) = 0;
  *(unsigned char *)(self + 0x41) = 0;
  *(uint *)(self + 0x44) = 0x457a0000;
  *(unsigned char *)(self + 0x50) = 0;
  *(unsigned char *)(self + 0x51) = 0;
  *(unsigned char *)(self + 0x52) = 1;
  *(unsigned char *)(self + 0x53) = 1;
  *(float *)(self + 0x54) = param_2;
}
// near miss from lane ag6 (unreviewed)
