/* HSTMATCH module=EBOOT.BIN start=0x0029445c end=0x00294480 symbol=FUN_0029445c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0029445c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00294554(Obj_0029445c *o, int v, Flag1 f);
extern "C" void FUN_0029445c(Obj_0029445c *o) { Flag1 f = { 0 }; FUN_00294554(o, o->f4, f); }
