/* HSTMATCH module=hstp_trans_main.prx start=0x00070260 end=0x000702c4 symbol=FUN_00070260 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: changed to C++ and typed the third helper argument as an empty tag; exact match verified; names and types await human review. */
typedef unsigned char undefined1;
typedef unsigned int uint;
struct Tag {};
extern "C" void FUN_00070640(int *self, int n, Tag tag);
extern "C" void FUN_000114c0(int address, int value, int size);
extern "C" void FUN_00070260(int *self, int n)
{
  if (n != 0) {
    FUN_00070640(self, n, Tag());
    FUN_000114c0(self[0] + self[1] * 4, 0, n << 2);
    self[1] += n;
  }
}
