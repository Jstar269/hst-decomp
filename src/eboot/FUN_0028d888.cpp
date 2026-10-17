/* HSTMATCH module=EBOOT.BIN start=0x0028d888 end=0x0028d8ac symbol=FUN_0028d888 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0028d888 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0028dbd8(Obj_0028d888 *o, int v, Flag1 f);
extern "C" void FUN_0028d888(Obj_0028d888 *o) { Flag1 f = { 0 }; FUN_0028dbd8(o, o->f4, f); }
