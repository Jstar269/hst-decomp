/* HSTMATCH module=EBOOT.BIN start=0x000ff678 end=0x000ff74c symbol=FUN_000ff678 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Ring buffer read (copy up to n bytes out; peek flag leaves the read position alone). */
extern void FUN_002b77d8(char *dst, char *src, unsigned n);
extern void FUN_00011090(char *dst, char *src, unsigned n);
typedef struct Ring {
    int pad0;
    char *data;
    unsigned cap;
    unsigned rd;
    unsigned wr;
} Ring;

unsigned FUN_000ff678(Ring *r, char *dst, unsigned n, int peek)
{
    unsigned cnt;
    if ((int)n <= 0)
        return n;
    cnt = r->wr - r->rd;
    if (n < cnt)
        cnt = n;
    {
        unsigned off = r->rd % r->cap;
        unsigned chunk = r->cap - off;
        if (cnt < chunk)
            chunk = cnt;
        FUN_002b77d8(dst, r->data + off, chunk);
        if (chunk != cnt)
            FUN_00011090(dst + chunk, r->data, cnt - chunk);
    }
    if (peek == 0)
        r->rd = r->rd + cnt;
    return cnt;
}
