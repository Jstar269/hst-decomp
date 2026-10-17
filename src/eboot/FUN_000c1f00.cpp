/* HSTMATCH module=EBOOT.BIN start=0x000c1f00 end=0x000c1f24 symbol=FUN_000c1f00 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000c1f00 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000c1fcc(Obj_000c1f00 *o, int v, Flag1 f);
extern "C" void FUN_000c1f00(Obj_000c1f00 *o) { Flag1 f = { 0 }; FUN_000c1fcc(o, o->f4, f); }
