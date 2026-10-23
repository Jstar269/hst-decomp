/* HSTMATCH module=EBOOT.BIN start=0x0022ae88 end=0x0022af6c symbol=FUN_0022ae88 lang=c99 */
extern char *DAT_003415a8;
extern int FUN_0022a9a8();

unsigned char FUN_0022ae88(int param_1, int param_2)
{
    int iVar4;
    unsigned char cVar1;

    iVar4 = FUN_0022a9a8();
    if (iVar4 == 1) {
        cVar1 = *(unsigned char *)((param_2 + 10) + (param_1 * 0x14 + DAT_003415a8 + 0x3d00));
    } else {
        cVar1 = *(unsigned char *)(param_2 + (param_1 * 0x14 + DAT_003415a8 + 0x3d00));
    }
    return cVar1 != 0 &&
           ((iVar4 = FUN_0022a9a8(), iVar4 == 1)
                ? *(unsigned char *)((param_2 + 10) + (param_1 * 0x14 + DAT_003415a8 + 0x3d00))
                : *(unsigned char *)(param_2 + (param_1 * 0x14 + DAT_003415a8 + 0x3d00))) < 4;
}
// NEAR MISS (lane fm3): 43 of 57 words, structural match. Two blocks differ:
// (1) retail keeps param_1 alive in s2 (3 saved regs: s2=a0, s1=a1, s0 = row offset 20*param_1)
//     and recomputes the row offset in the else arm; ours puts param_1 in s0 and overwrites it with
//     the offset (2 saved regs). The whole body then reads s0 where retail reads s2.
// (2) retail's `cVar1 != 0 && ...` test is `slti v0,v0,1; xori v0,v0,1; andi v0,v0,0xff;
//     beqzl v0,exit` (the positive condition materialised then tested); ours is `andi v0,0xff;
//     beqz v0,exit` with the same block order.
// The && return form IS the right shape (it produces retail's short-circuit + beqzl-to-exit and the
// final `slti v0,v0,4` returned directly). Ruled out: separate if/else with a bVar3 result
// (materialises the second call too early and returns via bnez/nop), `(param_2+10)+(p1*0x14+global)
// +0x3d00` vs the parenthesised `(p2+10)+(p1*0x14+global+0x3d00)` (the latter is the one that keeps
// `addiu v0,sX,10` separate from the lbu 0x3d00 displacement - use it), local declaration order.
// near miss from lane fm3 (unreviewed)
