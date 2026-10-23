/* HSTMATCH module=EBOOT.BIN start=0x00114190 end=0x001142b0 symbol=FUN_00114190 lang=c99 */
/* near miss: 71/72 words, 20 differ. head (the a1==6 arm) is exact only as a one-case `switch`,
   which emits retail's `beq a1,v1,ORI / b B / andi` with the flag test duplicated into the b delay
   and again after the ori; an if/else gives the plain `bne` + single andi. V4 copy from the int
   struct batches 4 lwc1 then 4 swc1 only in C (C++ interleaves load/store pairs). Still off: retail
   materialises the Tag as `move v0,zero` in the capacity-fail delay slot then `seb a2,v0` before
   `addiu a0,a0,140`, and computes the element address as `lw v1,data / sll a1,count,4 / addu
   v1,v1,a1`; ours writes the a0 addiu into that delay slot, folds the tag to `seb a2,zero`, and
   swaps the sll/lw and the addu operands. Ruled out: C++ Tag (move lands in the right slot but the
   copy interleaves), static/static-inline tag factory (adds a helper or folds), slow-path-first
   branch (bnezl + worse). */
typedef struct { int a, b, c, d; } Cmd;
typedef struct { float x, y, z, w; } V4;
typedef struct { char c; } Tag;
extern void FUN_001142b0(int, int, int, int, unsigned);
extern void FUN_0011605c(int *, V4 *, Tag);

void FUN_00114190(int param_1, int param_2, int param_3, int param_4, unsigned param_5)
{
    Cmd tmp;
    Tag tag;
    char *p;
    int n;
    V4 *dst;

    switch (param_2) {
    case 6:
        param_5 |= 0xd;
        break;
    }
    if ((param_5 & 1) == 0)
        goto fallback;
    if ((*(unsigned short *)(*(int *)(*(int *)(*(int *)(param_1 + 0x54) + 0x10)) + 0xe) & 3) != 0) {
        if (*(int *)(param_1 + 0x90) == 0)
            goto fallback;
    }
    if (*(int *)(param_1 + 0x68) != 1 || (*(unsigned int *)(param_1 + 0x6c) & 2) != 0)
        goto fallback;
    p = (char *)&tmp;
    n = 16;
    if (p != 0) {
        do {
            *p++ = 0;
        } while (--n);
    }
    tmp.a = param_2;
    tmp.b = param_3;
    tmp.c = param_4;
    tmp.d = param_5;
    if (*(unsigned int *)(param_1 + 0x90) < *(unsigned int *)(param_1 + 0x94)) {
        dst = (V4 *)(*(int *)(param_1 + 0x8c) + *(unsigned int *)(param_1 + 0x90) * 0x10);
        if (dst != 0)
            *dst = *(V4 *)&tmp;
        *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
        return;
    }
    tag.c = 0;
    FUN_0011605c((int *)(param_1 + 0x8c), (V4 *)&tmp, tag);
    return;
fallback:
    FUN_001142b0(param_1, param_2, param_3, param_4, param_5);
}
// near miss from lane fm6 (unreviewed)
