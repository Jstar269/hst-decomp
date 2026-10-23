/* HSTMATCH module=EBOOT.BIN start=0x0022ab44 end=0x0022abdc symbol=FUN_0022ab44 lang=c99 */
extern char *DAT_003415a8;
extern int FUN_0022a9a8();

unsigned char FUN_0022ab44(int param_1, int param_2, int *param_3)
{
    unsigned char uVar1;
    int iVar2;

    iVar2 = FUN_0022a9a8();
    if (param_3 != 0) {
        *param_3 = iVar2;
    }
    if (iVar2 == 1) {
        uVar1 = *(unsigned char *)(param_1 * 0x14 + DAT_003415a8 + (param_2 + 10) + 0x3d00);
    } else {
        uVar1 = *(unsigned char *)(param_1 * 0x14 + DAT_003415a8 + param_2 + 0x3d00);
    }
    return uVar1;
}
// NEAR MISS (lane fm3): 6 words differ. Retail loads the row-table global first (lui; lw a0,5544)
// and adds the index term to it, then adds (col+10)/(col) on the left (addu v0,v1,v0 / addu v0,s0,v0);
// ours multiplies first, loads the global into v0 and accumulates the column on the right.
// Ruled out: sharing a `row` local (mwcc CSEs it into a1 and the whole color map changes, 2 words
// shorter); left-chain orderings param_2+10+base, base+idx*14+param_2, and (param_2+10)+(idx*0x14+base)
// (each only reorders the same 6 words); 0x3d0a written inline (folds into the lbu disp, retail keeps
// addiu v1,s0,10 + lbu 0x3d00).
// near miss from lane fm3 (unreviewed)
