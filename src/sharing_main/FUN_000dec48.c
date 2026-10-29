/* HSTMATCH module=hstp_trans_main.prx start=0x000dec48 end=0x000dec80 symbol=FUN_000dec48 lang=c99 */
/* Clone of src/eboot/FUN_000dac88.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

/* Pair of a halfword and a second part copied by FUN_000dec80 (its type is not visible here). */
typedef struct ShortPair {
  short first;   /* 0x00 */
  short pad02;
  int second;    /* 0x04 */
} ShortPair;

extern void * FUN_000dec80();

/* Copy constructor of the pair. */
ShortPair * FUN_000dec48(ShortPair *dst,ShortPair *src)
{
  dst->first = src->first;
  FUN_000dec80(&dst->second,&src->second);
  return dst;
}
