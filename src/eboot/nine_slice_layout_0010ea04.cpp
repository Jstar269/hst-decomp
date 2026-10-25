/* HSTMATCH module=EBOOT.BIN start=0x0010ea04 end=0x0010ee50 symbol=FUN_0010ea04 lang=c++ rodata=0x002c1128 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rect {
    char pad[4];
    short x0;
    short y0;
    short x1;
    short y1;
    short W() const { return x1 - x0; }
    short H() const { return y1 - y0; }
    void SetX(short x)
    {
        short d = x - x0;
        x0 = x;
        x1 += d;
    }
    void SetY(short y)
    {
        short d = y - y0;
        y0 = y;
        y1 += d;
    }
    void SetPos(short x, short y)
    {
        SetX(x);
        SetY(y);
    }
};

extern "C" void FUN_000ffb3c(void *, int);

struct Frame {
    char pad[0x10];
    Rect **parts;
    void Show(int i, int on) { FUN_000ffb3c(parts[i], on); }
};

#pragma opt_strength_reduction off
extern "C" void FUN_0010ea04(Frame *self, short x, short y, short w, short h, short l, short t, int n)
{
    for (int i = 0; i < n; ++i) {
        FUN_000ffb3c(self->parts[i], 0);
        switch (i) {
        case 0:
            self->parts[0]->SetPos(x + l, y + t);
            break;
        case 1: {
            Rect *r = self->parts[2];
            r->SetPos(x + l, t + ((y + h) - r->H()));
            break;
        }
        case 2:
            self->parts[1]->y0 = self->parts[0]->y1;
            self->parts[1]->y1 = self->parts[2]->y0;
            self->parts[1]->SetX(x + l);
            break;
        case 3: {
            Rect *r = self->parts[6];
            r->SetPos(l + ((x + w) - r->W()), y + t);
            break;
        }
        case 4: {
            Rect *r = self->parts[8];
            r->SetPos(l + ((x + w) - r->W()), t + ((y + h) - r->H()));
            break;
        }
        case 5: {
            self->parts[7]->y0 = self->parts[6]->y1;
            self->parts[7]->y1 = self->parts[8]->y0;
            Rect *r = self->parts[7];
            r->SetX(l + ((x + w) - r->W()));
            break;
        }
        case 6:
            self->parts[3]->SetY(y + t);
            self->parts[3]->x0 = self->parts[0]->x1;
            self->parts[3]->x1 = self->parts[6]->x0;
            break;
        case 7: {
            Rect *r = self->parts[5];
            r->SetY(t + ((y + h) - r->H()));
            self->parts[5]->x0 = self->parts[2]->x1;
            self->parts[5]->x1 = self->parts[8]->x0;
            break;
        }
        case 8:
            self->parts[4]->y0 = self->parts[3]->y1;
            self->parts[4]->y1 = self->parts[5]->y0;
            self->parts[4]->x0 = self->parts[3]->x0;
            self->parts[4]->x1 = self->parts[5]->x1;
            break;
        }
    }
}
