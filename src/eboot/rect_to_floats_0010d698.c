/* HSTMATCH module=EBOOT.BIN start=0x0010d698 end=0x0010d6e4 symbol=FUN_0010d698 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared rect shorts in standard order and computed w, h before float assignments; exact match verified; names and types await human review. */

struct RectSrc {
    char pad[16];
    short x;
    short y;
    short x2;
    short y2;
    short z;
};

struct Dst {
    char pad0[96];
    float fx;
    float fy;
    float fz;
    char pad1[256 - 108];
    short w;
    short h;
};

void FUN_0010d698(struct Dst *dest, const struct RectSrc *src)
{
    short x = src->x;
    short y = src->y;
    short x2 = src->x2;
    short y2 = src->y2;
    short z = src->z;
    float fx = x;
    short w = x2 - x;
    short h = y2 - y;
    dest->w = w;
    dest->h = h;
    dest->fx = fx;
    dest->fy = y;
    dest->fz = z;
}
