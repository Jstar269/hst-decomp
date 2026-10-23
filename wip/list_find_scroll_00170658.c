/* HSTMATCH module=EBOOT.BIN start=0x00170658 end=0x00170744 symbol=FUN_00170658 lang=c99 */
void FUN_00170658(int param_1, int param_2)
{
    int iVar1;
    int *puVar2;
    int *puVar3;
    int *puVarEnd;
    int iVar4;
    int iVar5;

    if (param_2 != 0x7fff && param_2 != 0x7ffe) {
        iVar1 = (*(int (**)(int))(param_1 + 0x548))(param_2);
        puVar2 = *(int **)(param_1 + 0x1d4);
        iVar4 = puVar2[1];
        puVar3 = (int *)*puVar2;
        puVarEnd = puVar3 + puVar2[1];
        iVar5 = 0;
        for (; puVar3 != puVarEnd; puVar3++) {
            if (*(int *)*puVar3 == iVar1) {
                if (iVar4 < 5) {
                    *(int *)(param_1 + 0x560) = iVar5;
                    *(int *)(param_1 + 0x568) = 0;
                } else if (iVar5 + 2 < iVar4) {
                    if (iVar5 - 1 < 1) {
                        *(int *)(param_1 + 0x560) = iVar5;
                        *(int *)(param_1 + 0x568) = 0;
                    } else {
                        *(int *)(param_1 + 0x560) = 1;
                        *(int *)(param_1 + 0x568) = iVar5 - 1;
                    }
                } else {
                    *(int *)(param_1 + 0x568) = iVar4 - 4;
                    *(int *)(param_1 + 0x560) = iVar5 - (iVar4 - 4);
                }
                *(int *)(param_1 + 0x564) = iVar5;
                return;
            }
            iVar5 = iVar5 + 1;
        }
    }
}
// NEAR MISS (lane fm3): 48 of 59 words. Same block structure, but two systemic mismatches:
// (a) frame: retail reserves 32 bytes (ra at 12, s0 at 8) where ours uses 16; the recipe says a
//     trailing unused EMPTY by-value tag parameter in a C++ file explains that, but adding
//     `struct False {}; ... , False` did not change the frame here (worth retrying with the tag as
//     the FIRST parameter or a different tag size).
// (b) the list walk: retail `xor v1,a1,a0; sltiu v1,v1,1; xori v1,v1,1; beqz v1,exit` materialises
//     `!(first == end)`, and it loads the count twice (`lw a2,4(v1)`, then `lw v1,4(v1)` for the end
//     pointer) whereas ours CSEs the count and emits a plain `beq a3,a0,exit`.
// Everything else (the 0x7fff/0x7ffe early outs with beql, the 0x548 call, the 0x560/0x564/0x568
// window arithmetic including the `iVar4 - 4` clamp) is written correctly.
// near miss from lane fm3 (unreviewed)
