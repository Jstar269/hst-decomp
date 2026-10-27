/* HSTMATCH module=EBOOT.BIN start=0x0001d7e4 end=0x0001d8a8 symbol=FUN_0001d7e4 lang=c99 */
/* Clone of src/sharing_main/vec4_from_packed_bytes_0001d430.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (the four bytes of a packed 32-bit value, high byte first, converted as unsigned to the four floats of a Vec4; `(c >> k) & 0xff` gives the ext); exact match verified; names and types await human review. */
typedef struct Vec4 {
  float x;
  float y;
  float z;
  float w;
} Vec4;

void FUN_0001d7e4(Vec4 *out, unsigned int c)
{
  out->x = (float)((c >> 24) & 0xff);
  out->y = (float)((c >> 16) & 0xff);
  out->z = (float)((c >> 8) & 0xff);
  out->w = (float)(c & 0xff);
}
