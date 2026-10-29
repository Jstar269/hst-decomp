/* HSTMATCH module=EBOOT.BIN start=0x0010d948 end=0x0010db54 symbol=FUN_0010d948 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies n 36-byte records into a local buffer (memberwise copy: the user constructor makes MWCC copy field by field, ints with lw, shorts with lh), reads the first record's rectangle, rebases every record's rectangle to (0, 0, w, h), then passes the buffer on. Matching idiom: `Elem() {}` for the memberwise copy; the statement order fx, w, h, fy fixes the register choice. */
struct Elem {
    int a;
    int b;
    int c;
    int d;
    short x0;
    short y0;
    short x1;
    short y1;
    short s4;
    int e;
    int f;
    Elem() {}
};

struct Self {
    char pad[0x60];
    float fx;
    float fy;
    char pad2[0xd4 - 0x68];
    int count;
};

extern "C" void FUN_00101630(Self *, Elem *, int);

extern "C" void FUN_0010d948(Self *self, Elem *src, int n)
{
    Elem buf[5];
    Elem *dst = buf;
    Elem *end = src + n;
    int i;

    for (; src < end; src++) {
        *dst = *src;
        dst++;
    }
    short x0 = buf[0].x0;
    short x1 = buf[0].x1;
    short y0 = buf[0].y0;
    short y1 = buf[0].y1;
    self->fx = (float)x0;
    short w = x1 - x0;
    short h = y1 - y0;
    self->fy = (float)y0;
    for (i = 0; i < n; i++) {
        buf[i].x0 = 0;
        buf[i].y0 = 0;
        buf[i].x1 = w;
        buf[i].y1 = h;
    }
    FUN_00101630(self, buf, n);
    self->count = n;
}
