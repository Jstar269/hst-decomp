/* HSTMATCH module=EBOOT.BIN start=0x001473ec end=0x00147430 symbol=FUN_001473ec */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0014a03c(void *a, Arg1 b);
extern "C" void FUN_00149d28(void *a, int b, void *c);
extern "C" void FUN_001473ec(void *a, void *b) { Arg1 x; x.v = 1; FUN_0014a03c(a, x); FUN_00149d28(a, 1, b); }
