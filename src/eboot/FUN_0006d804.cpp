/* HSTMATCH module=EBOOT.BIN start=0x0006d804 end=0x0006d828 symbol=FUN_0006d804 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0006d804 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0006d8d0(Obj_0006d804 *o, int v, Flag1 f);
extern "C" void FUN_0006d804(Obj_0006d804 *o) { Flag1 f = { 0 }; FUN_0006d8d0(o, o->f4, f); }
