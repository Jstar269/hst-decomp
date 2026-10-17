/* HSTMATCH module=EBOOT.BIN start=0x0014ad08 end=0x0014ad2c symbol=FUN_0014ad08 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0014ad08 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0014b87c(Obj_0014ad08 *o, int v, Flag1 f);
extern "C" void FUN_0014ad08(Obj_0014ad08 *o) { Flag1 f = { 0 }; FUN_0014b87c(o, o->f4, f); }
