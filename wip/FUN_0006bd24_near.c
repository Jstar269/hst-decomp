/* HSTMATCH module=EBOOT.BIN start=0x0006bd24 end=0x0006bed4 symbol=FUN_0006bd24 lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Frame 48: ra 28, s5 24, s4 20, s3 16, s2 12, s1 8, s0 4, and an 8-byte local pair at
   sp+40 (self+4) / sp+44 (the new node). a0 = the tree header (count at 0, an embedded sentinel node at +4),
   a1 = parent node, a2 = source node, a3 = side (0 = left, 1 = right). Node = left, right, parent|colour bit,
   then a 2-word payload at +12. */
typedef unsigned int u32;

typedef struct Node {
    u32 f0;                      /* 0: left */
    u32 f4;                      /* 4: right */
    u32 f8;                      /* 8: parent with the colour in bit 0 */
    u32 fc;                      /* 12: payload word 0 */
    u32 f10;                     /* 16: payload word 1 */
} Node;

typedef struct Tree {
    u32 f0;                      /* 0: node count */
    u32 f4;                      /* 4: sentinel node left */
    u32 f8;                      /* 8: sentinel right */
    u32 fc;                      /* 12: sentinel parent (the root) */
    u32 f10;                     /* 16 */
    u32 f14;                     /* 20 */
} Tree;
typedef struct Guard {           /* the 8-byte local pair at sp+40 */
    u32 *slot;
    Node *node;
} Guard;


char DAT_002bc6dc[];

void *FUN_00000bcc(int size);
u32 FUN_0000fe3c(void);
void FUN_0000f3e8(u32 a, char *b);
void FUN_0000d518(void);
void FUN_00000a00(void *p);

void FUN_0006bd24(Tree *self, Node *parent, Node *src, int side)
{
    Node *p;
    Node *old;
    u32 at;
    u32 red;
    Guard g;

    p = (Node *)FUN_00000bcc(20);
    if (p == 0) {
        FUN_0000f3e8(*(u32 *)(FUN_0000fe3c() + 12), DAT_002bc6dc);
        FUN_0000d518();
    }
    p->f4 = 0;
    p->f0 = 0;
    g = (Guard){ (u32 *)at, p };

    p->f8 = (p->f8 & 1) | (u32)parent;

    if (side != 0) {
        old = (Node *)src->f0;
        if ((u32)p + 12 != 0) {
            *(u32 *)((u32)p + 12) = *(u32 *)((u32)old + 12);
            *(u32 *)((u32)p + 16) = *(u32 *)((u32)old + 16);
        }
        self->fc = (u32)p;
        *(u32 *)((u32)parent + 0) = (u32)p;
        old = (Node *)src->f0;
        g.node = 0;
    } else {
        old = (Node *)src->f4;
        if ((u32)p + 12 != 0) {
            *(u32 *)((u32)p + 12) = *(u32 *)((u32)old + 12);
            *(u32 *)((u32)p + 16) = *(u32 *)((u32)old + 16);
        }
        *(u32 *)((u32)parent + 4) = (u32)p;
        old = (Node *)src->f4;
        g.node = 0;
    }

    red = (old->f8 & 1) != 0;
    if (red)
        p->f8 = p->f8 | 1;
    else
        p->f8 = p->f8 & ~1u;

    self->f0 = self->f0 + 1;

    if (parent->f4 != 0)
        FUN_0006bd24(self, parent, old, 0);
    if (parent->f0 != 0)
        FUN_0006bd24(self, parent, old, 1);

    if (g.node != 0)
        FUN_00000a00(g.node);
}
// MEASURED WALL (107/108 words, 85 differ, first at +0x1c). Shape is the real one (see the note above the body:
// a3 != 0 is the LEFT path; the recursion descends into the child that was copied, not into the source, and the
// parent variable carries the new node). Two things are left:
//  (1) retail's dead 8-byte guard at sp+40/sp+44 -- 40 holds self+4 and is NEVER read, 44 holds the new node and is
//      zeroed once it is linked. A plain local `u32 at` is deleted by dead-store elimination; an address-taken struct
//      keeps it but MWCC then materialises &g in a register (103 words); an aggregate compound-literal assignment
//      restores the frame and s5 but costs a zeroing loop (106). Only a single `sw s5,40(sp)` survives in retail, so
//      the source object must be address-taken with direct sp-relative accesses, which this MWCC will not emit here.
//  (2) saved-register colouring: retail s4=self s3=parent s2=src/old s1=side s0=p s5=self+4; ours shifts by one or
//      two depending on the guard spelling. Same class of tie as 0x6b6f8.
// Pass 14: the missing word is reachable but is NOT the blocker. Spellings that restore `sw s5,40(sp)`:
//   aggregate compound literal (k/l)  107/108, 85 differ
//   address-taken guard, single cast store (o/p) 107/108, 85 differ
//   struct local with only the slot field stored through its address (i) 102/108
//   two volatile homed locals `volatile u32 at; Node *volatile own;` (s) 104/108 - but self loses its saved
//   register and a second reload pair appears; non-volatile homed locals (t) 98/108.
// Retail's p/self/parent/src colours come out right only in the PLAIN version (95/108: s4=self s3=parent s2=src
// s0=side s1=p vs retail s1=side s0=p) - i.e. exactly the side/p swap of the 0x6b6f8 family. Every spelling that
// homes the guard also permutes the whole saved set, so the 84-word gap tracks the guard spelling, not the code.
// near miss from lane dsn2 (unreviewed)
