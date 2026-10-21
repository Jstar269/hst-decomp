/* HSTMATCH module=hstp_trans_main.prx start=0x00231a6c end=0x00231c28 symbol=FUN_00231a6c lang=c++ */
/* Clone of src/eboot/draw_sprite_list_002224f8.cpp (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: Tex *t declared at function scope between i and the walking pointer (saved-register order i > t > s); x0/y0 kept as ints across the first draw call; the 48-byte stride walks the pointer by a char cast because the fields reach +0x3c; names and types await human review. */
struct Tag4 { unsigned char c[4]; };

struct Tex {
    char pad[8];
    int w;
    int h;
};

struct Sprite {
    char pad0[0x20];
    unsigned char enabled;
    char pad1[3];
    Tex *tex;
    char pad2[4];
    float alpha;
    float scale;
    char pad3[4];
    int cx;
    int cy;
    char pad4[4];
};

extern "C" void FUN_00051e30(void *p, int a, int b, int c, int d, int e, int f);
extern "C" void FUN_00052354(void *p, Tag4 t, float a, float b, float c, float d,
                             float e, float f, float g, float h, float i);
extern "C" void FUN_000522c0(void *p);

extern "C" void FUN_00231a6c(Sprite *sp)
{
    int i = 0;
    Tex *t;
    Sprite *s = sp;
    do {
        if (s->enabled != 0 && s->alpha > 0.0f) {
            Tag4 tag;
            tag.c[0] = 0x80;
            tag.c[1] = 0x80;
            tag.c[2] = 0x80;
            float a = s->alpha * 128.0f;
            t = s->tex;
            tag.c[3] = (unsigned int)a;
            int w = t->w;
            int cx = s->cx;
            int h = t->h;
            int cy = s->cy;
            float fw = (float)w * s->scale;
            int x0 = (int)((float)cx - fw / 2.0f);
            float fh = (float)h * s->scale;
            int y0 = (int)((float)cy - fh / 2.0f);
            FUN_00051e30(t, 0, 0, 480, 272, 0, 0);
            FUN_00052354(t, tag, 0.0f, 0.0f, (float)x0, (float)y0, (float)w, (float)h, (float)x0 + fw, (float)y0 + fh, 65535.0f);
            FUN_000522c0(t);
        }
        i++;
        s = (Sprite *)((char *)s + 0x30);
    } while (i < 16);
}
