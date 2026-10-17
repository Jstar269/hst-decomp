/* HSTMATCH module=EBOOT.BIN start=0x000e9570 end=0x000e9594 symbol=FUN_000e9570 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000e9570 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000e984c(Obj_000e9570 *o, int v, Flag1 f);
extern "C" void FUN_000e9570(Obj_000e9570 *o) { Flag1 f = { 0 }; FUN_000e984c(o, o->f4, f); }
