/* HSTMATCH module=hstp_trans_main.prx start=0x00151f80 end=0x00151fc4 symbol=FUN_00151f80 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00153268(void *a, Arg1 b);
extern "C" void FUN_00153038(void *a, int b, void *c);
extern "C" void FUN_00151f80(void *a, void *b) { Arg1 x; x.v = 1; FUN_00153268(a, x); FUN_00153038(a, 1, b); }
