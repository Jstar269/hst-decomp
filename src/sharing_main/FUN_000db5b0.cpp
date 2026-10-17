/* HSTMATCH module=hstp_trans_main.prx start=0x000db5b0 end=0x000db5d4 symbol=FUN_000db5b0 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000db5b0 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000db990(Obj_000db5b0 *o, int v, Flag1 f);
extern "C" void FUN_000db5b0(Obj_000db5b0 *o) { Flag1 f = { 0 }; FUN_000db990(o, o->f4, f); }
