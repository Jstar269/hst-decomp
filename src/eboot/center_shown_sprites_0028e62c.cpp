/* HSTMATCH module=EBOOT.BIN start=0x0028e62c end=0x0028e750 symbol=FUN_0028e62c lang=c++ */
/* Clone of src/sharing_main/center_shown_sprites_0029fdf4.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sprite {
    char pad[4];
    short x0;
    short y0;
    short x1;
    short y1;
    short fc;
    unsigned short flags;
};

struct Obj {
    char pad0[0x1b9c];
    Sprite *s1b9c;
    Sprite *s1ba0;
    Sprite *s1ba4;
    Sprite *s1ba8;
    short f1bac;
    short x1bae;
    short f1bb0;
    short x1bb2;
    Sprite *s1bb4;
};

extern "C" void FUN_000ffb3c(Sprite *s, int on);

static inline bool IsShown(const Sprite *s) { return (s->flags & 3) != 0; }
static inline short Width(const Sprite *s) { return s->x1 - s->x0; }

static inline void SetX(Sprite *s, short x)
{
    short d = x - s->x0;
    s->x0 = x;
    s->x1 += d;
}

static inline void MoveX(Sprite *s, short d)
{
    s->x0 += d;
    s->x1 += d;
}

extern "C" void FUN_0028e62c(Obj *self)
{
    FUN_000ffb3c(self->s1bb4, 0);
    if (IsShown(self->s1b9c)) {
        SetX(self->s1ba0, self->x1bae);
        MoveX(self->s1ba0, -Width(self->s1ba0) / 2);
    }
    if (IsShown(self->s1ba4)) {
        SetX(self->s1ba8, self->x1bb2);
        MoveX(self->s1ba8, -Width(self->s1ba8) / 2);
    }
}
