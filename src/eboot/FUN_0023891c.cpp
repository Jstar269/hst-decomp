/* HSTMATCH module=EBOOT.BIN start=0x0023891c end=0x00238940 symbol=FUN_0023891c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0023891c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00238c1c(Obj_0023891c *o, int v, Flag1 f);
extern "C" void FUN_0023891c(Obj_0023891c *o) { Flag1 f = { 0 }; FUN_00238c1c(o, o->f4, f); }
