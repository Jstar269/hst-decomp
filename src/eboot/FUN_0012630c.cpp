/* HSTMATCH module=EBOOT.BIN start=0x0012630c end=0x001264f8 symbol=FUN_0012630c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Net {
    virtual ~Net();
    int f04;                /* 0x04 */
    int f08;                /* 0x08 */
    int f0c;                /* 0x0c */
    int f10;                /* 0x10 */
};

struct Ctx {
    int sock;               /* 0x00 */
    unsigned short *status; /* 0x04 */
    unsigned char *quit;    /* 0x08 */
    int sema;               /* 0x0c */
    char pad10[0x10];       /* 0x10..0x1f */
    Net *net20;             /* 0x20 */
    Net *net24;             /* 0x24 */
};

extern "C" {
extern char DAT_002da210[];
extern char DAT_002da224[];
extern char DAT_002da250[];
extern char DAT_002da268[];
extern char DAT_002da284[];
extern char DAT_002da2b0[];
extern void *FUN_00000a90(unsigned size);
extern void FUN_00000a00(void *p);
extern void FUN_000009e4(void *p);
extern void FUN_000ff5b0(Net *n, void *buf, int len);
extern void FUN_001264f8(char *fmt, ...);
extern void FUN_002b7888(int ms);
extern int FUN_002b78e8(int sema);
extern void FUN_002b79b0(int x);
extern int FUN_002b7e50(int sock, void *a, void *b, void *buf, int *len,
                        int x, int y);
}

extern "C" int FUN_0012630c(int unused, Ctx *c)
{
    struct {
        int len;            /* 0x18 */
        short unk4;         /* 0x1c */
        short port;         /* 0x1e */
    } args;
    char buf1[8];           /* 0x10 */
    int sema = c->sema;
    char *buf = (char *)FUN_00000a90(0x1690);
    int r;

    c->status[0] = 0x4000;
    FUN_001264f8(DAT_002da210);
    for (;;) {
        if (*c->quit != 0)
            break;
        if (c->net24->f10 - c->net24->f0c + 0x1690 <= 0x4000) {
            args.len = 0x1690;
            r = FUN_002b7e50(c->sock, buf1, &args.port, buf, &args.len, 0, 0);
            if (r == 0) {
                FUN_000ff5b0(c->net24, buf, args.len);
            } else if (r != -0x7fbef8f7) {
                FUN_001264f8(DAT_002da224, r);
                *c->status |= 0x8040;
            }
        } else {
            FUN_002b7888(16000);
        }
    }
    FUN_001264f8(DAT_002da250);
    FUN_001264f8(DAT_002da268);
    r = FUN_002b78e8(sema);
    if (r != 0)
        FUN_001264f8(DAT_002da284, r);
    if (c->net24 != 0) {
        delete c->net24;
        c->net24 = 0;
    }
    if (c->net20 != 0) {
        delete c->net20;
        c->net20 = 0;
    }
    if (c->quit != 0) {
        FUN_00000a00(c->quit);
        c->quit = 0;
    }
    if (c->status != 0) {
        FUN_00000a00(c->status);
        c->status = 0;
    }
    if (buf != 0)
        FUN_000009e4(buf);
    FUN_001264f8(DAT_002da2b0);
    FUN_002b79b0(0);
    return 0;
}
