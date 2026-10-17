/* HSTMATCH module=EBOOT.BIN start=0x0005e7b4 end=0x0005e7d8 symbol=FUN_0005e7b4 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0005e7b4 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0005ea98(Obj_0005e7b4 *o, int v, Flag1 f);
extern "C" void FUN_0005e7b4(Obj_0005e7b4 *o) { Flag1 f = { 0 }; FUN_0005ea98(o, o->f4, f); }
