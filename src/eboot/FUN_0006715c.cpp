/* HSTMATCH module=EBOOT.BIN start=0x0006715c end=0x00067180 symbol=FUN_0006715c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0006715c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00067334(Obj_0006715c *o, int v, Flag1 f);
extern "C" void FUN_0006715c(Obj_0006715c *o) { Flag1 f = { 0 }; FUN_00067334(o, o->f4, f); }
