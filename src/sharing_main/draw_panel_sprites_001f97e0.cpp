/* HSTMATCH module=hstp_trans_main.prx start=0x001f97e0 end=0x001f9a60 symbol=FUN_001f97e0 lang=c++ */
/* Clone of src/eboot/draw_panel_sprites_001eb504.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: tex pointer (&p->tex) and both panel size fields are loaded into locals before the Rect update; the second pass tests the byte flag again through its own bool temp. */
struct Rect { unsigned color; short x0, y0, x1, y1, z; };
struct Sprite { char pad0[0x60]; float px; float py; char pad1[0x78 - 0x68]; float alpha; };
struct Panel { char pad[0x788]; char tex[8]; int w; int h; };
struct Game { char pad[0x70]; Panel *panel[4]; };
struct Cfg { char pad[0x45]; unsigned char f45; };
struct Self {
    char pad0[0x54];
    Sprite *spr[7];
    Rect *rect[0x2fc / 4 - 0x70 / 4];
    int a[6];
    int b[6];
};

extern "C" {
extern Game *DAT_003e19f0;
extern Cfg *DAT_003e1e84;
void FUN_00105570(void *, int);
void FUN_000f3588(float, float, float, float, float, void *, Rect *, int, int);
void FUN_00108aec(void *);
}

extern "C" void FUN_001f97e0(Self *self)
{
    for (int i = 0; i < 2; i++) {
        bool alt = !DAT_003e1e84->f45;
        int sp = self->a[i + (alt ? 2 : 0)];
        int bi = self->b[i + (alt ? 2 : 0)];
        Panel *p = DAT_003e19f0->panel[i];
        Rect *r = self->rect[bi];
        char *tex = p->tex;
        int w = p->w;
        int h = p->h;
        r->x1 = r->x0 + w;
        r->y1 = r->y0 + h;
        FUN_00105570(r, -12);
        Sprite *s = self->spr[sp];
        r->color = ((unsigned char)(int)(128.0f * s->alpha) << 24) | 0x808080;
        FUN_000f3588(s->px, s->py, 28.0f / (float)w, 1.0f, 1.0f, tex, r, 0, 0);
        bool alt2 = !DAT_003e1e84->f45;
        if (alt2) {
            bi = self->b[i + 4];
            sp = self->a[i + 4];
            p = DAT_003e19f0->panel[i + 2];
            r = self->rect[bi];
            tex = p->tex;
            w = p->w;
            h = p->h;
            r->x1 = r->x0 + w;
            r->y1 = r->y0 + h;
            FUN_00105570(r, -12);
            s = self->spr[sp];
            r->color = ((unsigned char)(int)(128.0f * s->alpha) << 24) | 0x808080;
            FUN_000f3588(s->px, s->py, 28.0f / (float)w, 1.0f, 1.0f, tex, r, 0, 0);
        }
    }
    FUN_00108aec(self);
}
