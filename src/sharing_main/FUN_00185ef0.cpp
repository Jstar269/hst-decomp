/* HSTMATCH module=hstp_trans_main.prx start=0x00185ef0 end=0x00185f34 symbol=FUN_00185ef0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00186a40(void *a, Arg1 b);
extern "C" void FUN_00186810(void *a, int b, void *c);
extern "C" void FUN_00185ef0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00186a40(a, x); FUN_00186810(a, 1, b); }
