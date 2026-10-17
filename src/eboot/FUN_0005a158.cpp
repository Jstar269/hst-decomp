/* HSTMATCH module=EBOOT.BIN start=0x0005a158 end=0x0005a17c symbol=FUN_0005a158 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0005a158 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0005a330(Obj_0005a158 *o, int v, Flag1 f);
extern "C" void FUN_0005a158(Obj_0005a158 *o) { Flag1 f = { 0 }; FUN_0005a330(o, o->f4, f); }
