/* HSTMATCH module=EBOOT.BIN start=0x00199b48 end=0x00199c44 symbol=FUN_00199b48 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: base constructor takes the object, 16 floats typed as a Mat4 of four Vec4 rows copied row by row (r0 = G.r0; ... four loads then four stores per row; a whole-struct assignment becomes a copy loop), vtable pointer stored from the symbol address; readability pass; exact match verified; names and types await human review. */
typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Mat4 { Vec4 r0, r1, r2, r3; } Mat4;
typedef struct BgObj {
  void *vtable;                /* 0x00 */
  char pad04[0x58 - 4];
  int unk58;                   /* 0x58 */
  int unk5c;                   /* 0x5c */
  Mat4 matrix;                 /* 0x60 */
} BgObj;
extern Mat4 DAT_002bc410;
extern char DAT_0030926c;
extern void FUN_00102e38(BgObj *);

/* Constructor: base ctor, own vtable, two words cleared and the matrix set from the global identity. */
BgObj *FUN_00199b48(BgObj *self)
{
  FUN_00102e38(self);
  self->vtable = &DAT_0030926c;
  self->unk58 = 0;
  self->unk5c = 0;
  self->matrix.r0 = DAT_002bc410.r0;
  self->matrix.r1 = DAT_002bc410.r1;
  self->matrix.r2 = DAT_002bc410.r2;
  self->matrix.r3 = DAT_002bc410.r3;
  return self;
}
