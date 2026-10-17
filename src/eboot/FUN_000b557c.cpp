/* HSTMATCH module=EBOOT.BIN start=0x000b557c end=0x000b55a0 symbol=FUN_000b557c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000b557c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000b7870(Obj_000b557c *o, int v, Flag1 f);
extern "C" void FUN_000b557c(Obj_000b557c *o) { Flag1 f = { 0 }; FUN_000b7870(o, o->f4, f); }
