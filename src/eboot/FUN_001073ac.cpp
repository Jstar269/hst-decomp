/* HSTMATCH module=EBOOT.BIN start=0x001073ac end=0x001073f0 symbol=FUN_001073ac */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001083d4(void *a, Arg1 b);
extern "C" void FUN_001081a4(void *a, int b, void *c);
extern "C" void FUN_001073ac(void *a, void *b) { Arg1 x; x.v = 1; FUN_001083d4(a, x); FUN_001081a4(a, 1, b); }
