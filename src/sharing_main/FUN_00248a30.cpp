/* HSTMATCH module=hstp_trans_main.prx start=0x00248a30 end=0x00248a54 symbol=FUN_00248a30 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Obj_00248a30 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00248d64(Obj_00248a30 *o, int v, Flag1 f);
extern "C" void FUN_00248a30(Obj_00248a30 *o) { Flag1 f = { 0 }; FUN_00248d64(o, o->f4, f); }
