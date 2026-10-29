/* HSTMATCH module=hstp_trans_main.prx start=0x00249790 end=0x00249a24 symbol=FUN_00249790 rodata=0x002da518 lang=c++ */
/* Clone of src/eboot/state_machine_002395f8.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_003daec4;
extern void *DAT_003f39ec;
extern char DAT_003f39a8;

extern void FUN_00249474(char *);
extern void FUN_000646f4(float, float, void *, void *, void *, int, int, int);
extern void FUN_0024c6b8(char *);
extern void FUN_0024c700(char *);
extern void FUN_0024d8ac(char *);
extern void FUN_00249a24(char *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void FUN_0024e600(char *);
extern void FUN_0024476c(void *);

void FUN_00249790(char *param_1)
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
        FUN_00249474(param_1);
        *(int *)(param_1 + 0x44) = 8;
        local_20[0] = 0;
        local_20[1] = 0;
        local_20[2] = 0;
        local_20[3] = 0;
        local_30[0] = 0;
        local_30[1] = 0;
        local_30[2] = 0;
        local_30[3] = 0;
        FUN_000646f4(65535.0f, -1.0f, DAT_003daec4, local_30, local_20, 10, 0, 0);
        *(int *)(param_1 + 0x3c) = 1;
        FUN_0024c6b8(param_1 + 0x50);
        FUN_0024c700(param_1 + 0x50);
        break;
    }

    case 2:
        if (*(int *)(param_1 + 0x17f4) == 0 && *(int *)(param_1 + 0x17fc) == 1) {
            int iVar3 = *(int *)(param_1 + 0x1850);
            int iVar2 = *(int *)((char *)DAT_003f39ec + 0x18b8);
            bool before = (iVar3 / iVar2 & 1U) != 0;
            int iVar1 = iVar3 + 1;
            *(int *)(param_1 + 0x1850) = iVar1;
            bool after = (iVar1 / *(int *)((char *)DAT_003f39ec + 0x18b8) & 1U) != 0;
            if (before != after) {
                FUN_0024d8ac(param_1 + 0x50);
            }
        }
        break;

    case 3:
        if (*(int *)(param_1 + 0x17fc) == 1) {
            int iVar3 = *(int *)(param_1 + 0x1850);
            int iVar2 = *(int *)((char *)DAT_003f39ec + 0x18b8);
            bool before = (iVar3 / iVar2 & 1U) != 0;
            int iVar1 = iVar3 + 1;
            *(int *)(param_1 + 0x1850) = iVar1;
            bool after = (iVar1 / *(int *)((char *)DAT_003f39ec + 0x18b8) & 1U) != 0;
            if (before != after) {
                FUN_0024d8ac(param_1 + 0x50);
            }
        }
        break;

    case 7:
        FUN_00249a24(param_1, &uStack[7], &uStack[6], &uStack[5], &uStack[4],
                     &uStack[3], &uStack[2], &uStack[1], &uStack[0]);
        if (*(unsigned char *)(*(int *)(param_1 + 0x1510) + 0x21) != 0) {
            FUN_0024e600(param_1 + 0x50);
            *(int *)(param_1 + 0x40) = 6;
        }
        break;

    case 8:
        if (*(float *)((char *)DAT_003daec4 + 0xc) == 0.0f) {
            *(int *)(param_1 + 0x3c) = 2;
            *(int *)(param_1 + 0x44) = 2;
        }
        break;

    case 9:
        if (*(float *)((char *)DAT_003daec4 + 0xc) == 0.0f) {
            *(int *)(param_1 + 0x44) = 10;
            *(int *)(param_1 + 0x3c) = 1;
            switch (*(int *)(param_1 + 0x48) = 1) {
            case 1:
                FUN_0024476c(&DAT_003f39a8);
                break;
            }
        }
        break;
    }
}
}
