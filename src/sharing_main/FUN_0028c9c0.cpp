/* HSTMATCH module=hstp_trans_main.prx start=0x0028c9c0 end=0x0028c9e4 symbol=FUN_0028c9c0 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Obj_0028c9c0 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0028cb98(Obj_0028c9c0 *o, int v, Flag1 f);
extern "C" void FUN_0028c9c0(Obj_0028c9c0 *o) { Flag1 f = { 0 }; FUN_0028cb98(o, o->f4, f); }
