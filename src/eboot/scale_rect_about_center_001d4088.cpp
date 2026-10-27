/* HSTMATCH module=EBOOT.BIN start=0x001d4088 end=0x001d416c symbol=FUN_001d4088 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rect {
    char pad[4];
    short x0;
    short y0;
    short x1;
    short y1;
};

static inline short MidX(const Rect *r) { return (r->x0 + r->x1) / 2; }
static inline short MidY(const Rect *r) { return (r->y0 + r->y1) / 2; }

extern "C" void FUN_001d4088(Rect *r, float sx, float sy)
{
    short cx = MidX(r);
    r->x0 = (short)((float)cx + sx * (float)(r->x0 - cx));
    r->x1 = (short)((float)cx + sx * (float)(r->x1 - cx));
    short cy = MidY(r);
    r->y0 = (short)((float)cy + sy * (float)(r->y0 - cy));
    r->y1 = (short)((float)cy + sy * (float)(r->y1 - cy));
}
