/* HSTMATCH module=hstp_trans_main.prx start=0x001728d8 end=0x001728fc symbol=FUN_001728d8 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Obj_001728d8 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00172b90(Obj_001728d8 *o, int v, Flag1 f);
extern "C" void FUN_001728d8(Obj_001728d8 *o) { Flag1 f = { 0 }; FUN_00172b90(o, o->f4, f); }
