/* HSTMATCH module=EBOOT.BIN start=0x00091740 end=0x00091764 symbol=FUN_00091740 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_00091740 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00091800(Obj_00091740 *o, int v, Flag1 f);
extern "C" void FUN_00091740(Obj_00091740 *o) { Flag1 f = { 0 }; FUN_00091800(o, o->f4, f); }
