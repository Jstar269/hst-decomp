/* HSTMATCH module=hstp_trans_main.prx start=0x0001d54c end=0x0001d58c symbol=FUN_0001d54c lang=c99 */
/* Clone of src/eboot/vec4_pass_xz_0001d900.c (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies the 16-byte float vector to the stack and hands its first and third components to the
   helper FUN_000c6dc. Names provisional. */
typedef struct {
  float x;
  float y;
  float z;
  float w;
} Vec4;

extern void FUN_0000c6f4(float, float);

void FUN_0001d54c(Vec4 *v)
{
  Vec4 t = *v;
  FUN_0000c6f4(t.x, t.z);
}
