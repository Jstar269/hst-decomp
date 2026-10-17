/* HSTMATCH module=EBOOT.BIN start=0x00238940 end=0x00238964 symbol=FUN_00238940 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_00238940 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00238c0c(Obj_00238940 *o, int v, Flag1 f);
extern "C" void FUN_00238940(Obj_00238940 *o) { Flag1 f = { 0 }; FUN_00238c0c(o, o->f4, f); }
