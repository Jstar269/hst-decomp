/* HSTMATCH module=hstp_trans_main.prx start=0x0006edec end=0x0006ee10 symbol=FUN_0006edec */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0006edec { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0006eeb8(Obj_0006edec *o, int v, Flag1 f);
extern "C" void FUN_0006edec(Obj_0006edec *o) { Flag1 f = { 0 }; FUN_0006eeb8(o, o->f4, f); }
