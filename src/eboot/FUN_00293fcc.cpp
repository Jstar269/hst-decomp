/* HSTMATCH module=EBOOT.BIN start=0x00293fcc end=0x00294010 symbol=FUN_00293fcc */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0029430c(void *a, Arg1 b);
extern "C" void FUN_00294088(void *a, int b, void *c);
extern "C" void FUN_00293fcc(void *a, void *b) { Arg1 x; x.v = 1; FUN_0029430c(a, x); FUN_00294088(a, 1, b); }
