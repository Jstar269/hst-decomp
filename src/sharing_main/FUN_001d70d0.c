/* HSTMATCH module=hstp_trans_main.prx start=0x001d70d0 end=0x001d7160 symbol=FUN_001d70d0 lang=c99 */
/* Clone of src/eboot/FUN_001c8c3c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

/* Copies a record of 17 floats word by word and returns dst. */
float * FUN_001d70d0(float *dst,float *src)
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
