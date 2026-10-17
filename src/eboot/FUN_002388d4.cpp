/* HSTMATCH module=EBOOT.BIN start=0x002388d4 end=0x002388f8 symbol=FUN_002388d4 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_002388d4 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00238c3c(Obj_002388d4 *o, int v, Flag1 f);
extern "C" void FUN_002388d4(Obj_002388d4 *o) { Flag1 f = { 0 }; FUN_00238c3c(o, o->f4, f); }
