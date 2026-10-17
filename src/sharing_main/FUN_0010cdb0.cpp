/* HSTMATCH module=hstp_trans_main.prx start=0x0010cdb0 end=0x0010cdf4 symbol=FUN_0010cdb0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0010d97c(void *a, Arg1 b);
extern "C" void FUN_0010d74c(void *a, int b, void *c);
extern "C" void FUN_0010cdb0(void *a, void *b) { Arg1 x; x.v = 1; FUN_0010d97c(a, x); FUN_0010d74c(a, 1, b); }
