/* HSTMATCH module=EBOOT.BIN start=0x0022aae8 end=0x0022ab44 symbol=FUN_0022aae8 lang=c99 */
extern char *DAT_003415a8;

void FUN_0022aae8(int param_1, unsigned char param_2, unsigned char param_3, int param_4, int param_5)
{
    int iVar2;
    int iVar1;

    if (param_5 == 1) {
        iVar2 = 10;
        iVar1 = 0xf;
    } else {
        iVar2 = 0;
        iVar1 = 5;
    }
    *(unsigned char *)((iVar2 + param_4) + (param_1 * 0x14 + DAT_003415a8 + 0x3d00)) = param_2;
    *(unsigned char *)((iVar1 + param_4) + (param_1 * 0x14 + DAT_003415a8 + 0x3d00)) = param_3;
}
// NEAR MISS (lane fm3): only 4 of 23 words differ, and they are the same commutative-operand
// encoding twice: retail `addu a0,t1,a0` / `addu a0,t0,a0` (and `addu v1,t1,v1` / `addu v1,a3,v1`)
// puts the freshly computed offset in rs; ours emits `addu a0,a0,t1` / `addu a0,a0,t0` (base in rs).
// Every other instruction, including the bnel/`move t0,zero`/`li t0,10`/`b`/`li v1,15` select and
// the reload of DAT_003415a8 between the two stores, already matches.
// Ruled out: `(iVar2+param_4)+(p1*0x14+base+0x3d00)`, `(p1*0x14+base)+(iVar2+param_4)+0x3d00`, and
// putting 0x3d00 outside the inner sum -- all give the same 4-word operand swap. Two locals declared
// iVar2-then-iVar1 (not iVar1-then-iVar2) IS required: it fixes 7 other words of colouring.
// near miss from lane fm3 (unreviewed)
