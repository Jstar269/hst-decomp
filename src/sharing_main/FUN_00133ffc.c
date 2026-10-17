/* HSTMATCH module=hstp_trans_main.prx start=0x00133ffc end=0x001340b0 symbol=FUN_00133ffc lang=c99 */
/* Clone of src/eboot/FUN_00128d8c.c (hstclone.py tag s10171846c1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed float vectors and arranged the copy and previous-value store to match the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined1;
typedef struct { float x, y, z, w; } Vec4;
typedef struct {
  undefined1 pad0[0x1b0];
  Vec4 current;
  undefined1 pad1[0x10];
  Vec4 next;
  unsigned char active;
  undefined1 pad2[3];
  float angle;
  float previous;
} Obj;

extern void FUN_0002245c(Vec4 *out, Vec4 *a, Vec4 *b);
extern void FUN_00022540(Vec4 *out, Vec4 *in);
extern float FUN_0000c6f4(float a, float b);
extern void FUN_00135e88(Obj *self);

void FUN_00133ffc(Obj *self)
{
  Vec4 reordered;
  Vec4 result;
  Vec4 difference;

  if (self->active != 0) {
    FUN_0002245c(&difference, &self->next, &self->current);
    reordered.x = difference.x;
    reordered.y = difference.y;
    reordered.z = difference.z;
    reordered.w = difference.w;
    self->previous = self->angle;
    FUN_00022540(&result, &reordered);
    result.w = 0.0f;
    self->angle = FUN_0000c6f4(result.x, result.z);
    self->next.x = self->current.x;
    self->next.y = self->current.y;
    self->next.z = self->current.z;
    self->next.w = self->current.w;
    self->active = 0;
  }
  FUN_00135e88(self);
  self->previous = self->angle;
}
