/* HSTMATCH module=EBOOT.BIN start=0x00128d8c end=0x00128e40 symbol=FUN_00128d8c lang=c99 */
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

extern void FUN_00022434(Vec4 *out, Vec4 *a, Vec4 *b);
extern void FUN_00022518(Vec4 *out, Vec4 *in);
extern float FUN_0000c6dc(float a, float b);
extern void FUN_0012aa1c(Obj *self);

void FUN_00128d8c(Obj *self)
{
  Vec4 reordered;
  Vec4 result;
  Vec4 difference;

  if (self->active != 0) {
    FUN_00022434(&difference, &self->next, &self->current);
    reordered.x = difference.x;
    reordered.y = difference.y;
    reordered.z = difference.z;
    reordered.w = difference.w;
    self->previous = self->angle;
    FUN_00022518(&result, &reordered);
    result.w = 0.0f;
    self->angle = FUN_0000c6dc(result.x, result.z);
    self->next.x = self->current.x;
    self->next.y = self->current.y;
    self->next.z = self->current.z;
    self->next.w = self->current.w;
    self->active = 0;
  }
  FUN_0012aa1c(self);
  self->previous = self->angle;
}
