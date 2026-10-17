/* HSTMATCH module=hstp_trans_main.prx start=0x000b8848 end=0x000b886c symbol=FUN_000b8848 */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Obj_000b8848 { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_000bab70(Obj_000b8848 *o, int v, Flag1 f);
extern "C" void FUN_000b8848(Obj_000b8848 *o) { Flag1 f = { 0 }; FUN_000bab70(o, o->f4, f); }
