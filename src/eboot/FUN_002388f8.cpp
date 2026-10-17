/* HSTMATCH module=EBOOT.BIN start=0x002388f8 end=0x0023891c symbol=FUN_002388f8 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_002388f8 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00238c2c(Obj_002388f8 *o, int v, Flag1 f);
extern "C" void FUN_002388f8(Obj_002388f8 *o) { Flag1 f = { 0 }; FUN_00238c2c(o, o->f4, f); }
