/* HSTMATCH module=EBOOT.BIN start=0x0001d940 end=0x0001d998 symbol=FUN_0001d940 lang=c99 */
/* Clone of src/sharing_main/FUN_0001d58c_0001d58c.c (hstclone.py tag u5cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Vec4 { float x, y, z, w; } Vec4;

extern void FUN_000224f8(Vec4 *out, int a, int b);
extern float FUN_000224d8(const Vec4 *a, const Vec4 *b);
extern float FUN_00022e44(float value);

void FUN_0001d940(int param_1, int param_2)
{
  Vec4 second;
  Vec4 first;
  float length;

  FUN_000224f8(&first, param_1, param_2);
  second.x = first.x;
  second.y = first.y;
  second.z = first.z;
  second.w = first.w;
  length = FUN_000224d8(&second, &second);
  FUN_00022e44(length);
}
