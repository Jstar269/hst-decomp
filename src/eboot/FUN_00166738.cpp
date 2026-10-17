/* HSTMATCH module=EBOOT.BIN start=0x00166738 end=0x0016675c symbol=FUN_00166738 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_00166738 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_001669bc(Obj_00166738 *o, int v, Flag1 f);
extern "C" void FUN_00166738(Obj_00166738 *o) { Flag1 f = { 0 }; FUN_001669bc(o, o->f4, f); }
