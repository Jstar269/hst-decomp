/* HSTMATCH module=hstp_trans_main.prx start=0x001222a4 end=0x00122338 symbol=FUN_001222a4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: both switches list the empty cases 0/1 (old state) and 3 (new state) explicitly; MWCC tests labels in reverse source order. */
extern void FUN_00121f3c();

struct Obj_001222a4 {
  char pad00[0x3c];
  int state;
  unsigned char f40;
  char pad41[0xb];
  unsigned char f4c;
  char pad4d[3];
  int f50;
  unsigned char f54;
  char pad55[3];
  int f58;
  int f5c;
  int f60;
  int f64;
  char pad68[4];
  int f6c;
};

void FUN_001222a4(struct Obj_001222a4 *self, int state)
{
  switch (self->state) {
  case 0:
    break;
  case 1:
    break;
  case 3:
    self->f4c = 0;
    break;
  }
  self->state = state;
  switch (state) {
  case 0:
    FUN_00121f3c();
    break;
  case 1:
    self->f4c = 0;
    self->f50 = 0;
    self->f54 = 0;
    self->f58 = 0;
    self->f5c = -1;
    self->f60 = -1;
    self->f64 = -1;
    self->f6c = -1;
    self->f40 = 0;
    break;
  case 3:
    break;
  }
}
