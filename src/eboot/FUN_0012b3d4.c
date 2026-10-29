/* HSTMATCH module=EBOOT.BIN start=0x0012b3d4 end=0x0012b470 symbol=FUN_0012b3d4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
  char pad000[0x354];
  int f354;
  char pad358[4];
  void *f35c;
};
extern int DAT_0033b544;
extern int DAT_0033b54c;
extern int FUN_0012b72c(struct Obj *self, void *p, int n);
extern void FUN_0012ad54(struct Obj *self, void *addr, int a, float f, int b,
                         void *p, int c);

void FUN_0012b3d4(struct Obj *self, void *p)
{
  if (FUN_0012b72c(self, self->f35c, 5) == 0)
    FUN_0012ad54(self, (void *)(DAT_0033b544 + self->f354), 1, -1.0f, 0, p, 1);
  else
    FUN_0012ad54(self, (void *)DAT_0033b54c, 1, -1.0f, 0, p, 1);
}
