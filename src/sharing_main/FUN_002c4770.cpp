/* HSTMATCH module=hstp_trans_main.prx start=0x002c4770 end=0x002c4794 symbol=FUN_002c4770 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Obj_002c4770 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_002c4844(Obj_002c4770 *o, int v, Flag1 f);
extern "C" void FUN_002c4770(Obj_002c4770 *o) { Flag1 f = { 0 }; FUN_002c4844(o, o->f4, f); }
