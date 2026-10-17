/* HSTMATCH module=hstp_trans_main.prx start=0x000b7650 end=0x000b7694 symbol=FUN_000b7650 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000b8284(void *a, Arg1 b);
extern "C" void FUN_000b7ff0(void *a, int b, void *c);
extern "C" void FUN_000b7650(void *a, void *b) { Arg1 x; x.v = 1; FUN_000b8284(a, x); FUN_000b7ff0(a, 1, b); }
