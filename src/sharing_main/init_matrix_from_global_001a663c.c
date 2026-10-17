/* HSTMATCH module=hstp_trans_main.prx start=0x001a663c end=0x001a6738 symbol=FUN_001a663c lang=c99 */
/* Clone of src/eboot/init_matrix_from_global_00199b48.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: base constructor takes the object, 16 floats typed as a Mat4 of four Vec4 rows copied row by row (r0 = G.r0; ... four loads then four stores per row; a whole-struct assignment becomes a copy loop), vtable pointer stored from the symbol address; exact match verified; names and types await human review. */
typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Mat4 { Vec4 r0, r1, r2, r3; } Mat4;
typedef struct Obj {
  void *vt;
  char pad[0x58 - 4];
  int f58, f5c;
  Mat4 m;
} Obj;
extern Mat4 DAT_002cc260;
extern char DAT_003b2538;
extern void FUN_0010873c(Obj *);

Obj *FUN_001a663c(Obj *o)
{
  FUN_0010873c(o);
  o->vt = &DAT_003b2538;
  o->f58 = 0;
  o->f5c = 0;
  o->m.r0 = DAT_002cc260.r0;
  o->m.r1 = DAT_002cc260.r1;
  o->m.r2 = DAT_002cc260.r2;
  o->m.r3 = DAT_002cc260.r3;
  return o;
}
