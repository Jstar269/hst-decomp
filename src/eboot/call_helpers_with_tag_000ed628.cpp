/* HSTMATCH module=EBOOT.BIN start=0x000ed628 end=0x000ed678 symbol=FUN_000ed628 lang=c++ */
/* Clone of src/sharing_main/call_helpers_with_tag_000f2cf0.cpp (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: changed both third helper arguments to an empty C++ tag; exact match verified; names and types await human review. */
struct EmptyTag {};
extern "C" void FUN_000ed678(unsigned int, int, EmptyTag);
extern "C" void FUN_000ed948(unsigned int, int, EmptyTag);
extern "C" void FUN_000ed628(unsigned int param_1, int param_2)
{
  if (param_2 != 0) {
    FUN_000ed948(param_1, param_2, EmptyTag());
    FUN_000ed678(param_1, param_2, EmptyTag());
  }
}
