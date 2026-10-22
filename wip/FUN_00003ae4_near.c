/* HSTMATCH module=EBOOT.BIN start=0x00003ae4 end=0x00003b30 symbol=FUN_00003ae4 lang=c99 */
/* NEAR MISS: 17/19 words. Still open: retail keeps the argument and the base-constructor result in two
   saved registers (s0/s1) and reloads a1 late; the candidate reuses one register. */
extern void *FUN_00002ad4(void *);
extern void FUN_00002a64(void *, void *);
extern char DAT_00306f40[];

typedef struct {
  void *vptr;
} Head;

Head *FUN_00003ae4(void *self, void *arg)
{
  Head *p = (Head *)FUN_00002ad4(self);
  p->vptr = DAT_00306f40;
  FUN_00002a64((char *)p + 4, arg);
  return p;
}
// near miss from lane km1 (unreviewed)
