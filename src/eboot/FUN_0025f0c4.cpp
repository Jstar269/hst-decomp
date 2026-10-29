/* HSTMATCH module=EBOOT.BIN start=0x0025f0c4 end=0x0025f1c4 symbol=FUN_0025f0c4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: inverted if/else on DAT_003417be, structured bool condition with xori, typed Obj fields; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern unsigned char DAT_003417be;
extern void FUN_000114c0(void *, int, unsigned int);
extern void FUN_0010b8cc(void *, int, int);
extern void FUN_0025346c(void *, int);
extern void FUN_0025eca0(void *);
extern void FUN_0025f1c4(void *);
}

struct VC_1 { virtual void d0(); virtual void m(int); };

struct Sub58 {
  char pad0[0xd8];
  int unkD8;
  char padDC[0x114 - 0xdc];
  unsigned char unk114;
};

struct Obj {
  char pad0[0x58];
  Sub58 *sub;          /* 0x58 */
  char pad5c[0x64 - 0x5c];
  unsigned char enabled;   /* 0x64 */
  unsigned char altFlag;   /* 0x65 */
  char pad66[0x70 - 0x66];
  VC_1 *view;          /* 0x70 */
  char pad74[0x1c4 - 0x74];
  char sub1c4[0x34];   /* 0x1c4 */
  bool unk1f8;         /* 0x1f8 */
  char pad1f9[0x2c8 - 0x1f9];
  char zeroBlock[8];   /* 0x2c8 start of a 28-byte block cleared on entry */
  int unk2d0;          /* 0x2d0 */
};

extern "C" void FUN_0025f0c4(Obj *self)
{
  FUN_000114c0(self->zeroBlock, 0, 28);
  self->unk2d0 = 1;
  FUN_0025eca0(self);
  self->unk1f8 = DAT_003417be != 0;

  int b = (self->enabled != 0) ^ 1;
  if (b == 0) {
    b = self->altFlag != 0;
  }
  FUN_0025346c(self->sub1c4, b);

  if (DAT_003417be != 0) {
    Sub58 *sub = self->sub;
    sub->unkD8 = 0;
    sub->unk114 = 1;
    FUN_0010b8cc(self->sub, 1, 0);
    self->view->m(1);
  }
  else {
    Sub58 *sub = self->sub;
    sub->unkD8 = 2;
    sub->unk114 = 1;
    FUN_0010b8cc(self->sub, 0, 0);
    self->view->m(0);
  }
  FUN_0025f1c4(self);
}
