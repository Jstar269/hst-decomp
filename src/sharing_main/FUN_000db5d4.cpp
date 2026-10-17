/* HSTMATCH module=hstp_trans_main.prx start=0x000db5d4 end=0x000db5f8 symbol=FUN_000db5d4 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000db5d4 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000db980(Obj_000db5d4 *o, int v, Flag1 f);
extern "C" void FUN_000db5d4(Obj_000db5d4 *o) { Flag1 f = { 0 }; FUN_000db980(o, o->f4, f); }
