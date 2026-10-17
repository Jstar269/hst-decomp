/* HSTMATCH module=EBOOT.BIN start=0x00106ff0 end=0x00107034 symbol=FUN_00106ff0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00107bbc(void *a, Arg1 b);
extern "C" void FUN_0010798c(void *a, int b, void *c);
extern "C" void FUN_00106ff0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00107bbc(a, x); FUN_0010798c(a, 1, b); }
