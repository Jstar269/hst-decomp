/* HSTMATCH module=hstp_trans_main.prx start=0x00136840 end=0x001368dc symbol=FUN_00136840 lang=c99 */
/* Clone of src/eboot/FUN_0012b3d4.c (hstclone.py tag c015707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
  char pad000[0x354];
  int f354;
  char pad358[4];
  void *f35c;
};
extern int DAT_003e4884;
extern int DAT_003e488c;
extern int FUN_00136b98(struct Obj *self, void *p, int n);
extern void FUN_001361c0(struct Obj *self, void *addr, int a, float f, int b,
                         void *p, int c);

void FUN_00136840(struct Obj *self, void *p)
{
  if (FUN_00136b98(self, self->f35c, 5) == 0)
    FUN_001361c0(self, (void *)(DAT_003e4884 + self->f354), 1, -1.0f, 0, p, 1);
  else
    FUN_001361c0(self, (void *)DAT_003e488c, 1, -1.0f, 0, p, 1);
}
