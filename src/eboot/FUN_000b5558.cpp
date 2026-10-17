/* HSTMATCH module=EBOOT.BIN start=0x000b5558 end=0x000b557c symbol=FUN_000b5558 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000b5558 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000b7880(Obj_000b5558 *o, int v, Flag1 f);
extern "C" void FUN_000b5558(Obj_000b5558 *o) { Flag1 f = { 0 }; FUN_000b7880(o, o->f4, f); }
