/* HSTMATCH module=EBOOT.BIN start=0x000e99d4 end=0x000e9a1c symbol=FUN_000e99d4 lang=c++ */
/* Hand-written reconstruction from the disassembly (delete of a member through its virtual destructor); exact match verified; names and types await human review. */

extern "C" {
}
struct VD { virtual ~VD(); };

extern "C" void FUN_000e99d4(int param_1)
{
  VD *p = *(VD **)(param_1 + 0x540);
  if (p != 0) {
    delete p;
    *(VD **)(param_1 + 0x540) = 0;
  }
}
