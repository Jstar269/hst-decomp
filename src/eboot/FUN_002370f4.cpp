/* HSTMATCH module=EBOOT.BIN start=0x002370f4 end=0x00237138 symbol=FUN_002370f4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0023810c(void *a, Arg1 b);
extern "C" void FUN_00237d1c(void *a, int b, void *c);
extern "C" void FUN_002370f4(void *a, void *b) { Arg1 x; x.v = 1; FUN_0023810c(a, x); FUN_00237d1c(a, 1, b); }
