/* HSTMATCH module=hstp_trans_main.prx start=0x00166888 end=0x001668dc symbol=FUN_00166888 lang=c99 rodata=0x002d2114 */
/* Clone of src/eboot/switch_state_value_0015a2b0.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct S
{
  char pad[0x14];
  int f14;
  char pad2[0x20 - 0x18];
  int f20;
};

void FUN_00166888(struct S *p, int v)
{
  p->f14 = v;
  switch(v) {
  case 0:
  case 1:
    p->f20 = 0;
    p->f14 = 2;
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    p->f14 = 8;
    break;
  case 6:
    break;
  case 7:
    p->f14 = 8;
    break;
  }
}
