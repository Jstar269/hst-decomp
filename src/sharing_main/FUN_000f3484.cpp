/* HSTMATCH module=hstp_trans_main.prx start=0x000f3484 end=0x000f34a8 symbol=FUN_000f3484 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000f3484 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000f3550(Obj_000f3484 *o, int v, Flag1 f);
extern "C" void FUN_000f3484(Obj_000f3484 *o) { Flag1 f = { 0 }; FUN_000f3550(o, o->f4, f); }
