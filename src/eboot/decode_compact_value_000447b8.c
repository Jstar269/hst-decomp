/* HSTMATCH module=EBOOT.BIN start=0x000447b8 end=0x00044858 symbol=FUN_000447b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_000447b8(int unused, short *out, unsigned char *src)
{
  int b = src[0];
  int hi = b & 0xf0;
  if (hi != 0xf0) {
    if (hi != 0xe0) {
      if (hi != 0xd0 && hi != 0xc0) {
        *out = b & 0x7f;
        return 1;
      }
      *out = ((b & 0x1f) << 6) + (src[1] & 0x3f);
      return 2;
    }
    *out = ((b & 0x0f) << 12) + ((src[1] & 0x3f) << 6) + (src[2] & 0x3f);
    return 3;
  }
  *out = 0;
  return 1;
}
