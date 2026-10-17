/* HSTMATCH module=hstp_trans_main.prx start=0x0014a820 end=0x0014a844 symbol=FUN_0014a820 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0014a820 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0014b17c(Obj_0014a820 *o, int v, Flag1 f);
extern "C" void FUN_0014a820(Obj_0014a820 *o) { Flag1 f = { 0 }; FUN_0014b17c(o, o->f4, f); }
