/* HSTMATCH module=EBOOT.BIN start=0x0006ab24 end=0x0006abcc symbol=FUN_0006ab24 lang=c99 */
/* NEAR MISS: 42/42 words, 11 differ (prologue scheduling only). Still open: retail hoists the first step
   of the n*432 strength reduction above the register saves and keeps n in a1 until the call setup. */
typedef unsigned int uint;

extern void *FUN_00000a90(uint);
extern void *FUN_000008d8(void *, void *, void *, uint, uint);
extern void FUN_00056b98(void);
extern void FUN_00056cb0(void);

typedef struct {
  uint count;
  void *f4;
  char *f8;
} Self;

void FUN_0006ab24(Self *self, uint n)
{
  uint size = n * 432 + 16;
  self->count = n;
  self->f4 = FUN_000008d8(FUN_00000a90(size), (void *)FUN_00056b98, (void *)FUN_00056cb0, 432, n);
  self->f8 = FUN_00000a90(self->count);
  {
    uint i;
    for (i = 0; i < self->count; i++) {
      self->f8[i] = 0;
    }
  }
}
// near miss from lane km1 (unreviewed)
