/* HSTMATCH module=EBOOT.BIN start=0x0027aadc end=0x0027ab5c symbol=FUN_0027aadc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the five-word tail as floats; exact match verified; readability pass; names and types await human review. */

/* Record of five flag bytes, five integer words and five floats (copied member by member). */
typedef struct {
  unsigned char bytes[5];
  unsigned char padding[3];
  unsigned int words[5];
  float values[5];
} Record;

Record *FUN_0027aadc(Record *dst,Record *src)
{
  dst->bytes[0] = src->bytes[0];
  dst->bytes[1] = src->bytes[1];
  dst->bytes[2] = src->bytes[2];
  dst->bytes[3] = src->bytes[3];
  dst->bytes[4] = src->bytes[4];
  dst->words[0] = src->words[0];
  dst->words[1] = src->words[1];
  dst->words[2] = src->words[2];
  dst->words[3] = src->words[3];
  dst->words[4] = src->words[4];
  dst->values[0] = src->values[0];
  dst->values[1] = src->values[1];
  dst->values[2] = src->values[2];
  dst->values[3] = src->values[3];
  dst->values[4] = src->values[4];
  return dst;
}
