/* HSTMATCH module=EBOOT.BIN start=0x0014ac9c end=0x0014acc0 symbol=FUN_0014ac9c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0014ac9c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0014b930(Obj_0014ac9c *o, int v, Flag1 f);
extern "C" void FUN_0014ac9c(Obj_0014ac9c *o) { Flag1 f = { 0 }; FUN_0014b930(o, o->f4, f); }
