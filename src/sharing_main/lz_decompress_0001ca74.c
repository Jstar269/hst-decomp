/* HSTMATCH module=hstp_trans_main.prx start=0x0001ca74 end=0x0001cb60 symbol=FUN_0001ca74 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* LZ-style decoder: a tag byte with low bits 00 starts a literal run of (tag >> 2) + 1 bytes; otherwise
   bit 0 selects a 2-byte (len 3..10, 12-bit distance) or 3-byte (len 3..1026, 20-bit distance) back reference. */
void FUN_0001ca74(unsigned char *dst, const unsigned char *src, int size)
{
  unsigned char *end = dst + size;
  while (dst < end) {
    unsigned int c = *src++;
    if ((c & 3) == 0) {
      int n = (c >> 2) + 1;
      while (n-- > 0) *dst++ = *src++;
    } else {
      unsigned char *p;
      int n;
      if ((c & 1) == 1) {
        unsigned int v = c + (src[0] << 8);
        n = ((v >> 1) & 7) + 3;
        p = dst - (v >> 4);
        src += 1;
      } else {
        unsigned int v = c + ((src[0] << 8) + (src[1] << 16));
        n = ((v >> 2) & 0x3ff) + 3;
        p = dst - (v >> 12);
        src += 2;
      }
      while (n-- > 0) *dst++ = *p++;
    }
  }
}
