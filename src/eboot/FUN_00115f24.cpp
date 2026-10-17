/* HSTMATCH module=EBOOT.BIN start=0x00115f24 end=0x00115f68 symbol=FUN_00115f24 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00116688(void *a, Arg1 b);
extern "C" void FUN_00116424(void *a, int b, void *c);
extern "C" void FUN_00115f24(void *a, void *b) { Arg1 x; x.v = 1; FUN_00116688(a, x); FUN_00116424(a, 1, b); }
