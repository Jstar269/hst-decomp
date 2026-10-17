/* HSTMATCH module=EBOOT.BIN start=0x001e0ab0 end=0x001e0ba0 symbol=FUN_001e0ab0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_001e0ab0.c (tag: a1) */
struct Arr6 {
    int v[6];
};
extern struct Arr6 DAT_002ebb1c;
extern unsigned char *DAT_00338ac4;
extern void FUN_001eaad8(int, int, int);

void FUN_001e0ab0(int param_1, int param_2)
{
    int uVar1;
    int uVar3;
    struct Arr6 local_18;

    *(int *)(*(int *)(param_1 + 0x40) + 0x54) = param_2;
    local_18 = DAT_002ebb1c;
    if (DAT_00338ac4 != 0) {
        uVar1 = *(int *)(DAT_00338ac4 + 0x198);
    } else {
        uVar1 = 0;
    }
    uVar3 = uVar1 % 2;
    FUN_001eaad8(*(int *)(*(int *)(param_1 + 0x3c) + 0x8c), uVar3, local_18.v[param_2]);
    FUN_001eaad8(*(int *)(*(int *)(param_1 + 0x3c) + 0x8c), uVar3 ^ 1, local_18.v[5 - param_2]);
}
