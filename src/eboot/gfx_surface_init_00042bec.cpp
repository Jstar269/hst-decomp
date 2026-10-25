/* HSTMATCH module=EBOOT.BIN start=0x00042bec end=0x00042dd8 symbol=FUN_00042bec lang=c++ rodata=0x002bc148 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Info {
    char pad0[0x50];
    unsigned short w;
    unsigned short h;
    char pad54[0x108 - 0x54];
};

struct Gfx {
    char pad0[0x19088];
    int ctx;
    int surf;
    int ext;
    int m29094;
    int w;
    int h;
    int count;
    char pad290a4[0x190b4 - 0x190a4];
    int totalW;
    int totalH;
};

extern "C" {
extern unsigned int DAT_003417a4;
extern char DAT_002cff88[];
extern char DAT_002ccac0[];
int FUN_002b7ac8(int, int, int, int *);
int FUN_002b7aa0(int, Info *);
int FUN_002b7ad0(int, const char *, int, int *);
void FUN_00042dd8(const char *, ...);
}

extern "C" void FUN_00042bec(Gfx *self)
{
    int type = 0;
    switch (DAT_003417a4) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        type = 9;
        break;
    case 9:
        type = 17;
        break;
    case 10:
        break;
    }
    int err;
    Info info;
    self->surf = FUN_002b7ac8(self->ctx, type, 0, &err);
    if (err)
        FUN_00042dd8(DAT_002cff88, err);
    err = FUN_002b7aa0(self->surf, &info);
    if (err)
        FUN_00042dd8(DAT_002cff88, err);
    switch (DAT_003417a4) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        self->ext = FUN_002b7ad0(self->ctx, DAT_002ccac0, 8680, &err);
        if (err)
            FUN_00042dd8(DAT_002cff88, err);
        self->m29094 = 0;
        break;
    default:
        self->ext = 0;
        self->m29094 = 0;
        break;
    }
    self->w = info.w;
    self->w = (self->w + 3) / 4 * 4;
    self->h = info.h;
    self->count = (self->totalW / self->w) * (self->totalH / self->h);
}
