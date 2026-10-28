/* HSTMATCH module=EBOOT.BIN start=0x0006eaa0 end=0x0006eb04 symbol=FUN_0006eaa0 lang=c++ */
/* Clone of src/sharing_main/zero_append_00070260.cpp (hstclone.py tag u6cr5e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: changed to C++ and typed the third helper argument as an empty tag; exact match verified; names and types await human review. */
struct Tag {};
extern "C" void FUN_0006ee80(int *self, int n, Tag tag);
extern "C" void FUN_000114c0(int address, int value, int size);
extern "C" void FUN_0006eaa0(int *self, int n)
{
  if (n != 0) {
    FUN_0006ee80(self, n, Tag());
    FUN_000114c0(self[0] + self[1] * 4, 0, n << 2);
    self[1] += n;
  }
}
