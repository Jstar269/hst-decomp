/* HSTMATCH module=hstp_trans_main.prx start=0x0004ae50 end=0x0004af74 symbol=FUN_0004ae50 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* collision.cpp (assert strings): sample a 4-bit attribute map at normalised (x, y) and map it through the 16-entry lookup table. */
extern const char DAT_00376028[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_0037612c[];   /* "0 <= u" */
extern const char DAT_00376134[];   /* "0 <= v" */
extern const char DAT_0037613c[];   /* "alut[index] != 255" */
extern const char DAT_00376060[];   /* "collision.cpp" */
extern "C" void FUN_0004ae24(...);
#define HST_ASSERT(cond, text, line) do { if (!(cond)) { FUN_0004ae24(DAT_00376028, text, DAT_00376060, line); for (;;) {} } } while (0)

struct AttrMap {
    int width;                  /* 0x00 */
    int height;                 /* 0x04 */
    int stride;                 /* 0x08 */
    unsigned char alut[16];     /* 0x0c */
    unsigned char *data;        /* 0x1c */
};

extern "C" unsigned char FUN_0004ae50(float x, float y, AttrMap *map)
{
    int u = (int)(x * map->width);
    int v = (int)(y * map->height);
    HST_ASSERT(0 <= u, DAT_0037612c, 0x115);
    HST_ASSERT(0 <= v, DAT_00376134, 0x116);
    if (u >= map->width) u = map->width - 1;
    if (v >= map->height) v = map->height - 1;
    int index = map->data[(u >> 1) + v * map->stride];
    if (u & 1) index >>= 4;
    index &= 0xf;
    HST_ASSERT(map->alut[index] != 255, DAT_0037613c, 0x121);
    return map->alut[index];
}
