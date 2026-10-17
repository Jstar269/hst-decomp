/* HSTMATCH module=hstp_trans_main.prx start=0x0028fa34 end=0x0028fa58 symbol=FUN_0028fa34 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Obj_0028fa34 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0028fb08(Obj_0028fa34 *o, int v, Flag1 f);
extern "C" void FUN_0028fa34(Obj_0028fa34 *o) { Flag1 f = { 0 }; FUN_0028fb08(o, o->f4, f); }
