/* HSTMATCH module=hstp_trans_main.prx start=0x000db58c end=0x000db5b0 symbol=FUN_000db58c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000db58c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000dba50(Obj_000db58c *o, int v, Flag1 f);
extern "C" void FUN_000db58c(Obj_000db58c *o) { Flag1 f = { 0 }; FUN_000dba50(o, o->f4, f); }
