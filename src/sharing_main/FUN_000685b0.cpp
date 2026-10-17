/* HSTMATCH module=hstp_trans_main.prx start=0x000685b0 end=0x000685d4 symbol=FUN_000685b0 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000685b0 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00068788(Obj_000685b0 *o, int v, Flag1 f);
extern "C" void FUN_000685b0(Obj_000685b0 *o) { Flag1 f = { 0 }; FUN_00068788(o, o->f4, f); }
