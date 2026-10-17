/* HSTMATCH module=hstp_trans_main.prx start=0x000671e0 end=0x00067224 symbol=FUN_000671e0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00067c10(void *a, Arg1 b);
extern "C" void FUN_000678fc(void *a, int b, void *c);
extern "C" void FUN_000671e0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00067c10(a, x); FUN_000678fc(a, 1, b); }
