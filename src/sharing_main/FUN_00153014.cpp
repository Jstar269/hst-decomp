/* HSTMATCH module=hstp_trans_main.prx start=0x00153014 end=0x00153038 symbol=FUN_00153014 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Obj_00153014 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0015688c(Obj_00153014 *o, int v, Flag1 f);
extern "C" void FUN_00153014(Obj_00153014 *o) { Flag1 f = { 0 }; FUN_0015688c(o, o->f4, f); }
