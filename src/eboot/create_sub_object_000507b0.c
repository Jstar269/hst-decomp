/* HSTMATCH module=EBOOT.BIN start=0x000507b0 end=0x00050824 symbol=FUN_000507b0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); names and types await human review. */

extern char DAT_002d0e90[];

extern void *FUN_0003a088(void *self);
extern void *FUN_0003caf0(void *p);
extern void FUN_0003cb00(void *slot, void *p);
extern void FUN_0004ea98(char *msg);
extern int FUN_00050908(void *self);

typedef struct Owner {
  char pad00[0x1a00c];
  void *block;      /* 0x1a00c block created by FUN_0003a088 */
} Owner;

/* Creates the owner's block (reports an error and hangs when that fails), writes 0xcb000000 into the item FUN_0003caf0 returns and registers the following address. */
int FUN_000507b0(Owner *self)
{
  void *p;

  p = FUN_0003a088(self);
  self->block = p;
  if (!p) {
    FUN_0004ea98(DAT_002d0e90);
    for (;;) {
    }
  }
  p = FUN_0003caf0(p);
  *(int *)p = 0xcb000000;
  FUN_0003cb00(self->block, (char *)p + 4);
  return FUN_00050908(self);
}
