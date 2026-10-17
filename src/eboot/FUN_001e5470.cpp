/* HSTMATCH module=EBOOT.BIN start=0x001e5470 end=0x001e54dc symbol=f__1OFv lang=c++ */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: typed helper arguments and object fields; exact match verified; names and types await human review. */
struct O { char bytes[0x784]; void f(); };
extern "C" void FUN_0021780c(float, float, void *, int);
extern "C" void FUN_00217834(void *, int, int, int);
void O::f()
{
  FUN_0021780c(2.0f, 1.0f, bytes + 0x6f8, 10);
  FUN_00217834(bytes + 0x6f8, -1, *(int *)(bytes + 0x718), 10);
  FUN_0021780c(2.0f, 1.0f, bytes + 0x784, 10);
}
