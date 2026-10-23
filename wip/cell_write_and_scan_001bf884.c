/* HSTMATCH module=EBOOT.BIN start=0x001bf884 end=0x001bf948 symbol=FUN_001bf884 lang=c99 */
extern char *DAT_003415a8;
extern void FUN_001bbab8(int);

void FUN_001bf884(int param_1, int param_2, unsigned char param_3)
{
    unsigned char *pbVar1;
    int iVar2;
    int iVar4;
    int iVar3;

    if (param_2 < 0) {
        pbVar1 = 0;
    } else if (param_2 >= 0x280) {
        pbVar1 = 0;
    } else {
        pbVar1 = (unsigned char *)(param_1 + param_2 * 2 + 0x34c);
    }
    if (pbVar1 != 0 && (*pbVar1 = param_3, (unsigned)(param_3 - 4) < 2) && DAT_003415a8 != 0) {
        iVar4 = 0;
        iVar3 = 0;
        do {
            if (iVar4 < 0) {
                iVar2 = 0;
            } else if (iVar4 < 0xf) {
                iVar2 = (int)DAT_003415a8 + 0x80 + iVar3 + 4;
            } else {
                iVar2 = 0;
            }
            FUN_001bbab8(iVar2);
            iVar4 = iVar4 + 1;
            iVar3 = iVar3 + 0x38;
        } while (iVar4 < 0xf);
    }
}
// NEAR MISS (lane fm3): 33 of 49 words differ; every block is in retail's order, the difference is
//   (a) the bounds chain: retail `bltz a1,L_zero(<0 only>)` then `slti at,a1,640; beqzl at,join;
//       move v1,zero` (one zero store in the likely delay) then sll/addu/b/addiu; ours emits the
//       zero for the `>= 0x280` arm as a separate block with bnezl (one extra move + a b/b pair).
//       Tried: if/else-if with `< 0x280`, with `>= 0x280`, `p = 0` pre-initialised, and
//       `if (p2 < 0 || p2 >= 0x280)` -- this `>=` form is the closest.
//   (b) the 15-iteration do/while body: retail reloads DAT_003415a8 at the loop head and splits
//       `DAT + 0x80` (addiu 128 in the bltz delay) from the `+4` member offset (addiu a0,v0,4 after
//       addu v0,v0,s0). Ours folds 0x80+4 into 0x84 and issues the load inside the else arm;
//       hoisting the load+0x80 into a `base` local moves the whole thing OUT of the loop (worse).
// Everything else matches: sb a2,(v1) store position, andi/addiu -4/sltiu <2 test, the DAT != 0
// test, s1=i / s0=i*0x38 colouring, jal 0x1bbab8 and the 0xf bound.
// near miss from lane fm3 (unreviewed)
