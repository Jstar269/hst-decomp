/* HSTMATCH module=EBOOT.BIN start=0x0021e520 end=0x0021e90c symbol=FUN_0021e520 lang=c++ */
struct Sprite {
    unsigned int color;
    short x0;
    short y0;
    short x1;
    short y1;
};

struct Anim {
    virtual void a0();
    virtual void a1();
    virtual void Update();
};

struct Item {
    virtual void i0();
    virtual void Show(int);
};

struct Row {
    void *label;
    void *value;
    char pad[0x10];
};

struct Hud {
    char pad0[0x60];
    Row rows[3];
    char pad1[4];
    Item *items[3];
    Sprite *spr[9];
    int left[9];
    int right[9];
    int top[9];
    int bottom[9];
    char pad2[0x174 - 0x16c];
    Anim anim;
    char pad3[0x1c8 - 0x178];
    int sel;
    int rank;
    char pad4[0x1e8 - 0x1d0];
    int frame;
};

extern "C" {
extern const float DAT_002f087c;
extern const float DAT_002f0880;
extern const float DAT_002f0884;
extern const float DAT_002f0888;
extern const int DAT_002f088c[16];
extern const float DAT_002f08cc;
extern const float DAT_002f08d0;
void FUN_000ffb3c(void *, int);
}

inline int Curve(int k)
{
    if (k < 16)
        return DAT_002f088c[k];
    return 128;
}

extern "C" void FUN_0021e520(Hud *self)
{
    self->anim.Update();
    int n = self->frame;
    float dur = DAT_002f087c;
    self->frame = n + 1;
    float t = self->frame;
    if (t >= dur) {
        self->items[self->sel]->Show(1);
        FUN_000ffb3c(self->rows[self->sel].label, self->rank < 10);
        FUN_000ffb3c(self->rows[self->sel].value, 0);
    } else {
        int i = self->sel * 3;
        int k = (int)(t * DAT_002f08cc);
        int fade = (int)(t * DAT_002f08d0);
        float scale = k < 16 ? DAT_002f088c[k] / 128.0f : 1.0f;
        float grow = -DAT_002f0880 + DAT_002f0880 * scale;
        unsigned char c = Curve(k);
        int ai = k < 16 ? DAT_002f088c[k] : 128; float a = ai;
        float w = grow * 15.0f / 2.0f;
        float h = grow * 19.0f / 2.0f;
        self->spr[i]->x0 = (short)(self->left[i] - w);
        self->spr[i]->x1 = (short)(self->right[i] + w);
        self->spr[i]->y0 = (short)(self->top[i] - h);
        self->spr[i]->y1 = (short)(self->bottom[i] + h);
        unsigned int col = c | (c << 8 | ((unsigned char)(int)a << 24 | c << 16));
        self->spr[i]->color = col;
        self->spr[i + 1]->x0 = (short)(self->left[i + 1] - w);
        self->spr[i + 1]->x1 = (short)(self->right[i + 1] + w);
        self->spr[i + 1]->y0 = (short)(self->top[i + 1] - h);
        self->spr[i + 1]->y1 = (short)(self->bottom[i + 1] + h);
        self->spr[i + 1]->color = col;
        float s = DAT_002f0884 * fade / DAT_002f087c;
        w = s * 95.0f / 2.0f;
        h = s * 60.0f / 2.0f;
        self->spr[i + 2]->x0 = (short)(self->left[i + 2] - w);
        self->spr[i + 2]->x1 = (short)(self->right[i + 2] + w);
        self->spr[i + 2]->y0 = (short)(self->top[i + 2] - h);
        self->spr[i + 2]->y1 = (short)(self->bottom[i + 2] + h);
        float alpha = DAT_002f0888 - DAT_002f0888 * fade / DAT_002f087c;
        self->spr[i + 2]->color = (self->spr[i + 2]->color & 0xffffff) | ((unsigned char)(unsigned int)alpha << 24);
    }
}
// NEAR 164: retail alpha ternary is beqzl/li a1,128 (ours beqz); register choice for k/fade/i differs;
// retail schedules w=grow*15/2 before global loads, h after first store, early mul 19*grow;
// color OR order and j=2 section order differ. ~16 compiles.
// near miss from lane ol2 (unreviewed)
