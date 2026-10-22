/* HSTMATCH module=EBOOT.BIN start=0x0001d900 end=0x0001d940 symbol=FUN_0001d900 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies the 16-byte float vector to the stack and hands its first and third components to the
   helper FUN_000c6dc. Names provisional. */
typedef struct {
  float x;
  float y;
  float z;
  float w;
} Vec4;

extern void FUN_0000c6dc(float, float);

void FUN_0001d900(Vec4 *v)
{
  Vec4 t = *v;
  FUN_0000c6dc(t.x, t.z);
}
