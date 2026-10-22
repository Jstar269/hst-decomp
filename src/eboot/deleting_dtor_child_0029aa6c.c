/* HSTMATCH module=EBOOT.BIN start=0x0029aa6c end=0x0029ab94 symbol=FUN_0029aa6c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_00309e64[];
extern unsigned int DAT_0034b328;
extern void FUN_00000a00(void *);
extern void FUN_000104e0(void *);
extern void FUN_0001f0f0(void *, int);
extern void FUN_0029a5b0();
extern void FUN_0029a830();
extern void FUN_0029ab94(void *, int);

struct Child
{
  unsigned char f0;
  unsigned char pad[0xb];
  void *fc;
  void *f10;
  void *f14;
  void *f18;
  void *f1c;
};

struct Parent
{
  void *vptr;
  unsigned char pad[0x38];
  struct Child *child;
};

void *FUN_0029aa6c(struct Parent *self, short flag)
{
  if (self != 0)
  {
  self->vptr = DAT_00309e64;
  DAT_0034b328 = 0;
  struct Child *c = self->child;
  if (c != 0)
  {
    if (c != 0)
    {
    if (c->f1c != 0)
    {
      FUN_000104e0(c->f1c);
      c->f1c = 0;
    }
    if (c->f18 != 0)
    {
      FUN_00000a00(c->f18);
      c->f18 = 0;
    }
    if (c->f14 != 0)
    {
      FUN_00000a00(c->f14);
      c->f14 = 0;
    }
    if (c->f10 != 0)
    {
      FUN_00000a00(c->f10);
      c->f10 = 0;
    }
    if (c->fc != 0)
    {
      FUN_0029ab94(c->fc, 1);
      c->fc = 0;
    }
    if (c->f0 != 0)
    {
      c->f0 = 0;
      FUN_0029a830();
      FUN_0029a5b0();
    }
    FUN_00000a00(c);
    }
    self->child = 0;
  }
  FUN_0001f0f0(self, 0);
  if (flag > 0)
    FUN_00000a00(self);
  }
  return self;
}
