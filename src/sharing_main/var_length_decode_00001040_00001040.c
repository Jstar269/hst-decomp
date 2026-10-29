/* HSTMATCH module=hstp_trans_main.prx start=0x00001040 end=0x000010dc symbol=FUN_00001040 lang=c99 */
/* Clone of src/eboot/var_length_decode_00001040.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Decodes a variable-length value: the low bits of the first byte flag how many bytes follow (1 to 4); the top bits of
   the first byte are the most significant part. Matching idiom: p[1]/p[2] are read into locals before the length tests. */
unsigned char *FUN_00001040(unsigned char *p, unsigned *out)
{
    unsigned b = p[0];
    unsigned b1, b2;
    if ((b & 1) == 0) {
        *out = b >> 1;
        return p + 1;
    }
    b1 = p[1];
    if ((b & 2) == 0) {
        *out = ((b >> 2) << 8) | b1;
        return p + 2;
    }
    b2 = p[2];
    if ((b & 4) == 0) {
        *out = ((b >> 3) << 16) | (b1 << 8) | b2;
        return p + 3;
    }
    *out = ((b >> 3) << 24) | (b1 << 16) | (b2 << 8) | p[3];
    return p + 4;
}
