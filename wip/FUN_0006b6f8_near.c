/* HSTMATCH module=EBOOT.BIN start=0x0006b6f8 end=0x0006b888 symbol=FUN_0006b6f8 lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Frame 64: ra 28, s3 24, s2 20, s1 16, s0 12, and a 24-byte header object at sp+40
   (f0 40, f4 44, f8 byte 48, fc 52, f10 56, f14 60). a0 = self (s1), a1 = arg (s0); arg->f4 is the anchor node. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Node {            /* 20-byte node */
    u32 f0;                      /* 0 */
    u32 f4;                      /* 4 */
    u32 f8;                      /* 8: pointer with a low colour bit */
    u32 fc;                      /* 12 */
    u32 f10;                     /* 16 */
} Node;

typedef struct Self {
    u8 pad0[8];
    u8 f8;                       /* 8, copied into the header object */
} Self;

typedef struct Arg {
    u32 f0;                      /* 0 */
    Node *f4;                    /* 4: anchor node */
} Arg;

typedef struct Hdr {             /* the 24-byte local at sp+40 */
    u32 f0;                      /* 0 */
    u32 f4;                      /* 4 */
    u8 f8;                       /* 8 */
    u8 pad9[3];
    u32 fc;                      /* 12 */
    u32 f10;                     /* 16 */
    u32 f14;                     /* 20 */
} Hdr;

char DAT_002bc6dc[];

void *FUN_00000bcc(int size);
u32 FUN_0000fe3c(void);
void FUN_0000f3e8(u32 a, char *b);
void FUN_0000d518(void);
void FUN_0006bd24(Hdr *h, u32 it, Node *anchor, int which);
void FUN_0006c894(Self *self, Hdr *h);
void FUN_0006c500(Hdr *h, u32 it);
void FUN_00000a00(void *p);

void FUN_0006b6f8(Self *self, Arg *arg)
{
    Hdr h;
    Node *p;
    u32 base;
    u32 v;

    if (arg->f4 == 0)
        return;

    base = (u32)self + 4;

    p = (Node *)FUN_00000bcc(20);
    if (p == 0) {
        v = FUN_0000fe3c();
        FUN_0000f3e8(*(u32 *)(v + 12), DAT_002bc6dc);
        FUN_0000d518();
    }

    h.f10 = base;
    h.f14 = (u32)p;
    if ((u32)p + 12 != 0) {
        *(u32 *)((u32)p + 12) = *(u32 *)((u32)arg->f4 + 12);
        *(u32 *)((u32)p + 16) = *(u32 *)((u32)arg->f4 + 16);
    }

    h.f0 = 0;
    h.f4 = 0;
    h.f8 = self->f8;
    h.fc = (u32)&h.f4;
    p->f4 = 0;
    p->f0 = 0;
    p->f8 = h.fc | (p->f8 & 1);

    if ((*(u32 *)((u32)arg->f4 + 8) & 1) != 0)
        p->f8 = p->f8 | 1;
    else
        p->f8 = p->f8 & ~1u;

    h.f0 = 1;
    h.f4 = (u32)p;
    h.fc = (u32)p;
    h.f14 = 0;
    if (arg->f4->f4 != 0)
        FUN_0006bd24(&h, h.f4, arg->f4, 0);
    if (arg->f4->f0 != 0)
        FUN_0006bd24(&h, h.f4, arg->f4, 1);

    FUN_0006c894(self, &h);

    if (h.f4 != 0)
        FUN_0006c500(&h, h.f4);
    if (h.f14 != 0)
        FUN_00000a00((void *)h.f14);
}
// MEASURED WALL (100/100 words, 50 differ): every instruction matches but the three live pointers are permuted.
// Ours: p=s0 arg=s1 self=s2 base=s3. Retail: arg=s0 self=s1 p=s2 base=s3. Same relative order (arg<self, base highest);
// only the base moves because MWCC colours the malloc destination `p` first here. Tried: const Arg*, local decl order
// (p/base swapped), blank-line/statement order before the malloc, return type void* instead of Node*, separate
// FUN_000008d8 result variable, by-value header passed first/last. All byte-identical. Allocator tie, not a spelling one.
// near miss from lane dsn2 (unreviewed)
