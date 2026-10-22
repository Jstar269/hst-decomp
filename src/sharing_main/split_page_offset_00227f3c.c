/* HSTMATCH module=hstp_trans_main.prx start=0x00227f3c end=0x00227fc8 symbol=FUN_00227f3c lang=c99 */
/* Clone of src/eboot/split_page_offset_00218a24.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Splits a signed value into a page number (*p1) and an offset (*p2): values >= 600/400/300 give the
   page 5/4/3 and the value minus the page base, everything below 300 is divided by 64 with a
   floor-division remainder (the remainder of a negative value is negative).
   Matching idioms: the page tests are written as "x >= 600" / "x >= 400" / "x >= 300" so that mwccpsp
   emits the branch-likely that jumps to the smaller case; the quotient has to be computed BEFORE the
   "x < 0" test (a local) so that the shared store lands in the likely slot; the "remainder == 0" case
   has to be the ELSE arm of "r != 0" so that its store sits in the beqzl slot and the branch returns. */
void FUN_00227f3c(int *p1, unsigned *p2, int x)
{
  if (x >= 600) {
    *p1 = 5;
    *p2 = x - 600;
  } else if (x >= 400) {
    *p1 = 4;
    *p2 = x - 400;
  } else if (x >= 300) {
    *p1 = 3;
    *p2 = x - 300;
  } else {
    int q = x >> 6;
    if (x < 0) {
      q = (x + 63) >> 6;
    }
    *p1 = q;
    {
      unsigned r = (unsigned)x & 0x3f;
      if (x < 0) {
        if (r != 0) {
          r = r - 64;
        } else {
          *p2 = r;
          return;
        }
      }
      *p2 = r;
    }
  }
}
