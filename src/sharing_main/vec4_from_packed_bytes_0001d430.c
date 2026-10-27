/* HSTMATCH module=hstp_trans_main.prx start=0x0001d430 end=0x0001d4f4 symbol=FUN_0001d430 lang=c99 */
/* Hand-written reconstruction from the disassembly (the four bytes of a packed 32-bit value, high byte first, converted as unsigned to the four floats of a Vec4; `(c >> k) & 0xff` gives the ext); exact match verified; names and types await human review. */
typedef struct Vec4 {
  float x;
  float y;
  float z;
  float w;
} Vec4;

void FUN_0001d430(Vec4 *out, unsigned int c)
{
  out->x = (float)((c >> 24) & 0xff);
  out->y = (float)((c >> 16) & 0xff);
  out->z = (float)((c >> 8) & 0xff);
  out->w = (float)(c & 0xff);
}
