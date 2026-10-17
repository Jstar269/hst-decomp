/* HSTMATCH module=hstp_trans_main.prx start=0x000917c8 end=0x000918c8 symbol=FUN_000917c8 lang=c99 */
/* Clone of src/eboot/struct_copy_0008fbc8.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restructured as a struct whose words at +0x38..0x40 and +0x80/+0x84 are int (lw/sw) while the rest are float (lwc1/swc1); exact match verified; names and types await human review. */
typedef struct S {
  float a[14];
  int b[3];
  int pad[3];
  float c[12];
  int d[2];
} S;

S *FUN_000917c8(S *dst, S *src)
{
  dst->a[0] = src->a[0];
  dst->a[1] = src->a[1];
  dst->a[2] = src->a[2];
  dst->a[3] = src->a[3];
  dst->a[4] = src->a[4];
  dst->a[5] = src->a[5];
  dst->a[6] = src->a[6];
  dst->a[7] = src->a[7];
  dst->a[8] = src->a[8];
  dst->a[9] = src->a[9];
  dst->a[10] = src->a[10];
  dst->a[11] = src->a[11];
  dst->a[12] = src->a[12];
  dst->a[13] = src->a[13];
  dst->b[0] = src->b[0];
  dst->b[1] = src->b[1];
  dst->b[2] = src->b[2];
  dst->c[0] = src->c[0];
  dst->c[1] = src->c[1];
  dst->c[2] = src->c[2];
  dst->c[3] = src->c[3];
  dst->c[4] = src->c[4];
  dst->c[5] = src->c[5];
  dst->c[6] = src->c[6];
  dst->c[7] = src->c[7];
  dst->c[8] = src->c[8];
  dst->c[9] = src->c[9];
  dst->c[10] = src->c[10];
  dst->c[11] = src->c[11];
  dst->d[0] = src->d[0];
  dst->d[1] = src->d[1];
  return dst;
}
