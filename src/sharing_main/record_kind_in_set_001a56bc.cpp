/* HSTMATCH module=hstp_trans_main.prx start=0x001a56bc end=0x001a5704 symbol=FUN_001a56bc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the if/else-if chain over 0xb, 0xc, 8, 7 is a switch with the labels written 7, 8, 12, 11 (retail tests them in reverse source order), the halfword is read through a struct; exact match verified; names and types await human review. */
struct Rec { unsigned short kind; };
extern "C" int FUN_001a56bc(void *self, Rec *r)
{
  switch (r->kind) {
  case 7:
  case 8:
  case 12:
  case 11:
    return 1;
  }
  return 0;
}
