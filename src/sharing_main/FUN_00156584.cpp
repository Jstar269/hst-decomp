/* HSTMATCH module=hstp_trans_main.prx start=0x00156584 end=0x001565a8 symbol=FUN_00156584 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Obj_00156584 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00157218(Obj_00156584 *o, int v, Flag1 f);
extern "C" void FUN_00156584(Obj_00156584 *o) { Flag1 f = { 0 }; FUN_00157218(o, o->f4, f); }
