/* HSTMATCH module=hstp_trans_main.prx start=0x00148024 end=0x00148068 symbol=FUN_00148024 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00148ba8(void *a, Arg1 b);
extern "C" void FUN_00148978(void *a, int b, void *c);
extern "C" void FUN_00148024(void *a, void *b) { Arg1 x; x.v = 1; FUN_00148ba8(a, x); FUN_00148978(a, 1, b); }
