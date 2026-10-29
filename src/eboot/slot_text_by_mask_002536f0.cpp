/* HSTMATCH module=EBOOT.BIN start=0x002536f0 end=0x0025395c symbol=FUN_002536f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the loop keeps a separate widget counter `k` (retail walks a pointer bumped by 4 with the +16 displacement left in the access); the inlined bit test takes an unused by-value empty Tag, which only reserves the hidden never-written stack slot that makes retail's frame 48 bytes (any single hidden slot gives it); `none()` is `!any()` so the empty test is the materialised `(mask != 0) ^ 1`. */
#include "hst/text_bank_lookup.h"

extern char DAT_002fcc74[];
extern char DAT_002c6a78[];

struct Widget {
    char pad[0x24];
    int unk24;
    int unk28;
    char pad2[0xf8 - 0x2c];
    const char *text;
    char pad3[0x138 - 0xfc];
    int dirty;
};
struct Reent { int pad[3]; void *err; }; /* per-thread C library state; err is the stderr stream */

extern "C" {
TextBank *FUN_0018c9f4(int);
void FUN_0010d4a8(Widget *);
Reent *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
}

struct Tag {};
struct Bits32 {
    unsigned bits;
    bool any() const { return bits != 0; }
    bool none() const { return !any(); }
    unsigned count() const
    {
        unsigned x = bits;
        x = x - ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x + (x >> 4)) & 0x0f0f0f0f;
        x = x + (x >> 8);
        return (x + (x >> 16)) & 0xff;
    }
    bool test(unsigned pos, Tag) const
    {
        if (pos >= 32) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c6a78);
            FUN_0000d518();
        }
        return (bits & (1u << pos)) != 0;
    }
};

/* Selection mask (one bit per entry of group 1 of text bank 9) and the widgets that show it. */
struct Self {
    Bits32 mask;
    Widget *rangeA;
    Widget *rangeB;
    int base;
    Widget *labels[2];
};

static inline void SetRange(Widget *w, int v)
{
    w->unk24 = v;
    w->unk28 = v;
}

static inline void SetText(Widget *w, const char *s, int dirty)
{
    w->text = s;
    w->dirty = dirty;
    FUN_0010d4a8(w);
}

/* Shows the labels of the selected entries (up to two) and sets the range widgets to base or base + 1 accordingly. */
extern "C" void FUN_002536f0(Self *self)
{
    TextBank *bank = FUN_0018c9f4(9);
    int n = bank->groups[1].count;
    if (self->mask.none()) {
        SetRange(self->rangeA, self->base + 1);
        SetRange(self->rangeB, self->base + 1);
        SetText(self->labels[0], DAT_002fcc74, 0);
        SetText(self->labels[1], DAT_002fcc74, 0);
    } else {
        if (self->mask.count() == 1) {
            SetRange(self->rangeA, self->base);
            SetRange(self->rangeB, self->base + 1);
            SetText(self->labels[1], DAT_002fcc74, 0);
        } else {
            SetRange(self->rangeA, self->base);
            SetRange(self->rangeB, self->base);
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (self->mask.test(i, Tag())) {
                const char *s = TextGet(FUN_0018c9f4(9), 1, i + 1);
                SetText(self->labels[k], s, 1);
                k++;
            }
        }
    }
}
