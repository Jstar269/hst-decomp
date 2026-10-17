/* HSTMATCH module=EBOOT.BIN start=0x0027e5f0 end=0x0027e614 symbol=FUN_0027e5f0 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0027e5f0 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0027e6c4(Obj_0027e5f0 *o, int v, Flag1 f);
extern "C" void FUN_0027e5f0(Obj_0027e5f0 *o) { Flag1 f = { 0 }; FUN_0027e6c4(o, o->f4, f); }
