/* HSTMATCH module=EBOOT.BIN start=0x00001040 end=0x000010dc symbol=FUN_00001040 lang=c99 */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
/* Decodes a variable length little-endian value: the first byte carries the length flags in its low
   bits and the top bits of the value; one to four bytes are consumed depending on the flags.
   The 4-byte case keeps the flag bit that was just tested ((b & 4) << 24), which is why the shift
   source is the tested value and not a fresh shift of b.
   Names provisional. */
unsigned char *FUN_00001040(unsigned char *p, unsigned *out)
{
  unsigned b = p[0];
  if (b & 1) goto L2;
  *out = b >> 1;
  return p + 1;
L2:
  if (b & 2) goto L3;
  *out = (unsigned)p[1] | ((b >> 2) << 8);
  return p + 2;
L3:
  if (b & 4) goto L4;
  *out = (unsigned)p[2] | ((unsigned)p[1] << 8) | ((b >> 3) << 16);
  return p + 3;
L4:
  *out = (unsigned)p[3] | ((unsigned)p[2] << 8) | ((unsigned)p[1] << 16) | ((b & 4) << 24);
  return p + 4;
}
// near miss from lane km1 (unreviewed)
