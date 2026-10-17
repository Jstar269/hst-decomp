/* HSTMATCH module=EBOOT.BIN start=0x00107130 end=0x00107174 symbol=FUN_00107130 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0010803c(void *a, Arg1 b);
extern "C" void FUN_00107e0c(void *a, int b, void *c);
extern "C" void FUN_00107130(void *a, void *b) { Arg1 x; x.v = 1; FUN_0010803c(a, x); FUN_00107e0c(a, 1, b); }
