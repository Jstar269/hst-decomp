/* HSTMATCH module=EBOOT.BIN start=0x000507b0 end=0x00050824 symbol=FUN_000507b0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); names and types await human review. */

extern char DAT_002d0e90[];

extern void *FUN_0003a088(void *self);
extern void *FUN_0003caf0(void *p);
extern void FUN_0003cb00(void *slot, void *p);
extern void FUN_0004ea98(char *msg);
extern int FUN_00050908(void *self);

int FUN_000507b0(char *self)
{
  void *p;

  p = FUN_0003a088(self);
  *(void **)(self + 0x1a00c) = p;
  if (!p) {
    FUN_0004ea98(DAT_002d0e90);
    for (;;) {
    }
  }
  p = FUN_0003caf0(p);
  *(int *)p = 0xcb000000;
  FUN_0003cb00(*(void **)(self + 0x1a00c), (char *)p + 4);
  return FUN_00050908(self);
}
