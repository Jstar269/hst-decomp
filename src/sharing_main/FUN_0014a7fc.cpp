/* HSTMATCH module=hstp_trans_main.prx start=0x0014a7fc end=0x0014a820 symbol=FUN_0014a7fc */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0014a7fc { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0014b18c(Obj_0014a7fc *o, int v, Flag1 f);
extern "C" void FUN_0014a7fc(Obj_0014a7fc *o) { Flag1 f = { 0 }; FUN_0014b18c(o, o->f4, f); }
