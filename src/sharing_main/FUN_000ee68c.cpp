/* HSTMATCH module=hstp_trans_main.prx start=0x000ee68c end=0x000ee6b0 symbol=FUN_000ee68c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000ee68c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000ee898(Obj_000ee68c *o, int v, Flag1 f);
extern "C" void FUN_000ee68c(Obj_000ee68c *o) { Flag1 f = { 0 }; FUN_000ee898(o, o->f4, f); }
