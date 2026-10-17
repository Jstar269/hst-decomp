/* HSTMATCH module=hstp_trans_main.prx start=0x0005931c end=0x000593a4 symbol=FUN_0005931c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies 16 floats (a 4x4 matrix) element by element (interleaved lwc1/swc1) and returns the destination. */
struct Mat16 {
  float m[16];
};

struct Mat16 *FUN_0005931c(struct Mat16 *dst, struct Mat16 *src)
{
  dst->m[0] = src->m[0];
  dst->m[1] = src->m[1];
  dst->m[2] = src->m[2];
  dst->m[3] = src->m[3];
  dst->m[4] = src->m[4];
  dst->m[5] = src->m[5];
  dst->m[6] = src->m[6];
  dst->m[7] = src->m[7];
  dst->m[8] = src->m[8];
  dst->m[9] = src->m[9];
  dst->m[10] = src->m[10];
  dst->m[11] = src->m[11];
  dst->m[12] = src->m[12];
  dst->m[13] = src->m[13];
  dst->m[14] = src->m[14];
  dst->m[15] = src->m[15];
  return dst;
}
