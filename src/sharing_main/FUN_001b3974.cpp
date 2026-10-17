/* HSTMATCH module=hstp_trans_main.prx start=0x001b3974 end=0x001b39b8 symbol=FUN_001b3974 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001b4e7c(void *a, Arg1 b);
extern "C" void FUN_001b4c4c(void *a, int b, void *c);
extern "C" void FUN_001b3974(void *a, void *b) { Arg1 x; x.v = 1; FUN_001b4e7c(a, x); FUN_001b4c4c(a, 1, b); }
