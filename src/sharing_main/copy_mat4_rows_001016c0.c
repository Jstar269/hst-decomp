/* HSTMATCH module=hstp_trans_main.prx start=0x001016c0 end=0x00101748 symbol=FUN_001016c0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies a 4x4 float matrix as four whole-row (4-float) struct assignments (batched lwc1 then swc1 per row)
   and returns the destination. */
struct V4 {
  float x;
  float y;
  float z;
  float w;
};

struct M4 {
  struct V4 r0;
  struct V4 r1;
  struct V4 r2;
  struct V4 r3;
};

struct M4 *FUN_001016c0(struct M4 *dst, struct M4 *src)
{
  dst->r0 = src->r0;
  dst->r1 = src->r1;
  dst->r2 = src->r2;
  dst->r3 = src->r3;
  return dst;
}
