/* HSTMATCH module=EBOOT.BIN start=0x001018d0 end=0x0010192c symbol=FUN_001018d0 lang=c99 */

extern char DAT_002d8ab4[];
void FUN_001006b0(char *);

typedef void (*Method)(int *);

void FUN_001018d0(int *p)
{
  if (p[2] == 0) {
    FUN_001006b0(DAT_002d8ab4);
  }
  (*(Method *)(*p + 0x3c))(p);
}
// NEAR 17/23 words (0x001018d0). The two statements are right (the p[2]==0 "Cast data is empty"
// log, then the virtual call at vtable+0x3c). Retail's 32-byte frame and its 4-word copy from
// sp+0x20..0x2c down to sp+0..0xc are a varargs home-area forward: the call passes p in a0 and
// re-homes the caller's a1-a3 for a variadic callee, keeping the object in t4. Declaring the
// function `(int *p, ...)` gives a 64-byte frame with an a1-a3 spill to 0x24..0x3c instead
// (24 words), so that is not the shape either; left for a later pass.
// near miss from lane fm5 (unreviewed)
