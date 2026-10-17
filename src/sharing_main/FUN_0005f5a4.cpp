/* HSTMATCH module=hstp_trans_main.prx start=0x0005f5a4 end=0x0005f5c8 symbol=FUN_0005f5a4 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0005f5a4 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0005f888(Obj_0005f5a4 *o, int v, Flag1 f);
extern "C" void FUN_0005f5a4(Obj_0005f5a4 *o) { Flag1 f = { 0 }; FUN_0005f888(o, o->f4, f); }
