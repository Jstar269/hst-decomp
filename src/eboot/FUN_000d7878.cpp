/* HSTMATCH module=EBOOT.BIN start=0x000d7878 end=0x000d789c symbol=FUN_000d7878 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000d7878 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000d7d70(Obj_000d7878 *o, int v, Flag1 f);
extern "C" void FUN_000d7878(Obj_000d7878 *o) { Flag1 f = { 0 }; FUN_000d7d70(o, o->f4, f); }
