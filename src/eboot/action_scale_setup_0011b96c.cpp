/* HSTMATCH module=EBOOT.BIN start=0x0011b96c end=0x0011bab8 symbol=FUN_0011b96c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Debug-flag gated update: after a global subsystem check, writes the same value into both words of the target, a scale in [0..1] derived from the countdown, an intensity from the current entry and one more scale into the layer, then flushes and advances the handler. */
#include "hst/tick_obj.h"

extern unsigned DAT_002d5ab0;
extern void *DAT_00338c20;
extern int DAT_002da0cc[];
extern "C" int FUN_000fb7b8(void *o);
extern "C" void FUN_00103480(void *o);

#define DEBUG_FLAG_ENABLE 0x800
#define LEVEL_ONE 0x80 /* fixed-point one used for the scale */
#define TABLE_INDEX_BASE 2

/* Target whose first two words past 0x24 receive the value. */
struct Target {
    char pad0[0x24];
    int a;                  /* 0x24 */
    int b;                  /* 0x28 */
};

/* Layer object: virtual methods, a float at 0x64 and a float at 0x78. */
struct LayerObj {
    virtual void s0();
    virtual void s1(int n);
    virtual void s2();
    virtual void s3();
    char pad0[0x60];
    float value64;          /* 0x64 */
    char pad1[0x10];
    float scale78;          /* 0x78 */
};

/* Node held by the owner at 0x40: a target, a layer object and a second target. */
struct Node {
    void *flushed;          /* 0x0 flushed and advanced at the end */
    LayerObj *layer;        /* 0x4 */
    Target *target;         /* 0x8 */
};

/* Owner object seen through its node pointer. */
struct OwnerNode {
    char pad0[0x40];
    Node *node;             /* 0x40 */
};

extern "C" void FUN_0011b96c(TickObj *self)
{
    if ((DAT_002d5ab0 & DEBUG_FLAG_ENABLE) != 0) {
        if (DAT_00338c20 != 0) {
            if (FUN_000fb7b8(DAT_00338c20) != 0)
                return;
        }
        if (self->unkc8 == 0) {
            Node *node = ((OwnerNode *)self->owner)->node;
            void *flushed = node->flushed;
            int *table = DAT_002da0cc;
            node->layer->s1(0);
            Target *target = node->target;
            int mode = self->cur.kind;
            int base;
            switch (mode) {
            case 0:
            case 1:
                base = 0;
                break;
            }
            int value = base + table[TABLE_INDEX_BASE];
            target->a = value;
            target->b = value;
            int level = LEVEL_ONE;
            if (self->countdown < 6)
                level *= (float)self->countdown / 5.0f;
            LayerObj *layer = node->layer;
            float intensity = self->cur.value;
            layer->value64 = intensity;
            layer->scale78 = (float)level / 128.0f;
            FUN_00103480(flushed);
            ((LayerObj *)flushed)->s3();
        }
    }
}
