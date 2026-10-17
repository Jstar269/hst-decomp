/* HSTMATCH module=EBOOT.BIN start=0x0027b6dc end=0x0027b700 symbol=FUN_0027b6dc */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Obj_0027b6dc { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0027b8b4(Obj_0027b6dc *o, int v, Flag1 f);
extern "C" void FUN_0027b6dc(Obj_0027b6dc *o) { Flag1 f = { 0 }; FUN_0027b8b4(o, o->f4, f); }
