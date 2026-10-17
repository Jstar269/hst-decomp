/* HSTMATCH module=EBOOT.BIN start=0x001b5354 end=0x001b53ec symbol=FUN_001b5354 lang=c99 */
extern int DAT_00340284;
extern int DAT_0034179c;
extern int FUN_000487c8(void);
extern void FUN_001b23c0(int *, int);
extern unsigned int FUN_002b79e8(void);
void FUN_001b5354(char *self)
{
  int result;
  unsigned char mode;
  unsigned char next;
  unsigned char old;
  FUN_000487c8();
  mode = (unsigned char)FUN_002b79e8();
  if ((mode & 0x20) != 0) {
    result = FUN_000487c8();
  } else {
    result = FUN_000487c8() != 0;
    if (result == 0)
      goto fallback;
    goto compare;
  fallback:
    result = (*(int *)(DAT_00340284 + 0x120) >= 0);
  }
compare:
  next = (unsigned char)result;
  old = *(volatile unsigned char *)(self + 0x48);
  if (old == next)
    return;
  *(volatile unsigned char *)(self + 0x48) = next;
  FUN_001b23c0(&DAT_0034179c, *(volatile unsigned char *)(self + 0x48));
}
// Near miss: 2 words differ at +0x48; retail uses bnez v1 with nop, this source yields bnezl v1 with an andi delay slot.
// Label shaping, byte temporaries, and volatile field access preserved the remaining output but did not change this branch form.
// near miss from lane cx2 (unreviewed)
