/* HSTMATCH module=hstp_trans_main.prx start=0x000f2cf0 end=0x000f2d40 symbol=FUN_000f2cf0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: changed both third helper arguments to an empty C++ tag; exact match verified; names and types await human review. */
struct EmptyTag {};
extern "C" void FUN_000f2d40(unsigned int, int, EmptyTag);
extern "C" void FUN_000f3010(unsigned int, int, EmptyTag);
extern "C" void FUN_000f2cf0(unsigned int param_1, int param_2)
{
  if (param_2 != 0) {
    FUN_000f3010(param_1, param_2, EmptyTag());
    FUN_000f2d40(param_1, param_2, EmptyTag());
  }
}
