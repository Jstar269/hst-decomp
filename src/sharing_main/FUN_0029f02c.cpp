/* HSTMATCH module=hstp_trans_main.prx start=0x0029f02c end=0x0029f050 symbol=FUN_0029f02c */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Obj_0029f02c { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0029f3b0(Obj_0029f02c *o, int v, Flag1 f);
extern "C" void FUN_0029f02c(Obj_0029f02c *o) { Flag1 f = { 0 }; FUN_0029f3b0(o, o->f4, f); }
