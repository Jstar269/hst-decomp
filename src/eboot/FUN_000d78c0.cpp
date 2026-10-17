/* HSTMATCH module=EBOOT.BIN start=0x000d78c0 end=0x000d78e4 symbol=FUN_000d78c0 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000d78c0 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000d7ca0(Obj_000d78c0 *o, int v, Flag1 f);
extern "C" void FUN_000d78c0(Obj_000d78c0 *o) { Flag1 f = { 0 }; FUN_000d7ca0(o, o->f4, f); }
