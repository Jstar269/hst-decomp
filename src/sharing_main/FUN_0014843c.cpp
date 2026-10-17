/* HSTMATCH module=hstp_trans_main.prx start=0x0014843c end=0x00148480 symbol=FUN_0014843c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00149ed8(void *a, Arg1 b);
extern "C" void FUN_00149c84(void *a, int b, void *c);
extern "C" void FUN_0014843c(void *a, void *b) { Arg1 x; x.v = 1; FUN_00149ed8(a, x); FUN_00149c84(a, 1, b); }
