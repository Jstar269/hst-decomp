/* HSTMATCH module=hstp_trans_main.prx start=0x001dfd98 end=0x001dfde4 symbol=FUN_001dfd98 lang=c++ */
/* Clone of src/eboot/center_rect_x_001d1f94.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: inline Width(const Rect *) and SetLeft(Rect *, short) helpers (matching recenter_rects_0026b2f0.cpp); exact match verified; names and types await human review. */
struct Rect_001dfd98 {
    char pad[4];
    short x0;
    short y0;
    short x1;
    short y1;
};

static inline short Width(const Rect_001dfd98 *r)
{
    return r->x1 - r->x0;
}

static inline void SetLeft(Rect_001dfd98 *r, short nx)
{
    short d = nx - r->x0;
    r->x0 = nx;
    r->x1 = r->x1 + d;
}

extern "C" void FUN_001dfd98(Rect_001dfd98 *r, short c)
{
    int w = Width(r);
    SetLeft(r, c - w / 2);
}
