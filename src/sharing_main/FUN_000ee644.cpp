/* HSTMATCH module=hstp_trans_main.prx start=0x000ee644 end=0x000ee668 symbol=FUN_000ee644 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000ee644 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000ee920(Obj_000ee644 *o, int v, Flag1 f);
extern "C" void FUN_000ee644(Obj_000ee644 *o) { Flag1 f = { 0 }; FUN_000ee920(o, o->f4, f); }
