/* HSTMATCH module=hstp_trans_main.prx start=0x001f3688 end=0x001f36f4 symbol=f__1OFv lang=c++ */
/* Clone of src/eboot/FUN_001e5470.cpp (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: typed helper arguments and object fields; exact match verified; names and types await human review. */
struct O { char bytes[0x784]; void f(); };
extern "C" void FUN_002268b4(float, float, void *, int);
extern "C" void FUN_002268dc(void *, int, int, int);
void O::f()
{
  FUN_002268b4(2.0f, 1.0f, bytes + 0x6f8, 10);
  FUN_002268dc(bytes + 0x6f8, -1, *(int *)(bytes + 0x718), 10);
  FUN_002268b4(2.0f, 1.0f, bytes + 0x784, 10);
}
