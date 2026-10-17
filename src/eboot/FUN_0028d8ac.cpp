/* HSTMATCH module=EBOOT.BIN start=0x0028d8ac end=0x0028d8d0 symbol=FUN_0028d8ac */
/* Clone of src/eboot/FUN_0027b6dc.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Obj_0028d8ac { int pad; int f4; };
struct Flag1 { signed char v; };
extern "C" void FUN_0028dbc8(Obj_0028d8ac *o, int v, Flag1 f);
extern "C" void FUN_0028d8ac(Obj_0028d8ac *o) { Flag1 f = { 0 }; FUN_0028dbc8(o, o->f4, f); }
