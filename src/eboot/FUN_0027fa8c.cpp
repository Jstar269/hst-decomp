/* HSTMATCH module=EBOOT.BIN start=0x0027fa8c end=0x0027fab0 symbol=FUN_0027fa8c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0027fa8c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0027fc00(Obj_0027fa8c *o, int v, Flag1 f);
extern "C" void FUN_0027fa8c(Obj_0027fa8c *o) { Flag1 f = { 0 }; FUN_0027fc00(o, o->f4, f); }
