/* HSTMATCH module=EBOOT.BIN start=0x001a87d0 end=0x001a87f4 symbol=FUN_001a87d0 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_001a87d0 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_001a8fb8(Obj_001a87d0 *o, int v, Flag1 f);
extern "C" void FUN_001a87d0(Obj_001a87d0 *o) { Flag1 f = { 0 }; FUN_001a8fb8(o, o->f4, f); }
