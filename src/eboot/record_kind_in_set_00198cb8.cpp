/* HSTMATCH module=EBOOT.BIN start=0x00198cb8 end=0x00198d00 symbol=FUN_00198cb8 lang=c++ */
/* Clone of src/sharing_main/record_kind_in_set_001a56bc.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the if/else-if chain over 0xb, 0xc, 8, 7 is a switch with the labels written 7, 8, 12, 11 (retail tests them in reverse source order), the halfword is read through a struct; exact match verified; names and types await human review. */
struct Rec { unsigned short kind; };
extern "C" int FUN_00198cb8(void *self, Rec *r)
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
