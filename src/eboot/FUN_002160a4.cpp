/* HSTMATCH module=EBOOT.BIN start=0x002160a4 end=0x002160c8 symbol=FUN_002160a4 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_002160a4 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00216164(Obj_002160a4 *o, int v, Flag1 f);
extern "C" void FUN_002160a4(Obj_002160a4 *o) { Flag1 f = { 0 }; FUN_00216164(o, o->f4, f); }
