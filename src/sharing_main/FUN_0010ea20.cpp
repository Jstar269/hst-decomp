/* HSTMATCH module=hstp_trans_main.prx start=0x0010ea20 end=0x0010ea44 symbol=FUN_0010ea20 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0010ea20 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00110110(Obj_0010ea20 *o, int v, Flag1 f);
extern "C" void FUN_0010ea20(Obj_0010ea20 *o) { Flag1 f = { 0 }; FUN_00110110(o, o->f4, f); }
