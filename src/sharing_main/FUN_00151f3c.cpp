/* HSTMATCH module=hstp_trans_main.prx start=0x00151f3c end=0x00151f80 symbol=FUN_00151f3c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00060868(void *a, Arg1 b);
extern "C" void FUN_00060638(void *a, int b, void *c);
extern "C" void FUN_00151f3c(void *a, void *b) { Arg1 x; x.v = 1; FUN_00060868(a, x); FUN_00060638(a, 1, b); }
