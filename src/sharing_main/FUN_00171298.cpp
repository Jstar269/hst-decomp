/* HSTMATCH module=hstp_trans_main.prx start=0x00171298 end=0x001712dc symbol=FUN_00171298 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00171f6c(void *a, Arg1 b);
extern "C" void FUN_00171c5c(void *a, int b, void *c);
extern "C" void FUN_00171298(void *a, void *b) { Arg1 x; x.v = 1; FUN_00171f6c(a, x); FUN_00171c5c(a, 1, b); }
