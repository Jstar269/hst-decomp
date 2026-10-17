/* HSTMATCH module=EBOOT.BIN start=0x000dad80 end=0x000dada4 symbol=FUN_000dad80 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000dad80 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000dae4c(Obj_000dad80 *o, int v, Flag1 f);
extern "C" void FUN_000dad80(Obj_000dad80 *o) { Flag1 f = { 0 }; FUN_000dae4c(o, o->f4, f); }
