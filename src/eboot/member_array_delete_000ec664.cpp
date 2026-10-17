/* HSTMATCH module=EBOOT.BIN start=0x000ec664 end=0x000ec6c8 symbol=FUN_000ec664 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: walking base declared after the loop index, delete through a virtual-destructor class, member offset form kept as int arithmetic; exact match verified; names and types await human review. */
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_000ec664(int param_1)
{
  int i = 0;
  int q = param_1;
  do {
    VC_0 *p = *(VC_0 **)(q + 0x40);
    if (p != 0) {
      delete p;
      *(VC_0 **)(q + 0x40) = 0;
    }
    i++;
    q += 4;
  } while (i < 6);
}
