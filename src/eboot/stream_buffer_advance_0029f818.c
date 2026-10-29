/* HSTMATCH module=EBOOT.BIN start=0x0029f818 end=0x0029f92c symbol=FUN_0029f818 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char u8;

enum { STREAM_BLOCK_SIZE = 0x10000 };

typedef struct StreamBuf {
    char pad00[4];
    void *source;                       /* 0x4 */
    char pad08[0x1b4 - 0x8];
    int sink;                           /* 0x1b4 */
    char block[STREAM_BLOCK_SIZE];      /* 0x1b8 */
    int block_len;                      /* 0x101b8 */
    char leftover[STREAM_BLOCK_SIZE];   /* 0x101bc */
    char *pending;                      /* 0x201bc: unconsumed bytes of the last block */
    int pending_len;                    /* 0x201c0 */
} StreamBuf;

extern void *FUN_00011090(void *dest, const void *src, int n);
extern void FUN_000c067c(void *, void *, void *);
extern int FUN_000ff5b0(int, const void *, int);

/* Feeds the sink with the leftover bytes, or with a freshly read block; keeps whatever the sink did not take. */
void FUN_0029f818(StreamBuf *self)
{
    int consumed;

    if (self->pending_len > 0) {
        consumed = FUN_000ff5b0(self->sink, self->pending, self->pending_len);
        self->pending_len -= consumed;
        self->pending += consumed;
    } else {
        self->block_len = STREAM_BLOCK_SIZE;
        FUN_000c067c(self->source, self->block, &self->block_len);
        consumed = FUN_000ff5b0(self->sink, self->block, self->block_len);
        if (consumed < self->block_len) {
            self->pending_len = self->block_len - consumed;
            self->pending = self->leftover;
            FUN_00011090(self->leftover, self->block + consumed, self->pending_len);
        }
    }
}
