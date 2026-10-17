/* HSTMATCH module=hstp_trans_main.prx start=0x000ee668 end=0x000ee68c symbol=FUN_000ee668 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000ee668 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000ee8a8(Obj_000ee668 *o, int v, Flag1 f);
extern "C" void FUN_000ee668(Obj_000ee668 *o) { Flag1 f = { 0 }; FUN_000ee8a8(o, o->f4, f); }
