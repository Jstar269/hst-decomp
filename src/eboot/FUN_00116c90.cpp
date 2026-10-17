/* HSTMATCH module=EBOOT.BIN start=0x00116c90 end=0x00116cb4 symbol=FUN_00116c90 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_00116c90 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00116e2c(Obj_00116c90 *o, int v, Flag1 f);
extern "C" void FUN_00116c90(Obj_00116c90 *o) { Flag1 f = { 0 }; FUN_00116e2c(o, o->f4, f); }
