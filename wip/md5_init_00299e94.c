/* HSTMATCH module=EBOOT.BIN start=0x00299e94 end=0x00299ef4 symbol=FUN_00299e94 lang=c99 */
typedef struct {
    unsigned int a;         /* 0x00 */
    unsigned int b;         /* 0x04 */
    unsigned int c;         /* 0x08 */
    unsigned int d;         /* 0x0c */
    unsigned int pad;       /* 0x10 */
    unsigned short f0;      /* 0x14 */
    unsigned short f1;      /* 0x16 */
    unsigned int len_lo;    /* 0x18 */
    unsigned int len_hi;    /* 0x1c */
} Md5Ctx;

unsigned int FUN_00299e94(Md5Ctx *ctx)
{
    if (ctx == 0)
        return 0x80000103;
    ctx->a = 0x67452301;
    ctx->len_lo = 0;
    ctx->len_hi = 0;
    ctx->b = 0xefcdab89;
    ctx->c = 0x98badcfe;
    ctx->d = 0x10325476;
    ctx->f0 = 0;
    ctx->f1 = 0;
    return 0;
}
// 23/24 words, 24 differ (reordered): retail materialises all four MD5 constants + the 0x80000103
// return value BEFORE the null check (lui a1/a2/a3/v0/t0 0x6745/0xefcd/0x98ba/0x1032/0x8000, then
// ori v1/a1/a2/a3, then beqz a0,END with `ori v0,t0,0x103` in the delay slot) and stores the two
// zero length words from registers (`move t0,zero; move t1,zero`). Every spelling tried (locals
// before the if, order a/b/c/d, explicit zero local, separate `return 0`) makes MWCC sink each
// constant to just before its store and use `sw zero` for the length words.
// near miss from lane ds3 (unreviewed)
