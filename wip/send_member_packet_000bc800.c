/* HSTMATCH module=EBOOT.BIN start=0x000bc800 end=0x000bc99c symbol=FUN_000bc800 lang=c99 */
/* NEAR MISS 102/103 words, 47 differing: retail keeps the used-count in a1 (ours a3), the name copy loads
   with lb (ours lbu), and the send result is copied to a1 before `bgez` (ours tests v0). Body layout, stack
   frame, header/entry structs and the do/while pair copy all match. */
extern char DAT_002d53a4[];
extern char DAT_002d53c4[];

extern void FUN_00011090(void *, const void *, int);
extern void FUN_000ba3ac(void *, ...);
extern int FUN_000bdb14(void *, int, void *, unsigned short, void *, int, int, int);

typedef struct Name {
  char c[6];
} Name;

typedef struct Hdr {
  int f0;
  int size;
  float x;
  float y;
  int count;
} Hdr;

typedef struct Entry {
  Name name;
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
  char *dst;
  int count;
  int i;
  int k;
  int r;
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
  float fx = self->f27c;
  float fy = self->f280;
  hdr.y = fy;
  hdr.x = fx;
  size = count * 0x10 + 0x14;
  hdr.size = size;
  hdr.count = count;

  dst = (char *)self->f188;
  FUN_00011090(dst, &hdr, 0x14);
  dst += 0x14;
  for (n = 0, p = (unsigned char *)self; n < 16; n++, p += 7) {
    if (p[0x5e]) {
      entry.name = *(Name *)(p + 0x58);
      entry.idx = n;
      entry.flag = self->f21c[n];
      FUN_00011090(dst, &entry, 0x10);
      dst += 0x10;
    }
  }

  for (n = 0, p = (unsigned char *)self; n < 16; n++, p += 7) {
    if (p[0x5e] && n != self->f198) {
      r = FUN_000bdb14(self, self->f17c, p + 0x58, (unsigned)self->f10, (void *)self->f188, size, 0, 1);
      if (r < 0)
        FUN_000ba3ac(DAT_002d53a4, r);
    }
  }
  FUN_000ba3ac(DAT_002d53c4);
}
// sy4 NEAR MISS 18 words differ (of 103): fixed vs the earlier wip: the name pair copy is `Name{char c[6]}` struct assignment (3 passes of lb/lb/sb/sb,
// src pointer bumped first), the stub is variadic `FUN_000ba3ac(fmt, r)`, hdr built from float locals declared fy-then-fx after `hdr.f0 = 0;` so
// count stays in a1 and the lwc1/swc1 prologue matches. Still different: retail's loop-control temps (flag lbu, slti, f198 lw) are in v1 not v0 in both pair loops;
// `lw a1,380 / lhu a3,16` argument load order (lhu first); and `move a1,v0` before `bgez a1` (r coalesced into a1).
// Ruled out: r declared at top/first/last/in-block, reusing k, struct Rec[16] loops (24), flag in an unsigned char local.
// sy4 update: (unsigned)self->f10 cast + `void *msg, ...` stub prototype + `void *` 5th param (as in send_cmd_msg_000bcc88.c) -> 16 words differ, all of: the swc1/sw order of the hdr stores
// (retail swc1 68, swc1 72, sw a1,76), loop-control temps in v1 instead of v0 in both pair loops, and `move a1,v0` before `bgez a1` (r coalesced into a1).
// improved by lane sy4 (unreviewed): 47 -> 16 differing words
