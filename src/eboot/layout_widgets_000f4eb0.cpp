/* HSTMATCH module=EBOOT.BIN start=0x000f4eb0 end=0x000f511c symbol=FUN_000f4eb0 lang=c++ */
/* Clone of src/sharing_main/layout_widgets_000fa5a4.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Widget {
    unsigned int color;
    short x0, y0, x1, y1;
    char pad[0x24 - 0xc];
    int f24;
    int f28;
    void Set(int v) { f24 = v; f28 = v; }
};

struct Layout {
    short dx0, dy0, dx1, dy1;
    short alpha;
};

struct Panel {
    char pad0[0x68];
    Widget *items[100];
    int f1f8;
    short x[2];
    short y[2];
    unsigned char f204[2];
    char pad1[2];
    int f208[2];
    char pad2[0x218 - 0x210];
    unsigned char f218;
};

extern "C" {
extern const Layout DAT_002c0880[];
Widget *FUN_000f4c9c(Panel *self, int id);

void FUN_000f4eb0(Panel *self)
{
    for (int i = 0; i < 2; i++) {
        self->items[0x40 + i]->Set(self->f208[i]);
        self->items[0x42 + i]->Set(self->items[0x40 + i]->f24);
        self->f204[i] = 1;
    }
    self->f1f8 = -1;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 3; k++) {
            int base = 0x3e + k * 2;
            const Layout *t = &DAT_002c0880[k];
            int id = base + j;
            if ((base == 0x42 || base == 0x48) && self->f218 == 0) {
                FUN_000f4c9c(self, id)->color = FUN_000f4c9c(self, id)->color & 0xffffff;
            } else {
                float scale = 1.0f;
                if (id >= 0x44) {
                    scale = 0.4f;
                }
                FUN_000f4c9c(self, id)->x0 = (short)(self->x[j] + t->dx0 * scale);
                FUN_000f4c9c(self, id)->y0 = self->y[j] + t->dy0;
                FUN_000f4c9c(self, id)->x1 = (short)(self->x[j] + t->dx1 * scale);
                FUN_000f4c9c(self, id)->y1 = self->y[j] + t->dy1;
                FUN_000f4c9c(self, id)->color = ((unsigned char)(t->alpha * 128 / 100) << 24) | (FUN_000f4c9c(self, id)->color & 0xffffff);
            }
        }
    }
    self->f204[0] = 0;
    self->f204[1] = 0;
}
}
