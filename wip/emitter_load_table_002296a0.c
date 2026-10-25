/* HSTMATCH module=EBOOT.BIN start=0x002296a0 end=0x00229774 symbol=FUN_002296a0 lang=c99 */

typedef struct {
  unsigned int a;
  unsigned int b;
} Item;

typedef struct {
  unsigned char pad[16];
  unsigned char child[1];
} Owner;

extern void FUN_00229774(void *self);
extern unsigned char *FUN_0004cad0(void *data, int *size, int n, int m);
extern void FUN_00229af0(void *out, void *dst, Item *item);
extern void FUN_000104e0(void *p);

int FUN_002296a0(unsigned short *arg0, Owner *arg1)
{
  unsigned char *p;
  Owner *self = (Owner *)arg0;
  unsigned short *data = (unsigned short *)arg1;
  int size;
  unsigned char out[12];

  FUN_00229774(self);
  data = (unsigned short *)FUN_0004cad0(data, &size, 16, 1);
  if (data == 0)
    return 0;
  if (size <= 0)
    return 0;
  p = (unsigned char *)data;
  if (p < (unsigned char *)data + size) {
    do {
      Item item;
      item.a = ((unsigned int)*(unsigned short *)p << 16) | *(unsigned short *)(p + 2);
      item.b = *(unsigned int *)(p + 4);
      p += 8;
      FUN_00229af0(out, self->child, &item);
    } while (p < (unsigned char *)data + size);
  }
  FUN_000104e0(data);
  return 1;
}
// Best after 15 hstmatch compiles: 31/53 words differ. The stack frame, callee-saved set, input-buffer
// register, and scratch slots match. A byte cursor with p += 8 gives the right loop extent and item
// layout; the remaining main mismatch is the object and cursor colours (s2/s1 swapped against retail),
// plus the null-return branch layout and instruction scheduling inside the loop. Tried separate and
// shared result forms, direct returns, char/short cursor types, preloaded halfword, owner-field pointer,
// and declaration/statement order. No exact match; parked at the lane's 15-compile limit.
// improved by lane lnm1 (unreviewed): 50 -> 31 differing words
