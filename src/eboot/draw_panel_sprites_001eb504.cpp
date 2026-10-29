/* HSTMATCH module=EBOOT.BIN start=0x001eb504 end=0x001eb784 symbol=FUN_001eb504 lang=c++ */
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
extern Game *DAT_003386b0;
extern Cfg *DAT_00338b44;
void FUN_000ffc3c(void *, int);
void FUN_000edec0(float, float, float, float, float, void *, Rect *, int, int);
void FUN_001031e8(void *);
}

/* Draws the two panel sprites per player (and the alternate pair when the config byte is clear), then calls FUN_001031e8. */
extern "C" void FUN_001eb504(Self *self)
{
    for (int i = 0; i < 2; i++) {
        bool alt = !DAT_00338b44->f45;
        int sp = self->a[i + (alt ? 2 : 0)];
        int bi = self->b[i + (alt ? 2 : 0)];
        Panel *p = DAT_003386b0->panel[i];
        Rect *r = self->rect[bi];
        char *tex = p->tex;
        int w = p->w;
        int h = p->h;
        r->x1 = r->x0 + w;
        r->y1 = r->y0 + h;
        FUN_000ffc3c(r, -12);
        Sprite *s = self->spr[sp];
        r->color = ((unsigned char)(int)(128.0f * s->alpha) << 24) | 0x808080;
        FUN_000edec0(s->px, s->py, 28.0f / (float)w, 1.0f, 1.0f, tex, r, 0, 0);
        bool alt2 = !DAT_00338b44->f45;
        if (alt2) {
            bi = self->b[i + 4];
            sp = self->a[i + 4];
            p = DAT_003386b0->panel[i + 2];
            r = self->rect[bi];
            tex = p->tex;
            w = p->w;
            h = p->h;
            r->x1 = r->x0 + w;
            r->y1 = r->y0 + h;
            FUN_000ffc3c(r, -12);
            s = self->spr[sp];
            r->color = ((unsigned char)(int)(128.0f * s->alpha) << 24) | 0x808080;
            FUN_000edec0(s->px, s->py, 28.0f / (float)w, 1.0f, 1.0f, tex, r, 0, 0);
        }
    }
    FUN_001031e8(self);
}
