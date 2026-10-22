/* HSTMATCH module=hstp_trans_main.prx start=0x00059c1c end=0x00059ca4 symbol=FUN_00059c1c lang=c++ */
/* Clone of src/eboot/update_range_items_00058f38.cpp (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls FUN_000593fc once with the given index when it is not negative, otherwise walks the index range
   from the member at +0x158 up to the member at +0x15c (inclusive), calling the callee for each index,
   and clears the flag byte at +0xec afterwards.
   Matching idioms: the loop bound is read through a trivial inline getter so that it is re-loaded on
   every iteration, and the callee's float argument is declared before its last int argument so that
   the float setup is scheduled before the constant "1".
   Names provisional. */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
struct Obj {
  char pad[0xec];
  unsigned char fEC;
  char pad2[0x6b];
  int f158;
  int f15c;
  int Limit() const { return f15c; }
};

extern "C" void FUN_000593fc(Obj *, int, float, int);

extern "C" void FUN_00059c1c(Obj *self, int idx, float f)
{
  if (idx < 0) {
    int i = self->f158;
    if (i <= self->Limit()) {
      do {
        FUN_000593fc(self, i, f, 1);
        i++;
      } while (i <= self->Limit());
    }
    self->fEC = 0;
  } else {
    FUN_000593fc(self, idx, f, 1);
  }
}
