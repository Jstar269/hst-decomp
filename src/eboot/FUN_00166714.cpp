/* HSTMATCH module=EBOOT.BIN start=0x00166714 end=0x00166738 symbol=FUN_00166714 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_00166714 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_001669cc(Obj_00166714 *o, int v, Flag1 f);
extern "C" void FUN_00166714(Obj_00166714 *o) { Flag1 f = { 0 }; FUN_001669cc(o, o->f4, f); }
