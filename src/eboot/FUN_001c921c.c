/* HSTMATCH module=EBOOT.BIN start=0x001c921c end=0x001c92ac symbol=FUN_001c921c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

/* Copies a block of 17 floats (field by field) and returns the destination. */
float * FUN_001c921c(float *dst,float *src)
{
  *dst = *src;
  dst[1] = src[1];
  dst[2] = src[2];
  dst[3] = src[3];
  dst[4] = src[4];
  dst[5] = src[5];
  dst[6] = src[6];
  dst[7] = src[7];
  dst[8] = src[8];
  dst[9] = src[9];
  dst[10] = src[10];
  dst[0xb] = src[0xb];
  dst[0xc] = src[0xc];
  dst[0xd] = src[0xd];
  dst[0xe] = src[0xe];
  dst[0xf] = src[0xf];
  dst[0x10] = src[0x10];
  return dst;
}
