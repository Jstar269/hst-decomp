/* HSTMATCH module=EBOOT.BIN start=0x00169e68 end=0x00169ea0 symbol=FUN_00169e68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct Span {
  float lo;         /* 0x00 */
  float hi;         /* 0x04 */
  float mid;        /* 0x08 midpoint of lo and hi */
  float extra;      /* 0x0c */
} Span;

/* Fills a span from a low bound, a high bound and an extra value; the midpoint is computed. */
void FUN_00169e68(Span *out,float *lo,float *hi,float *extra)
{
  out->lo = *lo;
  out->hi = *hi;
  out->extra = *extra;
  out->mid = (*hi + *lo) / 2.0f;
}
