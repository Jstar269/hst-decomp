/* HSTMATCH module=hstp_trans_main.prx start=0x00121bac end=0x00121bd0 symbol=FUN_00121bac */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_00121bac { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00121d48(Obj_00121bac *o, int v, Flag1 f);
extern "C" void FUN_00121bac(Obj_00121bac *o) { Flag1 f = { 0 }; FUN_00121d48(o, o->f4, f); }
