/* HSTMATCH module=hstp_trans_main.prx start=0x000ded40 end=0x000ded64 symbol=FUN_000ded40 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000ded40 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000dee0c(Obj_000ded40 *o, int v, Flag1 f);
extern "C" void FUN_000ded40(Obj_000ded40 *o) { Flag1 f = { 0 }; FUN_000dee0c(o, o->f4, f); }
