/* HSTMATCH module=EBOOT.BIN start=0x000bc800 end=0x000bc99c symbol=FUN_000bc800 lang=c99 */
/* NEAR MISS 102/103 words, 47 differing: retail keeps the used-count in a1 (ours a3), the name copy loads
   with lb (ours lbu), and the send result is copied to a1 before `bgez` (ours tests v0). Body layout, stack
   frame, header/entry structs and the do/while pair copy all match. */
extern const char DAT_002d53a4[];
extern const char DAT_002d53c4[];

extern void FUN_00011090(void *, const void *, int);
extern void FUN_000ba3ac(const char *);
extern int FUN_000bdb14(void *, int, void *, unsigned short, int, int, int, int);

typedef struct Pair {
  signed char c0;
  signed char c1;
} Pair;

typedef struct Hdr {
  int f0;
  int size;
  float x;
  float y;
  int count;
} Hdr;

typedef struct Entry {
  Pair name[3];
  int idx;
  unsigned char flag;
  char pad[3];
} Entry;

typedef struct Obj {
  char pad0[0x10];
  unsigned short f10;
  char pad1[0x58 - 0x12];
  char rec[16 * 7];
  char pad2[0x17c - (0x58 + 16 * 7)];
  int f17c;
  char pad3[0x188 - 0x180];
  int f188;
  char pad4[0x198 - 0x18c];
  int f198;
  char pad5[0x21c - 0x19c];
  unsigned char f21c[16];
  char pad6[0x27c - 0x22c];
  float f27c;
  float f280;
} Obj;

void FUN_000bc800(Obj *self)
{
  int size;
  Hdr hdr;
  Entry entry;
  Pair *src;
  Pair *d;
  Pair *dst;
  int count;
  int i;
  int k;
  int n;
  unsigned char *p;

  if (self->f188 == 0)
    return;

  count = 0;
  for (i = 0; i < 16; i++) {
    if (((unsigned char *)self)[i * 7 + 0x5e])
      count++;
  }

  hdr.f0 = 0;
  hdr.x = self->f27c;
  hdr.y = self->f280;
  size = count * 0x10 + 0x14;
  hdr.size = size;
  hdr.count = count;

  dst = (Pair *)self->f188;
  FUN_00011090(dst, &hdr, 0x14);
  dst += 0x14 / sizeof(Pair);
  for (n = 0, p = (unsigned char *)self; n < 16; n++, p += 7) {
    if (p[0x5e]) {
      src = (Pair *)(p + 0x58);
      d = (Pair *)entry.name;
      k = 3;
      do {
        *d++ = *src++;
      } while (--k > 0);
      entry.idx = n;
      entry.flag = self->f21c[n];
      FUN_00011090(dst, &entry, 0x10);
      dst += 0x10 / sizeof(Pair);
    }
  }

  for (n = 0, p = (unsigned char *)self; n < 16; n++, p += 7) {
    if (p[0x5e] && n != self->f198) {
      k = FUN_000bdb14(self, self->f17c, p + 0x58, self->f10, self->f188, size, 0, 1);
      if (k < 0)
        FUN_000ba3ac(DAT_002d53a4);
    }
  }
  FUN_000ba3ac(DAT_002d53c4);
}
// near miss from lane fm7 (unreviewed)
