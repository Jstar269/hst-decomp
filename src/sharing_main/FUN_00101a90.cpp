/* HSTMATCH module=hstp_trans_main.prx start=0x00101a90 end=0x00101ad4 symbol=FUN_00101a90 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00101d6c(void *a, Arg1 b);
extern "C" void FUN_00101b3c(void *a, int b, void *c);
extern "C" void FUN_00101a90(void *a, void *b) { Arg1 x; x.v = 1; FUN_00101d6c(a, x); FUN_00101b3c(a, 1, b); }
