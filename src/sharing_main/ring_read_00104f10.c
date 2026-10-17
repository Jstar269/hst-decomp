/* HSTMATCH module=hstp_trans_main.prx start=0x00104f10 end=0x00104fe4 symbol=FUN_00104f10 lang=c99 */
/* Clone of src/eboot/ring_read_000ff678.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Ring buffer read (copy up to n bytes out; peek flag leaves the read position alone). */
extern void FUN_002c75b0(char *dst, char *src, unsigned n);
extern void FUN_00011090(char *dst, char *src, unsigned n);
typedef struct Ring {
    int pad0;
    char *data;
    unsigned cap;
    unsigned rd;
    unsigned wr;
} Ring;

unsigned FUN_00104f10(Ring *r, char *dst, unsigned n, int peek)
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
        FUN_002c75b0(dst, r->data + off, chunk);
        if (chunk != cnt)
            FUN_00011090(dst + chunk, r->data, cnt - chunk);
    }
    if (peek == 0)
        r->rd = r->rd + cnt;
    return cnt;
}
