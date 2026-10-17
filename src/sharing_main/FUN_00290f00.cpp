/* HSTMATCH module=hstp_trans_main.prx start=0x00290f00 end=0x00290f24 symbol=FUN_00290f00 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Obj_00290f00 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00291074(Obj_00290f00 *o, int v, Flag1 f);
extern "C" void FUN_00290f00(Obj_00290f00 *o) { Flag1 f = { 0 }; FUN_00291074(o, o->f4, f); }
