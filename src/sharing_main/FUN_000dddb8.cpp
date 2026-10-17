/* HSTMATCH module=hstp_trans_main.prx start=0x000dddb8 end=0x000dddfc symbol=FUN_000dddb8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000de608(void *a, Arg1 b);
extern "C" void FUN_000de3a4(void *a, int b, void *c);
extern "C" void FUN_000dddb8(void *a, void *b) { Arg1 x; x.v = 1; FUN_000de608(a, x); FUN_000de3a4(a, 1, b); }
