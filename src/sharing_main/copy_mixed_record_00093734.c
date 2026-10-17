/* HSTMATCH module=hstp_trans_main.prx start=0x00093734 end=0x0009378c symbol=FUN_00093734 lang=c99 */
/* Clone of src/eboot/copy_mixed_record_00091a9c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
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

S91a9c *FUN_00093734(S91a9c *dst, S91a9c *src)
{
  dst->a = src->a;
  dst->b = src->b;
  dst->c = src->c;
  dst->d = src->d;
  dst->e = src->e;
  return dst;
}
