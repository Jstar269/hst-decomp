/* HSTMATCH module=EBOOT.BIN start=0x002296a0 end=0x00229774 symbol=FUN_002296a0 lang=c99 */

typedef struct {
  unsigned int a;
  unsigned int b;
} Item;

extern void FUN_00229774(void *self);
extern unsigned char *FUN_0004cad0(void *data, int *size, int n, int m);
extern void FUN_00229af0(void *out, void *dst, Item *item);
extern void FUN_000104e0(void *p);

int FUN_002296a0(void *self, void *data)
{
  unsigned char *buf;
  unsigned char *p;
  int size;

  FUN_00229774(self);
  buf = FUN_0004cad0(data, &size, 16, 1);
  if (buf == 0)
    return 0;
  if (size <= 0)
    return 0;
  for (p = buf; p < buf + size; p += 8) {
    Item item;
    void *out;
    item.a = (*(unsigned short *)p << 16) | *(unsigned short *)(p + 2);
    item.b = *(unsigned int *)(p + 4);
    FUN_00229af0(&out, (char *)self + 16, &item);
  }
  FUN_000104e0(buf);
  return 1;
}
// 1 word short (54/53 words, frame and stack slots now match): retail keeps self in s1 from entry,
// buf in s0 and the walker in s2 and recomputes `addiu a1,s1,16` inside the loop; this source hoists
// self+16 into s0 and colours self to s3. Tried: Item/void* out (fixed the 64->48 frame), out declared
// outside the loop, `p < buf + size` vs a cached end, size initialised/not initialised.
// near miss from lane ds6 (unreviewed)
