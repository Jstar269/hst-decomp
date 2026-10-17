/* HSTMATCH module=EBOOT.BIN start=0x000ff5b0 end=0x000ff678 symbol=FUN_000ff5b0 lang=c99 */
/* Near-miss for ring buffer write (complement of src/eboot/ring_read_000ff678.c).
   All buffer copying, division, chunk slicing, wrap-around logic, and return value handling
   match retail 100% (+0x58 to +0xc4). The only difference is prologue instruction scheduling:
   retail schedules `move s0, a2` immediately before `subu v0, v1, v0` after loading r->wr, r->rd,
   and r->cap, and emits `beqzl at, 0xff608` with duplicated `divu zero, v1, a0` in delay slot.
*/

extern void FUN_002b77d8(char *dst, char *src, unsigned n);
extern void FUN_00011090(char *dst, char *src, unsigned n);

typedef struct Ring {
    int pad0;
    char *data;
    unsigned cap;
    unsigned rd;
    unsigned wr;
} Ring;

unsigned FUN_000ff5b0(Ring *r, char *src, unsigned n)
{
    unsigned cnt;
    unsigned avail;
    if ((int)n <= 0)
        return n;
    avail = r->cap - (r->wr - r->rd);
    cnt = avail < n ? avail : n;
    {
        unsigned off = r->wr % r->cap;
        unsigned chunk = r->cap - off;
        if (cnt < chunk)
            chunk = cnt;
        FUN_002b77d8(r->data + off, src, chunk);
        if (chunk != cnt)
            FUN_00011090(r->data, src + chunk, cnt - chunk);
    }
    r->wr = r->wr + cnt;
    return cnt;
}
// near miss from lane u2r1-3 (unreviewed)
