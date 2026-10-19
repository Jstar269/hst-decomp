/* HSTMATCH module=EBOOT.BIN start=0x0015a3cc end=0x0015a4c8 symbol=FUN_0015a3cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: `off + (int)base` (named offset, int cast) for retail's index-first `addu v0,v0,a0`; the trailing float argument is 65533.0f. */

struct Tag4 { unsigned char c[4]; };

struct Elem16 {
    char pad[0x40];
    float fx;
    float fy;
};

struct Obj {
    char pad[8];
    int w;
    int h;
};

extern "C" void FUN_00051490(void *p, int a, int b, int c, int d, int e, int f);
extern "C" void FUN_00051894(void *p, Tag4 t, float a, float b, float c, float d,
                             float e, float f, float g, float h, float i);
extern "C" void FUN_0005185c(void *p);

extern "C" void FUN_0015a3cc(void *arr, struct Obj *obj, int idx)
{
    Tag4 tag;
    tag.c[0] = 0x80;
    tag.c[1] = 0x80;
    tag.c[2] = 0x80;
    tag.c[3] = 0x80;
    int off = idx * 0x10;
    Elem16 *e = (Elem16 *)(off + (int)arr);
    int x = (int)e->fx;
    int w = obj->w;
    int h = obj->h;
    int y = (int)e->fy;

    FUN_00051490(obj, 0, 0, 480, 272, 0, 0);
    FUN_00051894(obj, tag, 0.0f, 0.0f, (float)x, (float)y, (float)w, (float)h,
                 (float)(x + w), (float)(y + h), 65533.0f);
    FUN_0005185c(obj);
}
