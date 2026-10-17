/* HSTMATCH module=hstp_trans_main.prx start=0x000b886c end=0x000b8890 symbol=FUN_000b886c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000b886c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000bab60(Obj_000b886c *o, int v, Flag1 f);
extern "C" void FUN_000b886c(Obj_000b886c *o) { Flag1 f = { 0 }; FUN_000bab60(o, o->f4, f); }
