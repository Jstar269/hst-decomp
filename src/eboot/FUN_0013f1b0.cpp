/* HSTMATCH module=EBOOT.BIN start=0x0013f1b0 end=0x0013f1d4 symbol=FUN_0013f1b0 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0013f1b0 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0013fb40(Obj_0013f1b0 *o, int v, Flag1 f);
extern "C" void FUN_0013f1b0(Obj_0013f1b0 *o) { Flag1 f = { 0 }; FUN_0013fb40(o, o->f4, f); }
