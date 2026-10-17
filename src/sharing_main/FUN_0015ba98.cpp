/* HSTMATCH module=hstp_trans_main.prx start=0x0015ba98 end=0x0015babc symbol=FUN_0015ba98 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0015ba98 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0015bb58(Obj_0015ba98 *o, int v, Flag1 f);
extern "C" void FUN_0015ba98(Obj_0015ba98 *o) { Flag1 f = { 0 }; FUN_0015bb58(o, o->f4, f); }
