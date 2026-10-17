/* HSTMATCH module=EBOOT.BIN start=0x000d78e4 end=0x000d7908 symbol=FUN_000d78e4 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000d78e4 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000d7c90(Obj_000d78e4 *o, int v, Flag1 f);
extern "C" void FUN_000d78e4(Obj_000d78e4 *o) { Flag1 f = { 0 }; FUN_000d7c90(o, o->f4, f); }
