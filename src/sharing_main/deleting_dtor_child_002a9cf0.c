/* HSTMATCH module=hstp_trans_main.prx start=0x002a9cf0 end=0x002a9e18 symbol=FUN_002a9cf0 lang=c99 */
/* Clone of src/eboot/deleting_dtor_child_0029aa6c.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_003b3130[];
extern unsigned int DAT_003f4668;
extern void FUN_00000a00(void *);
extern void FUN_000104e0(void *);
extern void FUN_0001ed28(void *, int);
extern void FUN_002a9834();
extern void FUN_002a9ab4();
extern void FUN_002a9e18(void *, int);

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

void *FUN_002a9cf0(struct Parent *self, short flag)
{
  if (self != 0)
  {
  self->vptr = DAT_003b3130;
  DAT_003f4668 = 0;
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
      FUN_002a9e18(c->fc, 1);
      c->fc = 0;
    }
    if (c->f0 != 0)
    {
      c->f0 = 0;
      FUN_002a9ab4();
      FUN_002a9834();
    }
    FUN_00000a00(c);
    }
    self->child = 0;
  }
  FUN_0001ed28(self, 0);
  if (flag > 0)
    FUN_00000a00(self);
  }
  return self;
}
