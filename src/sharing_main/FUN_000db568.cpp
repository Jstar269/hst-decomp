/* HSTMATCH module=hstp_trans_main.prx start=0x000db568 end=0x000db58c symbol=FUN_000db568 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000db568 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000dba60(Obj_000db568 *o, int v, Flag1 f);
extern "C" void FUN_000db568(Obj_000db568 *o) { Flag1 f = { 0 }; FUN_000dba60(o, o->f4, f); }
