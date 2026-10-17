/* HSTMATCH module=EBOOT.BIN start=0x0010c69c end=0x0010cd24 symbol=FUN_0010c69c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Release-build twin of src/sharing_main/sprite_pulse_00112a80.cpp: the sprite.h GetSprite() assertion
   (line 1014) compiles out here. */

extern "C" float FUN_0000bf34(float);   /* sinf/cosf (SDK libm) */
extern int DAT_002d9220;

#define HST_ASSERT(cond, text, file, line) ((void)0)

struct Sprite {                 /* 0x2c bytes */
    unsigned int color;         /* 0xAABBGGRR */
    short x0;
    short y0;
    short x1;
    short y1;
    short z;
    unsigned short flags;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    Sprite();
};

struct SpriteSet {
    char pad0[0x10];
    Sprite **sprites;
    int count;
    char pad18[0xea - 0x18];
    unsigned char flag;
    int GetSpriteNum() const { return count; }
    Sprite *GetSprite(int sprite_index)
    {
        HST_ASSERT(sprite_index >= 0 && sprite_index < GetSpriteNum(), "", "sprite.h", 1014);
        return sprites[sprite_index];
    }
};

struct Pulse {
    SpriteSet *set;
    int pad4;
    int counter;
    int index;
    Sprite normal;              /* +0x10 */
    Sprite active;              /* +0x3c */
    int mode;                   /* +0x68 */
};

static inline int Min(const int &a, const int &b) { return b < a ? b : a; }

/* adds d to the R, G and B channels (each wrapping in 8 bits) */
static inline void AddColor(Sprite *s, short d)
{
    s->color = (s->color & 0xffffff00) | (unsigned char)((s->color & 0xff) + d);
    s->color = (s->color & 0xffff00ff) | ((unsigned char)(((s->color >> 8) & 0xff) + d) << 8);
    s->color = (s->color & 0xff00ffff) | ((unsigned char)(((s->color >> 16) & 0xff) + d) << 16);
}

/* scales the rectangle by k around its centre */
static inline void Inflate(Sprite *s, float k)
{
    short w = s->x1 - s->x0;
    short h = s->y1 - s->y0;
    short dw = (short)(w * k - w) / 2;
    s->x0 -= dw;
    s->x1 += dw;
    short dh = (short)(h * k - h) / 2;
    s->y0 -= dh;
    s->y1 += dh;
}

static inline float Half(float s) { return 0.5f * (1.0f + s); }

extern "C" void FUN_0010c69c(Pulse *self, int sel)
{
    if (self->set->GetSprite(self->index)->flags & 3)
        return;
    if (self->set->flag)
        self->counter = 3;
    Sprite *a = self->set->GetSprite(self->index);
    Sprite *b = self->set->GetSprite(self->index + 1);
    *a = self->normal;
    *b = self->active;
    Sprite *s = sel ? b : a;
    if (self->mode == 0) {
        int n = Min(self->counter, DAT_002d9220);
        float v = FUN_0000bf34(6.2831855f * (float)((n + 18) % 21) / 21.0f);
        float k = 1.0f + v * (n < 14 ? 0.2f : 0.1f);
        float t = Half(FUN_0000bf34(6.2831855f * (float)((self->counter + 18) % 21) / 21.0f));
        AddColor(s, (short)(32.0f * t));
        Inflate(s, k);
        AddColor(s, (short)(64.0f * Half(t)));
    } else if (self->mode == 1) {
        float t = Half(FUN_0000bf34(6.2831855f * (float)(self->counter % 4) / 4.0f));
        AddColor(s, (short)(32.0f * t));
        Inflate(s, 1.25f);
        AddColor(s, (short)(64.0f * Half(t)));
    }
    self->counter++;
}
