/* HSTMATCH module=hstp_trans_main.prx start=0x00121bd0 end=0x00121bf4 symbol=FUN_00121bd0 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_00121bd0 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00121d38(Obj_00121bd0 *o, int v, Flag1 f);
extern "C" void FUN_00121bd0(Obj_00121bd0 *o) { Flag1 f = { 0 }; FUN_00121d38(o, o->f4, f); }
