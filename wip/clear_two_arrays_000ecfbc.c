/* HSTMATCH module=EBOOT.BIN start=0x000ecfbc end=0x000ed08c symbol=FUN_000ecfbc lang=c99 */
struct Self
{
  char pad0[0x58];
  char *f58;
  int f5c;
  char pad1[0x68 - 0x60];
  char *f68;
  int f6c;
};

void FUN_000ecfbc(struct Self *self)
{
  char *p;
  for (p = self->f58; p != self->f58 + self->f5c * 0x60; p += 0x60)
    *(int *)(p + 0x44) = 6;
  for (p = self->f68; p != self->f68 + self->f6c * 0x18; p += 0x18)
    *(int *)(p + 8) = 2;
}
// near miss from lane od3 (unreviewed)
