/* HSTMATCH module=EBOOT.BIN start=0x001a4760 end=0x001a47a0 symbol=FUN_001a4760 lang=c99 */
/* Clone of src/sharing_main/map_mode_to_field_001b1d2c.c (hstclone.py tag c034920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad[0x2e4];
  int f2e4;
} Obj;

void FUN_001a4760(Obj *self, int mode)
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
