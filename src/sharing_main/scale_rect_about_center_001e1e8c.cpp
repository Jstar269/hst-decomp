/* HSTMATCH module=hstp_trans_main.prx start=0x001e1e8c end=0x001e1f70 symbol=FUN_001e1e8c lang=c++ */
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

extern "C" void FUN_001e1e8c(Rect *r, float sx, float sy)
{
    short cx = MidX(r);
    r->x0 = (short)((float)cx + sx * (float)(r->x0 - cx));
    r->x1 = (short)((float)cx + sx * (float)(r->x1 - cx));
    short cy = MidY(r);
    r->y0 = (short)((float)cy + sy * (float)(r->y0 - cy));
    r->y1 = (short)((float)cy + sy * (float)(r->y1 - cy));
}
