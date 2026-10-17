/* HSTMATCH module=hstp_trans_main.prx start=0x0005ae10 end=0x0005ae34 symbol=FUN_0005ae10 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0005ae10 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0005afe8(Obj_0005ae10 *o, int v, Flag1 f);
extern "C" void FUN_0005ae10(Obj_0005ae10 *o) { Flag1 f = { 0 }; FUN_0005afe8(o, o->f4, f); }
