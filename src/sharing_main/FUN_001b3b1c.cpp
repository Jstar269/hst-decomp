/* HSTMATCH module=hstp_trans_main.prx start=0x001b3b1c end=0x001b3b60 symbol=FUN_001b3b1c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001b5214(void *a, Arg1 b);
extern "C" void FUN_001b4fe4(void *a, int b, void *c);
extern "C" void FUN_001b3b1c(void *a, void *b) { Arg1 x; x.v = 1; FUN_001b5214(a, x); FUN_001b4fe4(a, 1, b); }
