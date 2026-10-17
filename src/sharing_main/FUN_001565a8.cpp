/* HSTMATCH module=hstp_trans_main.prx start=0x001565a8 end=0x001565cc symbol=FUN_001565a8 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Obj_001565a8 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00157184(Obj_001565a8 *o, int v, Flag1 f);
extern "C" void FUN_001565a8(Obj_001565a8 *o) { Flag1 f = { 0 }; FUN_00157184(o, o->f4, f); }
