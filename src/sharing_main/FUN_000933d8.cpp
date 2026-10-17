/* HSTMATCH module=hstp_trans_main.prx start=0x000933d8 end=0x000933fc symbol=FUN_000933d8 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000933d8 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_00093498(Obj_000933d8 *o, int v, Flag1 f);
extern "C" void FUN_000933d8(Obj_000933d8 *o) { Flag1 f = { 0 }; FUN_00093498(o, o->f4, f); }
