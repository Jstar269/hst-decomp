/* HSTMATCH module=EBOOT.BIN start=0x001797fc end=0x00179840 symbol=FUN_001797fc */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0017a34c(void *a, Arg1 b);
extern "C" void FUN_0017a11c(void *a, int b, void *c);
extern "C" void FUN_001797fc(void *a, void *b) { Arg1 x; x.v = 1; FUN_0017a34c(a, x); FUN_0017a11c(a, 1, b); }
