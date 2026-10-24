/* HSTMATCH module=EBOOT.BIN start=0x001c287c end=0x001c2ac0 symbol=FUN_001c287c lang=c99 rodata=0x2c63ac */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034a2e0;
extern int DAT_003415d4;
extern char DAT_0034179c;
extern int FUN_0021ab8c(int);
extern int FUN_001c7158(void);
extern int FUN_002afb80(int, int);
extern void FUN_001cd88c(int, int, int);
extern void FUN_001c2498(int);
extern void FUN_00225d98(int);
extern void FUN_001c9d7c(int);
extern void FUN_001c9dec(int);
extern void FUN_001c9dfc(int);
extern void FUN_001c9e0c(int);
extern void FUN_001ca8e8(int);
extern void FUN_001ca8f0(int);
extern void FUN_001905b8(int, int);
extern void FUN_001cd3d8(int);
extern void FUN_001b4848(float, void *);
extern void FUN_001b2430(void *);

void FUN_001c287c(int param_1)
{
    int uVar1;
    int iVar2;

    uVar1 = FUN_0021ab8c(*(int *)(param_1 + 0x1c));
    switch (uVar1) {
    case 0:
        iVar2 = FUN_001c7158();
        if (iVar2 != 0) {
            iVar2 = FUN_002afb80(*(int *)(param_1 + 0x18), 0);
            if (iVar2 != 0) {
                FUN_001cd88c(param_1, 5, 1);
                FUN_001c2498(param_1);
                FUN_00225d98(DAT_0034a2e0);
            }
        }
        break;
    case 1:
        FUN_001cd88c(param_1, 0, 1);
        FUN_001c9d7c(*(int *)(param_1 + 0x18));
        break;
    case 2:
        FUN_001cd88c(param_1, 0, 1);
        FUN_001c9dec(*(int *)(param_1 + 0x18));
        break;
    case 3:
        FUN_001cd88c(param_1, 0, 1);
        FUN_001c9dfc(*(int *)(param_1 + 0x18));
        break;
    case 4:
        FUN_001cd88c(param_1, 0, 1);
        FUN_001c9e0c(*(int *)(param_1 + 0x18));
        break;
    case 9:
        FUN_001ca8e8(*(int *)(param_1 + 0x18));
        *(int *)(param_1 + 0xe8) = 0;
        *(unsigned char *)(param_1 + 0xf0) = 0;
        FUN_001905b8(DAT_003415d4, 3);
        FUN_001cd88c(param_1, 8, 1);
        FUN_001cd3d8(*(int *)(param_1 + 0x18));
        break;
    case 5:
        FUN_001ca8e8(*(int *)(param_1 + 0x18));
        *(int *)(param_1 + 0xe8) = 2;
        *(unsigned char *)(param_1 + 0xf0) = 0;
        FUN_001905b8(DAT_003415d4, 3);
        FUN_001cd88c(param_1, 8, 1);
        FUN_001cd3d8(*(int *)(param_1 + 0x18));
        break;
    case 6:
        FUN_001ca8f0(*(int *)(param_1 + 0x18));
        *(int *)(param_1 + 0xe8) = 1;
        *(unsigned char *)(param_1 + 0xf0) = 0;
        FUN_001905b8(DAT_003415d4, 3);
        FUN_001cd88c(param_1, 8, 1);
        FUN_001cd3d8(*(int *)(param_1 + 0x18));
        break;
    case 7:
    case 8:
        break;
    default:
        break;
    }
    iVar2 = *(int *)(param_1 + 0x10);
    if (iVar2 == 0) {
        FUN_001b4848(0.1f, &DAT_0034179c);
        FUN_001b2430(&DAT_0034179c);
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 4) == 0xb && *(int *)(param_1 + 0x10) != 8) {
        FUN_001cd88c(param_1, 0, 1);
    }
}
