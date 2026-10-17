/* HSTMATCH module=EBOOT.BIN start=0x00199b48 end=0x00199c44 symbol=FUN_00199b48 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: base constructor takes the object, 16 floats typed as a Mat4 of four Vec4 rows copied row by row (r0 = G.r0; ... four loads then four stores per row; a whole-struct assignment becomes a copy loop), vtable pointer stored from the symbol address; exact match verified; names and types await human review. */
typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Mat4 { Vec4 r0, r1, r2, r3; } Mat4;
typedef struct Obj {
  void *vt;
  char pad[0x58 - 4];
  int f58, f5c;
  Mat4 m;
} Obj;
extern Mat4 DAT_002bc410;
extern char DAT_0030926c;
extern void FUN_00102e38(Obj *);

Obj *FUN_00199b48(Obj *o)
{
  FUN_00102e38(o);
  o->vt = &DAT_0030926c;
  o->f58 = 0;
  o->f5c = 0;
  o->m.r0 = DAT_002bc410.r0;
  o->m.r1 = DAT_002bc410.r1;
  o->m.r2 = DAT_002bc410.r2;
  o->m.r3 = DAT_002bc410.r3;
  return o;
}
