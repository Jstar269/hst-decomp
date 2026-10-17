/* HSTMATCH module=EBOOT.BIN start=0x00247674 end=0x00247810 symbol=FUN_00247674 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies the 64-byte matrix argument into a local (block-copy loop), stores it row by row into two matrix members (plain-C Vec4 assignments give the batched lwc1/swc1 rows), replaces its last row with the Vec4 at +0x40, then calls 0x55044 on the sub-object at +0xe0 and, unless the word at +0x454 is 0x96 or 0x97, on the one at +0x290. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct { Vec4 r0, r1, r2, r3; } Mat4;
typedef struct {
  char pad0[0x40];
  Vec4 v40;
  char pad1[0x10];
  Mat4 m60;
  Mat4 ma0;
  char pade0[0x374];
  int f454;
} Obj;
extern void FUN_00055044(void *, Mat4 *);

void FUN_00247674(Obj *o, Mat4 *src)
{
  Mat4 m = *src;
  o->m60.r0 = m.r0;
  o->m60.r1 = m.r1;
  o->m60.r2 = m.r2;
  o->m60.r3 = m.r3;
  o->ma0.r0 = m.r0;
  o->ma0.r1 = m.r1;
  o->ma0.r2 = m.r2;
  o->ma0.r3 = m.r3;
  m.r3.x = o->v40.x;
  m.r3.y = o->v40.y;
  m.r3.z = o->v40.z;
  m.r3.w = o->v40.w;
  FUN_00055044((char *)o + 0xe0, &m);
  if (o->f454 != 0x96 && o->f454 != 0x97) {
    FUN_00055044((char *)o + 0x290, &m);
  }
}
