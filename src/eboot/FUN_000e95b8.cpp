/* HSTMATCH module=EBOOT.BIN start=0x000e95b8 end=0x000e95dc symbol=FUN_000e95b8 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000e95b8 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000e97c4(Obj_000e95b8 *o, int v, Flag1 f);
extern "C" void FUN_000e95b8(Obj_000e95b8 *o) { Flag1 f = { 0 }; FUN_000e97c4(o, o->f4, f); }
