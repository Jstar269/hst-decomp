/* HSTMATCH module=hstp_trans_main.prx start=0x000d8dcc end=0x000d8e88 symbol=FUN_000d8dcc lang=c99 */
/* Hand-written reconstruction from the disassembly (matching idiom: case 8 has its own copy of the `f710 = 0` body; with 22, 14 and 8 sharing one body the 14 test becomes a plain beq to it instead of retail's beql with the store in the slot, 2 words); exact match verified; names and types await human review. */
/* Sets or clears the byte flag at +0x710 for some message codes and always returns 0. The compare
   chain tests the labels in reverse source order (12, 11, 10, 25, 18, 9, 20, 8, 14, 22, 1, 0), so the
   empty cases 0, 1 and 11 are real labels. */
typedef struct Obj {
  char pad[0x710];
  unsigned char f710;
} Obj;

int FUN_000d8dcc(Obj *self, int code)
{
  switch (code) {
  case 0:
  case 1:
    break;
  case 22:
  case 14:
    self->f710 = 0;
    break;
  case 8:
    self->f710 = 0;
    break;
  case 20:
  case 9:
  case 18:
  case 25:
  case 10:
    self->f710 = 1;
    break;
  case 11:
    break;
  case 12:
    self->f710 = 1;
    break;
  }
  return 0;
}
