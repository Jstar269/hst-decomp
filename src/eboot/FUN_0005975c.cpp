/* HSTMATCH module=EBOOT.BIN start=0x0005975c end=0x000597a0 symbol=FUN_0005975c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0005a008(void *a, Arg1 b);
extern "C" void FUN_00059cf4(void *a, int b, void *c);
extern "C" void FUN_0005975c(void *a, void *b) { Arg1 x; x.v = 1; FUN_0005a008(a, x); FUN_00059cf4(a, 1, b); }
