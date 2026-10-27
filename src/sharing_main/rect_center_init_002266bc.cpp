/* HSTMATCH module=hstp_trans_main.prx start=0x002266bc end=0x002267ac symbol=FUN_002266bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rect {
    int id;
    short x0, y0, x1, y1;
};

struct Obj {
    int f0;
    int f4;
    int f8;
    short fc;
    short fe;
    Rect *rect;
    short cx, cy;
    short dx0, dy0, dx1, dy1;
    int id;
};

extern "C" {
void FUN_002269c4(Obj *self);
void FUN_002269d0(Obj *self);
void FUN_002269dc(Obj *self);

void FUN_002266bc(Obj *self, Rect *r)
{
    self->f0 = 0;
    self->f4 = 0;
    self->rect = r;
    if (self->rect != 0) {
        self->cx = (self->rect->x0 + self->rect->x1) / 2;
        self->cy = (self->rect->y0 + self->rect->y1) / 2;
        self->dx0 = self->rect->x0 - self->cx;
        self->dy0 = self->rect->y0 - self->cy;
        self->dx1 = self->rect->x1 - self->cx;
        self->dy1 = self->rect->y1 - self->cy;
        self->id = self->rect->id;
        self->fc = 0x80;
    }
    FUN_002269c4(self);
    FUN_002269d0(self);
    FUN_002269dc(self);
}
}
