/* HSTMATCH module=EBOOT.BIN start=0x000d789c end=0x000d78c0 symbol=FUN_000d789c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000d789c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000d7d60(Obj_000d789c *o, int v, Flag1 f);
extern "C" void FUN_000d789c(Obj_000d789c *o) { Flag1 f = { 0 }; FUN_000d7d60(o, o->f4, f); }
