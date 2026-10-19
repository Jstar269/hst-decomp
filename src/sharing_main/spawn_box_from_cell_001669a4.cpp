/* HSTMATCH module=hstp_trans_main.prx start=0x001669a4 end=0x00166aa0 symbol=FUN_001669a4 lang=c++ */
/* Clone of src/eboot/spawn_box_from_cell_0015a3cc.cpp (hstclone.py tag s10181937g6r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_00051e30(void *p, int a, int b, int c, int d, int e, int f);
extern "C" void FUN_00052354(void *p, Tag4 t, float a, float b, float c, float d,
                             float e, float f, float g, float h, float i);
extern "C" void FUN_000522c0(void *p);

extern "C" void FUN_001669a4(void *arr, struct Obj *obj, int idx)
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

    FUN_00051e30(obj, 0, 0, 480, 272, 0, 0);
    FUN_00052354(obj, tag, 0.0f, 0.0f, (float)x, (float)y, (float)w, (float)h,
                 (float)(x + w), (float)(y + h), 65533.0f);
    FUN_000522c0(obj);
}
