/* HSTMATCH module=EBOOT.BIN start=0x00002a64 end=0x00002acc symbol=FUN_00002a64 lang=c++ */
/* Clone of src/sharing_main/FUN_00002a64_00002a64.cpp (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct EmptyTag {};
extern "C" int FUN_00014a40(const char *);
extern "C" void *FUN_00000a90(unsigned);
extern "C" void FUN_00002b60(void *, char *, EmptyTag);
extern "C" char *FUN_00002acc(void *);
extern "C" void FUN_000149a8(char *, const char *);
extern "C" void *FUN_00002a64(void *param_1, const char *param_2)
{
  int n = FUN_00014a40(param_2);
  char *buffer = (char *)FUN_00000a90((unsigned)(n + 1));
  FUN_00002b60(param_1, buffer, EmptyTag());
  FUN_000149a8(FUN_00002acc(param_1), param_2);
  return param_1;
}
