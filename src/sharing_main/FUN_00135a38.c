/* HSTMATCH module=hstp_trans_main.prx start=0x00135a38 end=0x00135b04 symbol=FUN_00135a38 lang=c99 rodata=0x002d18bc */
/* Clone of src/eboot/FUN_0012a5cc.c (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad[0x190];
  int state;
  char pad1[0x32d - 0x194];
  unsigned char f32d;
  char pad2[0x330 - 0x32e];
  int f330;
} Obj;

extern int FUN_00136cd4(Obj *self);
extern void FUN_000954d4(Obj *self, float f);
extern void FUN_00095bec(Obj *self);
extern void FUN_0013671c(Obj *self, int a, int b, float f);
extern void FUN_001354c4(Obj *self, int a, int b, int c);

void FUN_00135a38(Obj *self)
{
  if (FUN_00136cd4(self) == 0)
    return;
  switch (self->state) {
  case 0:
    if (self->f330 > 0) {
      self->f330--;
      FUN_000954d4(self, 0.0f);
      FUN_00095bec(self);
    } else if (self->f32d == 0) {
      FUN_0013671c(self, 1, 1, -1.0f);
    }
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xd:
    FUN_001354c4(self, 0, -1, 0);
    FUN_00095bec(self);
  }
}
