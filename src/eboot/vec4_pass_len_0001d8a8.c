/* HSTMATCH module=EBOOT.BIN start=0x0001d8a8 end=0x0001d900 symbol=FUN_0001d8a8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies the 16-byte float vector to the stack and hands the negated second component and the length
   of the (first, third) 2D part to the helper FUN_000c6dc. Names provisional. */
typedef struct {
  float x;
  float y;
  float z;
  float w;
} Vec4;

extern void FUN_0000c6dc(float, float);
extern float sqrtf(float);

void FUN_0001d8a8(Vec4 *v)
{
  Vec4 t = *v;
  FUN_0000c6dc(-t.y, sqrtf(t.x * t.x + t.z * t.z));
}
