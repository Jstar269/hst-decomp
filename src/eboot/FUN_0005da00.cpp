/* HSTMATCH module=EBOOT.BIN start=0x0005da00 end=0x0005da44 symbol=FUN_0005da00 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0005df68(void *a, Arg1 b);
extern "C" void FUN_0005dd38(void *a, int b, void *c);
extern "C" void FUN_0005da00(void *a, void *b) { Arg1 x; x.v = 1; FUN_0005df68(a, x); FUN_0005dd38(a, 1, b); }
