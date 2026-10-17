/* HSTMATCH module=hstp_trans_main.prx start=0x0001d58c end=0x0001d5e4 symbol=FUN_0001d58c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Vec4 { float x, y, z, w; } Vec4;

extern void FUN_00022520(Vec4 *out, int a, int b);
extern float FUN_00022500(const Vec4 *a, const Vec4 *b);
extern float FUN_00022e6c(float value);

void FUN_0001d58c(int param_1, int param_2)
{
  Vec4 second;
  Vec4 first;
  float length;

  FUN_00022520(&first, param_1, param_2);
  second.x = first.x;
  second.y = first.y;
  second.z = first.z;
  second.w = first.w;
  length = FUN_00022500(&second, &second);
  FUN_00022e6c(length);
}
