/* HSTMATCH module=hstp_trans_main.prx start=0x001565cc end=0x001565f0 symbol=FUN_001565cc */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Obj_001565cc { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00157174(Obj_001565cc *o, int v, Flag1 f);
extern "C" void FUN_001565cc(Obj_001565cc *o) { Flag1 f = { 0 }; FUN_00157174(o, o->f4, f); }
