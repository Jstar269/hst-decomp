/* HSTMATCH module=EBOOT.BIN start=0x0014fa98 end=0x0014fabc symbol=FUN_0014fa98 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0014fa98 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0014fb58(Obj_0014fa98 *o, int v, Flag1 f);
extern "C" void FUN_0014fa98(Obj_0014fa98 *o) { Flag1 f = { 0 }; FUN_0014fb58(o, o->f4, f); }
