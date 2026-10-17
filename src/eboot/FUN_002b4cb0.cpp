/* HSTMATCH module=EBOOT.BIN start=0x002b4cb0 end=0x002b4cd4 symbol=FUN_002b4cb0 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_002b4cb0 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_002b4d84(Obj_002b4cb0 *o, int v, Flag1 f);
extern "C" void FUN_002b4cb0(Obj_002b4cb0 *o) { Flag1 f = { 0 }; FUN_002b4d84(o, o->f4, f); }
