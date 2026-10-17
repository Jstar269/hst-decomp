/* HSTMATCH module=EBOOT.BIN start=0x000bfb94 end=0x000c02ac symbol=FUN_000bfb94 lang=c++ data=0x002d55c4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Ad hoc PTP connection thread: listens/accepts (server) or opens/connects (client), then moves data between
   the socket and two ring buffers until the quit flag is set, and finally frees its context. Strings and the
   socket id global are this file's .data block (data=); the Sharing module has the identical function at
   0x000c3234 (src/sharing_main/ptp_thread_000c3234.cpp). */

extern "C" {
void FUN_000c02ac(...);                                          /* debug print stub */
void *FUN_00010184(unsigned int align, unsigned int size);      /* memalign */
void FUN_000104e0(void *p);                                     /* free */
int FUN_002b7888(unsigned int us);                              /* sceKernelDelayThread */
int FUN_002b78e8(int sema);                                     /* sceKernelDeleteSema */
int FUN_002b79b0(int status);                                   /* sceKernelExitDeleteThread */
int FUN_002b7e58(unsigned char *mac, unsigned short port, unsigned int bufsize, unsigned int delay,
                 int count, int queue, int unk);                /* sceNetAdhocPtpListen */
int FUN_002b7e38(int id, unsigned char *mac, unsigned short *port, unsigned int timeout, int nonblock);
                                                                /* sceNetAdhocPtpAccept */
int FUN_002b7e00(int id, int unk);                              /* sceNetAdhocPtpClose */
int FUN_002b7e20(unsigned char *srcmac, unsigned short srcport, unsigned char *dstmac, unsigned short dstport,
                 unsigned int bufsize, unsigned int delay, int count, int unk);  /* sceNetAdhocPtpOpen */
int FUN_002b7e68(int id, unsigned int timeout, int nonblock);   /* sceNetAdhocPtpConnect */
int FUN_002b7e30(int id, unsigned int timeout, int nonblock);   /* sceNetAdhocPtpFlush */
int FUN_002b7e28(int id, void *buf, int *len, unsigned int timeout, int nonblock);  /* sceNetAdhocPtpRecv */
int FUN_002b7e08(int id, void *buf, int *len, unsigned int timeout, int nonblock);  /* sceNetAdhocPtpSend */
}

struct Ring {
    virtual ~Ring();
    int pad4;
    int pad8;
    int rd;
    int wr;
    int Used() const { return wr - rd; }
};

extern "C" void FUN_000ff5b0(Ring *r, void *buf, int len);           /* ring write */
extern "C" int FUN_000ff678(Ring *r, void *buf, int max, int flag);  /* ring read */

struct EtherAddr { unsigned char data[6]; };

struct PtpCtx {
    unsigned char server;
    unsigned short *status;
    bool *quit;
    int sema;
    EtherAddr peer;
    EtherAddr self;
    unsigned short port;
    Ring *tx;
    Ring *rx;
};

#define WOULD_BLOCK ((int)0x80410709)
#define BUF_SIZE 0x1690

static int DAT_002d55c4 = -1;   /* PTP socket id */

static inline bool Running(PtpCtx *c) { return !*c->quit; }

extern "C" int FUN_000bfb94(unsigned int args, PtpCtx *ctx)
{
    int sema = ctx->sema;
    int n;                      /* listen/open socket id, later the would-block counter */
    int cnt = 0;
    int i;
    void *buf = FUN_00010184(64, BUF_SIZE);
    int r;
    unsigned short port;
    int len;
    EtherAddr mac;

    FUN_000c02ac("Thread start\n");
    if (ctx->server) {
        n = FUN_002b7e58(ctx->peer.data, ctx->port, 0x2d20, 200000, 300, 1, 0);
        if (n < 0) {
            FUN_000c02ac("sceNetAdhocPtpListen() failed. ret = 0x%x\n", n);
            *ctx->status = 0x8001;
            goto error;
        }
        FUN_000c02ac("sceNetAdhocPtpListen ok\n");
        do {
            FUN_002b7888(34000);
            if (Running(ctx)) {
                r = FUN_002b7e38(n, mac.data, &port, 0, 1);
                if (r >= 0) {
                    DAT_002d55c4 = r;
                    goto accepted;
                }
                if (r != WOULD_BLOCK) {
                    FUN_000c02ac("sceNetAdhocPtpAccept() failed. ret = 0x%x\n", r);
                    FUN_002b7e00(n, 0);
                    *ctx->status = 0x8002;
                    goto error;
                }
            } else {
                goto accepted;
            }
            cnt++;
        } while (cnt < 882);
        FUN_000c02ac("sceNetAdhocPtpAccept() timeout.\n");
        FUN_002b7e00(n, 0);
        *ctx->status = 0x8004;
        goto error;
    accepted:
        FUN_002b7e00(n, 0);
        if (*ctx->quit) {
            if (DAT_002d55c4 >= 0)
                FUN_002b7e00(DAT_002d55c4, 0);
            goto cleanup;
        }
        FUN_000c02ac("sceNetAdhocPtpAccept ok\n");
    } else {
        n = FUN_002b7e20(ctx->self.data, 0, ctx->peer.data, ctx->port, 0x2d20, 200000, 300, 0);
        if (n < 0) {
            FUN_000c02ac("sceNetAdhocPtpOpen() failed. ret = 0x%x\n", n);
            *ctx->status = 0x8008;
            goto error;
        }
        FUN_000c02ac("sceNetAdhocPtpOpen ok\n");
        DAT_002d55c4 = n;
        do {
            FUN_002b7888(34000);
            if (Running(ctx)) {
                r = FUN_002b7e68(DAT_002d55c4, 0, 1);
                if (r >= 0)
                    goto connected;
                if (r != WOULD_BLOCK) {
                    FUN_000c02ac("sceNetAdhocPtpConnect() failed. ret = 0x%x\n", r);
                    FUN_002b7e00(DAT_002d55c4, 0);
                    *ctx->status = 0x8010;
                    goto error;
                }
            } else {
                goto connected;
            }
            cnt++;
        } while (cnt < 0x7fffffff);
        FUN_000c02ac("sceNetAdhocPtpConnect() timeout.\n");
        FUN_002b7e00(DAT_002d55c4, 0);
        *ctx->status = 0x8020;
        goto error;
    connected:
        if (*ctx->quit) {
            FUN_002b7e00(DAT_002d55c4, 0);
            goto cleanup;
        }
        FUN_000c02ac("sceNetAdhocPtpConnect ok\n");
    }
    *ctx->status = 0x4000;
    FUN_000c02ac("Thread loop start\n");
    n = 0;
    for (;;) {
        FUN_002b7888(100);
        if (*ctx->quit)
            break;
        r = FUN_002b7e30(DAT_002d55c4, 60000000, 0);
        if (r != 0 && r != WOULD_BLOCK) {
            FUN_000c02ac("sceNetAdhocPtpFlush() failed. ret = 0x%x\n", r);
            *ctx->status |= 0x8100;
        }
        if (!ctx->server) {
            int used = ctx->rx->Used();
            for (;;) {
                if (used + BUF_SIZE > 0x10000)
                    break;
                len = BUF_SIZE;
                r = FUN_002b7e28(DAT_002d55c4, buf, &len, 0, 1);
                if (r == 0) {
                    if (len <= 0)
                        break;
                    n = 0;
                    FUN_000ff5b0(ctx->rx, buf, len);
                } else {
                    if (r == WOULD_BLOCK) {
                        if (++n >= 150000) {
                            FUN_000c02ac("sceNetAdhocPtpRecv() time out.\n");
                            *ctx->status |= 0x8040;
                        }
                    } else {
                        FUN_000c02ac("sceNetAdhocPtpRecv() failed. ret = 0x%x\n", r);
                        *ctx->status |= 0x8040;
                    }
                    break;
                }
            }
        } else {
            i = 0;
            int used = ctx->tx->Used();
            for (;;) {
                if (used <= 0)
                    break;
                len = FUN_000ff678(ctx->tx, buf, BUF_SIZE, 0);
                r = FUN_002b7e08(DAT_002d55c4, buf, &len, 0, 1);
                if (r == 0 || r == (int)0x80410001 || r == (int)0x80410715 || r == (int)0x80410708 ||
                    r == WOULD_BLOCK || r == (int)0x8041070c || r == (int)0x80410719) {
                    if (len <= 0)
                        break;
                    n = 0;
                } else {
                    if (r == WOULD_BLOCK) {
                        if (++n >= 150000)
                            *ctx->status |= 0x8080;
                    } else {
                        FUN_000c02ac("sceNetAdhocPtpSend() failed. ret = 0x%x\n", r);
                        *ctx->status |= 0x8080;
                    }
                    break;
                }
                if (++i >= 1)
                    break;
            }
        }
    }
    FUN_000c02ac("ThreadFunc Exit loop\n");
    r = FUN_002b7e30(DAT_002d55c4, 60000000, 0);
    if (r < 0)
        FUN_000c02ac("sceNetAdhocPtpFlush() failed. ret = 0x%x\n", r);
    r = FUN_002b7e00(DAT_002d55c4, 0);
    if (r < 0)
        FUN_000c02ac("sceNetAdhocPtpClose() failed. ret = 0x%x\n", r);
    goto cleanup;
error:
    FUN_000c02ac("ThreadFunc enter error loop\n");
    do {
        FUN_002b7888(34000);
    } while (Running(ctx));
cleanup:
    FUN_000c02ac("ThreadFunc Delete ownself\n");
    r = FUN_002b78e8(sema);
    if (r != 0)
        FUN_000c02ac("sceKernelDeleteSema() failed. ret = 0x%x\n", r);
    if (ctx->rx) {
        delete ctx->rx;
        ctx->rx = 0;
    }
    if (ctx->tx) {
        delete ctx->tx;
        ctx->tx = 0;
    }
    if (ctx->quit) {
        delete ctx->quit;
        ctx->quit = 0;
    }
    if (ctx->status) {
        delete ctx->status;
        ctx->status = 0;
    }
    if (buf)
        FUN_000104e0(buf);
    FUN_000c02ac("ThreadFunc Delete finish\n");
    FUN_002b79b0(0);
    return 0;
}
