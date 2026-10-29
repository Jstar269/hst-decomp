/* HSTMATCH module=hstp_trans_main.prx start=0x0017602c end=0x00176064 symbol=FUN_0017602c lang=c99 */
/* Clone of src/eboot/FUN_00169e68.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

typedef struct Span {
  float lo;         /* 0x00 */
  float hi;         /* 0x04 */
  float mid;        /* 0x08 midpoint of lo and hi */
  float extra;      /* 0x0c */
} Span;

/* Fills a span from a low bound, a high bound and an extra value; the midpoint is computed. */
void FUN_0017602c(Span *out,float *lo,float *hi,float *extra)
{
  out->lo = *lo;
  out->hi = *hi;
  out->extra = *extra;
  out->mid = (*hi + *lo) / 2.0f;
}
