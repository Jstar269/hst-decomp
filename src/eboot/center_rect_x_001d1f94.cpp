/* HSTMATCH module=EBOOT.BIN start=0x001d1f94 end=0x001d1fe0 symbol=FUN_001d1f94 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: inline Width(const Rect *) and SetLeft(Rect *, short) helpers (matching recenter_rects_0026b2f0.cpp); exact match verified; names and types await human review. */
struct Rect_001d1f94 {
    char pad[4];
    short x0;
    short y0;
    short x1;
    short y1;
};

static inline short Width(const Rect_001d1f94 *r)
{
    return r->x1 - r->x0;
}

static inline void SetLeft(Rect_001d1f94 *r, short nx)
{
    short d = nx - r->x0;
    r->x0 = nx;
    r->x1 = r->x1 + d;
}

extern "C" void FUN_001d1f94(Rect_001d1f94 *r, short c)
{
    int w = Width(r);
    SetLeft(r, c - w / 2);
}
