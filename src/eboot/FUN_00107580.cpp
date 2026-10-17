/* HSTMATCH module=EBOOT.BIN start=0x00107580 end=0x001075c4 symbol=FUN_00107580 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00108aa4(void *a, Arg1 b);
extern "C" void FUN_001087e0(void *a, int b, void *c);
extern "C" void FUN_00107580(void *a, void *b) { Arg1 x; x.v = 1; FUN_00108aa4(a, x); FUN_001087e0(a, 1, b); }
