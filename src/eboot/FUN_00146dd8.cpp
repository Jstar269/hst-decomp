/* HSTMATCH module=EBOOT.BIN start=0x00146dd8 end=0x00146e1c symbol=FUN_00146dd8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001494e4(void *a, Arg1 b);
extern "C" void FUN_00149278(void *a, int b, void *c);
extern "C" void FUN_00146dd8(void *a, void *b) { Arg1 x; x.v = 1; FUN_001494e4(a, x); FUN_00149278(a, 1, b); }
