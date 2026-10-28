/* HSTMATCH module=hstp_trans_main.prx start=0x0004495c end=0x000449fc symbol=FUN_0004495c lang=c99 */
/* Clone of src/eboot/decode_compact_value_000447b8.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_0004495c(int unused, short *out, unsigned char *src)
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
