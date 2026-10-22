/* HSTMATCH module=hstp_trans_main.prx start=0x000010dc end=0x00001178 symbol=FUN_000010dc lang=c++ */
/* Clone of src/eboot/unpack_varint_000010dc.cpp (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern "C" char *FUN_000010dc(char *p, unsigned *out)
{
  int v = *p;
  if ((v & 1) == 0) {
    *out = v >> 1;
    return p + 1;
  }
  unsigned b1 = (unsigned char)p[1];
  if ((v & 2) == 0) {
    *out = ((v >> 2) << 8) | b1;
    return p + 2;
  }
  unsigned b2 = (unsigned char)p[2];
  if ((v & 4) == 0) {
    *out = ((v >> 3) << 16) | (b1 << 8) | b2;
    return p + 3;
  }
  *out = ((v >> 3) << 24) | (b1 << 16) | (b2 << 8) | (unsigned char)p[3];
  return p + 4;
}
