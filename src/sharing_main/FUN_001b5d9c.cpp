/* HSTMATCH module=hstp_trans_main.prx start=0x001b5d9c end=0x001b5dc0 symbol=FUN_001b5d9c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Obj_001b5d9c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_001b6584(Obj_001b5d9c *o, int v, Flag1 f);
extern "C" void FUN_001b5d9c(Obj_001b5d9c *o) { Flag1 f = { 0 }; FUN_001b6584(o, o->f4, f); }
