/* HSTMATCH module=EBOOT.BIN start=0x00108c60 end=0x00108c84 symbol=FUN_00108c60 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_00108c60 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0010a350(Obj_00108c60 *o, int v, Flag1 f);
extern "C" void FUN_00108c60(Obj_00108c60 *o) { Flag1 f = { 0 }; FUN_0010a350(o, o->f4, f); }
