/* HSTMATCH module=EBOOT.BIN start=0x000dac88 end=0x000dacc0 symbol=FUN_000dac88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

/* Pair of a halfword and a second part copied by FUN_000dacc0 (its type is not visible here). */
typedef struct ShortPair {
  short first;   /* 0x00 */
  short pad02;
  int second;    /* 0x04 */
} ShortPair;

extern void * FUN_000dacc0();

/* Copy constructor of the pair. */
ShortPair * FUN_000dac88(ShortPair *dst,ShortPair *src)
{
  dst->first = src->first;
  FUN_000dacc0(&dst->second,&src->second);
  return dst;
}
