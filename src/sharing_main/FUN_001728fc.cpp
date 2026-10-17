/* HSTMATCH module=hstp_trans_main.prx start=0x001728fc end=0x00172920 symbol=FUN_001728fc */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Obj_001728fc { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00172b80(Obj_001728fc *o, int v, Flag1 f);
extern "C" void FUN_001728fc(Obj_001728fc *o) { Flag1 f = { 0 }; FUN_00172b80(o, o->f4, f); }
