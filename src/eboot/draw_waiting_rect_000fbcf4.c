/* HSTMATCH module=EBOOT.BIN start=0x000fbcf4 end=0x000fbec8 symbol=FUN_000fbcf4 lang=c99 data=0x002d8344 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d8344-0x002d8354) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/mode_screen.h"
#include "hst/game_mode_state.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272

/* Packed colour split into bytes. */
struct Color {
    unsigned char r, g, b, a;
};

/* Layout rectangle: packed colour, corner coordinates and depth. */
struct Rect {
    unsigned color;
    short x0, y0, x1, y1, z;
};

extern GameModeState *DAT_003386b0;
extern int DAT_002d8278;

extern void *FUN_001039d8(void *, void *, int);
extern struct Rect *FUN_001026b8(void *, const char *);
extern void FUN_00051490(void *tex, int, int, int, int, int, int);
extern void FUN_00051894(void *tex, struct Color col, float u0, float v0, float x0, float y0, float u1, float v1, float x1, float y1, float z);
extern void FUN_0005185c(void *tex);

/* Draw the rectangle r with tex at (px, py), scaled by `scale` and stretched by (ax, ay). */
static inline void DrawRect(float px, float py, float scale, float ax, float ay, void *tex, struct Rect *r, int u, int v)
{
    unsigned c = r->color;
    struct Color col;
    col.r = c;
    col.g = c >> 8;
    col.b = c >> 16;
    col.a = c >> 24;
    int w = r->x1 - r->x0;
    int h = r->y1 - r->y0;
    int ix = (int)(px + (float)r->x0 + ((1.0f - ax) * (float)w) / 2.0f);
    int iy = (int)(py + (float)r->y0 + ((1.0f - ay) * (float)h) / 2.0f);
    FUN_00051490(tex, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    FUN_00051894(tex, col, (float)u, (float)v, (float)ix, (float)iy, (float)(u + w), (float)(v + h),
                 (float)ix + ax * ((float)w * scale), (float)iy + ay * ((float)h * scale), (float)r->z);
    FUN_0005185c(tex);
}

/* Draw the "waiting" rectangle of the screen's layout with the texture selected by the timer. */
void FUN_000fbcf4(ModeScreen *s)
{
    if (DAT_003386b0->flag == 0) return;
    if (s->core == 0) return;
    if (s->active == 0) return;

    void *handle = FUN_001039d8(s->core, "main", 0);
    struct Rect *r = FUN_001026b8(handle, "waiting");
    void *tex = s->slot[s->timer / DAT_002d8278];

    DrawRect(0.0f, 0.0f, 1.0f, 1.0f, 1.0f, tex, r, 0, 0);
}
