/* HSTMATCH module=EBOOT.BIN start=0x0012630c end=0x001264f8 symbol=FUN_0012630c lang=c++ data=0x002da210 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002da210-0x002da283) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
enum {
    RECV_SIZE = 0x1690,            /* bytes received per packet */
    RING_LIMIT = 0x4000,           /* receive ring capacity */
    STATUS_RUNNING = 0x4000,       /* status word while the loop runs */
    STATUS_ERROR = 0x8040,         /* bits set when a receive fails */
    ADHOC_ERR_TIMEOUT = -0x7fbef8f7, /* receive result meaning no packet yet (0x80410709) */
    RING_FULL_DELAY_US = 16000     /* sleep while the ring has no room */
};

/* Polymorphic buffer object; the ring variant tracks two positions (their difference is the byte count held). */
struct Net {
    virtual ~Net();
    int f04;                /* 0x04 */
    int f08;                /* 0x08 */
    int unk0c;              /* 0x0c */
    int unk10;              /* 0x10 */
};

/* Receive-thread context, passed as the thread argument block. */
struct Ctx {
    int sock;               /* 0x00 */
    unsigned short *status; /* 0x04 */
    unsigned char *quit;    /* 0x08 */
    int sema;               /* 0x0c */
    char pad10[0x10];       /* 0x10..0x1f */
    Net *obj20;             /* 0x20 */
    Net *ring;              /* 0x24 receive ring the packets are written into */
};

extern "C" {
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

/* Receive thread: read ad-hoc packets into the ring until told to quit, then free everything it owns. */
extern "C" int FUN_0012630c(int arglen, Ctx *ctx)
{
    struct {
        int len;            /* 0x18 */
        short unk4;         /* 0x1c */
        short port;         /* 0x1e */
    } recv;
    char src_mac[8];       /* 0x10 */
    int sema = ctx->sema;
    char *buf = (char *)FUN_00000a90(RECV_SIZE);
    int r;

    ctx->status[0] = STATUS_RUNNING;
    FUN_001264f8("Thread loop start\n");
    for (;;) {
        if (*ctx->quit != 0)
            break;
        if (ctx->ring->unk10 - ctx->ring->unk0c + RECV_SIZE <= RING_LIMIT) {
            recv.len = RECV_SIZE;
            r = FUN_002b7e50(ctx->sock, src_mac, &recv.port, buf, &recv.len, 0, 0);
            if (r == 0) {
                FUN_000ff5b0(ctx->ring, buf, recv.len);
            } else if (r != ADHOC_ERR_TIMEOUT) {
                FUN_001264f8("sceNetAdhocPdpRecv() failed. ret = 0x%x\n", r);
                *ctx->status |= STATUS_ERROR;
            }
        } else {
            FUN_002b7888(RING_FULL_DELAY_US);
        }
    }
    FUN_001264f8("ThreadFunc Exit loop\n");
    FUN_001264f8("ThreadFunc Delete ownself\n");
    r = FUN_002b78e8(sema);
    if (r != 0)
        FUN_001264f8(DAT_002da284, r);
    if (ctx->ring != 0) {
        delete ctx->ring;
        ctx->ring = 0;
    }
    if (ctx->obj20 != 0) {
        delete ctx->obj20;
        ctx->obj20 = 0;
    }
    if (ctx->quit != 0) {
        FUN_00000a00(ctx->quit);
        ctx->quit = 0;
    }
    if (ctx->status != 0) {
        FUN_00000a00(ctx->status);
        ctx->status = 0;
    }
    if (buf != 0)
        FUN_000009e4(buf);
    FUN_001264f8(DAT_002da2b0);
    FUN_002b79b0(0);
    return 0;
}
