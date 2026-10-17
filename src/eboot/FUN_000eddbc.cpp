/* HSTMATCH module=EBOOT.BIN start=0x000eddbc end=0x000edde0 symbol=FUN_000eddbc */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000eddbc { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000ede88(Obj_000eddbc *o, int v, Flag1 f);
extern "C" void FUN_000eddbc(Obj_000eddbc *o) { Flag1 f = { 0 }; FUN_000ede88(o, o->f4, f); }
