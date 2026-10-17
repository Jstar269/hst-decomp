/* HSTMATCH module=EBOOT.BIN start=0x0013f21c end=0x0013f240 symbol=FUN_0013f21c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0013f21c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0013fb10(Obj_0013f21c *o, int v, Flag1 f);
extern "C" void FUN_0013f21c(Obj_0013f21c *o) { Flag1 f = { 0 }; FUN_0013fb10(o, o->f4, f); }
