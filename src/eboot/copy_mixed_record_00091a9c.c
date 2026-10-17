/* HSTMATCH module=EBOOT.BIN start=0x00091a9c end=0x00091af4 symbol=FUN_00091a9c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct S91a9c4 {
  float x;
  float y;
  float z;
  float w;
} S91a9c4;

typedef struct S91a9c3 {
  float x;
  float y;
  float z;
} S91a9c3;

typedef struct S91a9c {
  S91a9c4 a;
  S91a9c3 b;
  float c;
  unsigned int d;
  unsigned int e;
} S91a9c;

S91a9c *FUN_00091a9c(S91a9c *dst, S91a9c *src)
{
  dst->a = src->a;
  dst->b = src->b;
  dst->c = src->c;
  dst->d = src->d;
  dst->e = src->e;
  return dst;
}
