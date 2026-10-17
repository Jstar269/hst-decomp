/* HSTMATCH module=hstp_trans_main.prx start=0x001b1d2c end=0x001b1d6c symbol=FUN_001b1d2c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad[0x2e4];
  int f2e4;
} Obj;

void FUN_001b1d2c(Obj *self, int mode)
{
  switch (mode) {
  case 1:
    self->f2e4 = 0;
    break;
  case 3:
    self->f2e4 = 1;
    break;
  case 5:
    self->f2e4 = 2;
    break;
  default:
    self->f2e4 = 0;
    break;
  }
}
