/* HSTMATCH module=EBOOT.BIN start=0x0004e780 end=0x0004ea98 symbol=FUN_0004e780 lang=c++ */
typedef unsigned long long u64;
struct PicHeader {
    unsigned totalSize;
    unsigned clutSize;
    unsigned imageSize;
    unsigned short headerSize;
    unsigned short clutColors;
    unsigned char picFormat;
    unsigned char mipmaps;
    unsigned char clutType;
    unsigned char imageType;
    unsigned short width;
    unsigned short height;
    u64 tex0;
    u64 tex1;
    unsigned regs;
    unsigned texClut;
};
extern "C" {
unsigned char *FUN_00010184(int, unsigned);
void FUN_000114c0(void *, int, int);
void *FUN_0005fdd0(void *, int);
void FUN_00011090(void *, const void *, int);
int FUN_0005febc(void *, int);
int FUN_0005ffb0(void *);
}

struct FileHead { char id[4]; unsigned char ver; unsigned char fmt; unsigned short count; char pad[8]; };
static inline int Log2(int v)
{
    int i;
    for (i = 31; i > 0; i--) {
        if (v & (1 << i))
            break;
    }
    if ((1 << i) < v)
        i++;
    return i;
}

extern "C" unsigned char *FUN_0004e780(int *out1, int *out2, int type, int clut, int w, int h)
{
    PicHeader hdr;
    hdr.headerSize = 0x30;
    int head = 16;
    int colors = 0;
    int psm = 0;
    int cpsm = 0;
    switch (type) {
    case 4:
        hdr.imageSize = w * h / 2;
        colors = 32;
        psm = 20;
        break;
    case 1:
        psm = 2;
        hdr.imageSize = w * h * 2;
        break;
    case 3:
        hdr.imageSize = w * h * 4;
        break;
    }
    hdr.imageSize = (hdr.imageSize + 15) & ~15;
    switch (clut) {
    case 3:
        hdr.clutSize = colors * 4;
        cpsm = 0;
        break;
    case 0:
        hdr.clutSize = 0;
        cpsm = 0;
        break;
    }
    hdr.clutType = clut | 0x40;
    hdr.mipmaps = 1;
    hdr.clutColors = colors;
    hdr.picFormat = 0;
    hdr.imageType = type;
    hdr.width = w;
    hdr.height = h;
    int tbw = (w + 63) / 64;
    if ((tbw & 1) && (unsigned)(type - 4) < 2)
        tbw++;
    int tw = Log2(w);
    int th = Log2(h);
    hdr.tex0 = ((u64)tbw << 14) | ((u64)psm << 20) | ((u64)tw << 26) | ((u64)th << 30) | ((u64)cpsm << 51) | (1ULL << 55);
    hdr.tex1 = 0x60;
    hdr.totalSize = hdr.clutSize + (hdr.headerSize + hdr.imageSize);
    hdr.regs = 0;
    hdr.texClut = 0;
    unsigned char *buf = FUN_00010184(head, head + hdr.totalSize);
    buf[0] = 'T';
    buf[1] = 'I';
    buf[2] = 'M';
    buf[3] = '2';
    buf[4] = 4;
    buf[5] = 0;
    *(unsigned short *)(buf + 6) = 1;
    FUN_000114c0(buf + 8, 0, 8);
    void *pic = FUN_0005fdd0(buf, 0);
    FUN_00011090(pic, &hdr, 0x30);
    *out1 = FUN_0005febc(pic, 0);
    *out2 = FUN_0005ffb0(pic);
    return buf;
}
// NEAR (192 words by position, 1 word missing): retail loads the constant 16 into v0 at entry ('li v0,16') and keeps it until 'addu a1,v0,v1' for the allocation size; every variant we wrote folds it into 'addiu a1,v0,16'.
// With v0 taken in retail, all temporaries move up a register (v1 not v0, colors in a1, psm in t3, cpsm in t2). Control flow, switch order and TEX0 packing already match.
// near miss from lane ol3 (unreviewed)
