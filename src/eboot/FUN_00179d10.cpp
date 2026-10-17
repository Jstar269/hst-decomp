/* HSTMATCH module=EBOOT.BIN start=0x00179d10 end=0x00179d54 symbol=FUN_00179d10 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0017a958(void *a, Arg1 b);
extern "C" void FUN_0017a728(void *a, int b, void *c);
extern "C" void FUN_00179d10(void *a, void *b) { Arg1 x; x.v = 1; FUN_0017a958(a, x); FUN_0017a728(a, 1, b); }
