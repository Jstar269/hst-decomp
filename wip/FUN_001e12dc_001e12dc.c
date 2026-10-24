/* HSTMATCH module=EBOOT.BIN start=0x001e12dc end=0x001e1614 symbol=FUN_001e12dc lang=c99 */
/* MEASURED 191/206 words, 202 differ, first diff +0x0 (hstmatch, this build).
   RANGE CORRECTION RETRACTED: end=0x001e15d8 was WRONG. Retail's prologue at 0x1e12dc is
   `27bdfff0 addiu sp,sp,-16` with ra@12, s2@8, s1@4, s0@0 -- a 16-byte frame and no s3.
   The 0x1e15fc epilogue restores exactly those offsets, so 0x1e15d8..0x1e1610 is this same
   function's last DEL site, not the next function. The "different frame" I saw was OUR
   epilogue (`lw ra,28(sp)`, s3@24, `addiu sp,sp,32`): our source carries one unused s3 local
   and a frame twice retail's. Real defect: frame 32 vs 16, and 15 words still absent.
   0x1e14cc..0x1e15b0: five DEL(p,off) sites (0x1958,0x195c,0x1d64,0x1954,0x25b8); retail
   zeroes the field in the beqzl delay AND again after the virtual call (DEL does both). */
typedef unsigned int undefined4;
typedef int code();

extern undefined4 DAT_0034a130;
extern void FUN_000009e4();

#define DEL(p, off)                                              \
  {                                                              \
    int *q_ = *(int **)((char *)(p) + (off));                    \
    if (q_ != (int *)0x0) {                                      \
      *(undefined4 *)((char *)(p) + (off)) = 0;                  \
      (**(code **)(*q_ + 8))(q_, 1);                             \
      *(undefined4 *)((char *)(p) + (off)) = 0;                  \
    }                                                            \
  }

void FUN_001e12dc(int param_1)
{
  int iVar3;

  DEL(param_1, 0x40);
  DEL(param_1, 0x3c);
  DEL(param_1, 0xd4);
  DEL(param_1, 500);
  if (DAT_0034a130 != 0) {
    FUN_000009e4();
    DAT_0034a130 = 0;
  }
  DEL(param_1, 0x9b4);
  DEL(param_1, 0x810);
  DEL(param_1, 0x175c);
  DEL(param_1, 0x1d68);
  DEL(param_1, 0x21e4);
  DEL(param_1, 0x235c);
  DEL(param_1, 0x2464);
  DEL(param_1, 0x250c);
  for (iVar3 = 0; iVar3 < 0x15; iVar3++) {
    DEL(param_1, iVar3 * 4 + 0x1adc);
  }
  DEL(param_1, 0x1958);
  DEL(param_1, 0x195c);
  DEL(param_1, 0x1d64);
  DEL(param_1, 0x1954);
  DEL(param_1, 0x25b8);
  return;
}
// near miss from lane fm10 (unreviewed)
