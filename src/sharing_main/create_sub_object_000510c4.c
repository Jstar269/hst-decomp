/* HSTMATCH module=hstp_trans_main.prx start=0x000510c4 end=0x00051138 symbol=FUN_000510c4 lang=c99 */
/* Clone of src/eboot/create_sub_object_000507b0.c (hstclone.py tag c072507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); names and types await human review. */

extern char DAT_003769ac[];

extern void *FUN_0003a0b0(void *self);
extern void *FUN_0003cb18(void *p);
extern void FUN_0003cb28(void *slot, void *p);
extern void FUN_0004efe0(char *msg);
extern int FUN_0005121c(void *self);

int FUN_000510c4(char *self)
{
  void *p;

  p = FUN_0003a0b0(self);
  *(void **)(self + 0x1a00c) = p;
  if (!p) {
    FUN_0004efe0(DAT_003769ac);
    for (;;) {
    }
  }
  p = FUN_0003cb18(p);
  *(int *)p = 0xcb000000;
  FUN_0003cb28(*(void **)(self + 0x1a00c), (char *)p + 4);
  return FUN_0005121c(self);
}
