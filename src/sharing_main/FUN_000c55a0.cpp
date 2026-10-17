/* HSTMATCH module=hstp_trans_main.prx start=0x000c55a0 end=0x000c55c4 symbol=FUN_000c55a0 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000c55a0 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000c566c(Obj_000c55a0 *o, int v, Flag1 f);
extern "C" void FUN_000c55a0(Obj_000c55a0 *o) { Flag1 f = { 0 }; FUN_000c566c(o, o->f4, f); }
