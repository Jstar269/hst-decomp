/* HSTMATCH module=EBOOT.BIN start=0x002395f8 end=0x0023988c symbol=FUN_002395f8 rodata=0x002c9f58 lang=c++ */

extern "C" {
extern void *DAT_00331b84;
extern void *DAT_0034a6bc;
extern char DAT_0034a678;

extern void FUN_002392dc(char *);
extern void FUN_00063830(float, float, void *, void *, void *, int, int, int);
extern void FUN_0023c520(char *);
extern void FUN_0023c568(char *);
extern void FUN_0023d714(char *);
extern void FUN_0023988c(char *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void FUN_0023e468(char *);
extern void FUN_0023466c(void *);

void FUN_002395f8(char *param_1)
{
    char uStack[8];
    int local_30[6];
    int local_20[4];

    int v1 = *(int *)(param_1 + 0x44);
    if (v1 != 0) {
        *(int *)(param_1 + 0x40) = v1;
        *(int *)(param_1 + 0x44) = 0;
        *(int *)(param_1 + 0x1854) = 0;
    }

    switch (*(int *)(param_1 + 0x40)) {
    case 0:
    case 4:
    case 5:
    case 6:
        break;

    case 1: {
        FUN_002392dc(param_1);
        *(int *)(param_1 + 0x44) = 8;
        local_20[0] = 0;
        local_20[1] = 0;
        local_20[2] = 0;
        local_20[3] = 0;
        local_30[0] = 0;
        local_30[1] = 0;
        local_30[2] = 0;
        local_30[3] = 0;
        FUN_00063830(65535.0f, -1.0f, DAT_00331b84, local_30, local_20, 10, 0, 0);
        *(int *)(param_1 + 0x3c) = 1;
        FUN_0023c520(param_1 + 0x50);
        FUN_0023c568(param_1 + 0x50);
        break;
    }

    case 2:
        if (*(int *)(param_1 + 0x17f4) == 0 && *(int *)(param_1 + 0x17fc) == 1) {
            int iVar3 = *(int *)(param_1 + 0x1850);
            int iVar2 = *(int *)((char *)DAT_0034a6bc + 0x18b8);
            int iVar1 = iVar3 + 1;
            *(int *)(param_1 + 0x1850) = iVar1;
            if (((iVar1 / *(int *)((char *)DAT_0034a6bc + 0x18b8) & 1U) != 0) != ((iVar3 / iVar2 & 1U) != 0)) {
                FUN_0023d714(param_1 + 0x50);
            }
        }
        break;

    case 3:
        if (*(int *)(param_1 + 0x17fc) == 1) {
            int iVar3 = *(int *)(param_1 + 0x1850);
            int iVar2 = *(int *)((char *)DAT_0034a6bc + 0x18b8);
            int iVar1 = iVar3 + 1;
            *(int *)(param_1 + 0x1850) = iVar1;
            if (((iVar1 / *(int *)((char *)DAT_0034a6bc + 0x18b8) & 1U) != 0) != ((iVar3 / iVar2 & 1U) != 0)) {
                FUN_0023d714(param_1 + 0x50);
            }
        }
        break;

    case 7:
        FUN_0023988c(param_1, &uStack[7], &uStack[6], &uStack[5], &uStack[4],
                     &uStack[3], &uStack[2], &uStack[1], &uStack[0]);
        if (*(unsigned char *)(*(int *)(param_1 + 0x1510) + 0x21) != 0) {
            FUN_0023e468(param_1 + 0x50);
            *(int *)(param_1 + 0x40) = 6;
        }
        break;

    case 8:
        if (*(float *)((char *)DAT_00331b84 + 0xc) == 0.0f) {
            *(int *)(param_1 + 0x3c) = 2;
            *(int *)(param_1 + 0x44) = 2;
        }
        break;

    case 9:
        if (*(float *)((char *)DAT_00331b84 + 0xc) == 0.0f) {
            *(int *)(param_1 + 0x44) = 10;
            *(int *)(param_1 + 0x3c) = 1;
            switch (*(int *)(param_1 + 0x48) = 1) {
            case 1:
                FUN_0023466c(&DAT_0034a678);
                break;
            }
        }
        break;
    }
}
}

// Differing: 18 words out of 165 words (147 matching).
// The only differences are in Case 2 (9 words) and Case 3 (9 words).
// Retail schedules `div zero, a2, a1` (iVar3 / iVar2) before `sw a0, 6224(s0)`
// and reloads DAT_0034a6bc->f_18b8 into v1 before executing `div zero, a0, v1`.
// Ours executes `sw a0, 6224(s0)` before both divisions when written sequentially,
// or swaps a0/a1 when iVar3 / iVar2 is placed on the left side of the != condition.
// Ruled out:
// - Inline helper functions (CheckAndTrigger): collapses reload of DAT_0034a6bc and reduces size from 165 to 161 words.
// - C99 vs C++: C++ matches rodata=0x002c9f58 and jump table layout.
// - Array zeroing in Case 1: scalar zero stores local_20[i] = 0 match retail's sw zero, not memset loops.
// - Stack layout: uStack[8], local_30[6], local_20[4] matches 80-byte frame and exact stack offsets (32, 48, 72).
// - Case 9: switch (*(int *)(param_1 + 0x48) = 1) { case 1: ... } reproduces retail's beq v1, v1 + dead b.
// near miss from lane ag2 (unreviewed)
