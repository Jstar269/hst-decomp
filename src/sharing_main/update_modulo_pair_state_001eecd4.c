/* HSTMATCH module=hstp_trans_main.prx start=0x001eecd4 end=0x001eedc4 symbol=FUN_001eecd4 lang=c99 */
/* Clone of src/eboot/update_modulo_pair_state_001e0ab0.c (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_001eecd4.c (tag: a1) */
struct Arr6 {
    int v[6];
};
extern struct Arr6 DAT_00393a28;
extern unsigned char *DAT_003e1e04;
extern void FUN_001f8d7c(int, int, int);

void FUN_001eecd4(int param_1, int param_2)
{
    int uVar1;
    int uVar3;
    struct Arr6 local_18;

    *(int *)(*(int *)(param_1 + 0x40) + 0x54) = param_2;
    local_18 = DAT_00393a28;
    if (DAT_003e1e04 != 0) {
        uVar1 = *(int *)(DAT_003e1e04 + 0x198);
    } else {
        uVar1 = 0;
    }
    uVar3 = uVar1 % 2;
    FUN_001f8d7c(*(int *)(*(int *)(param_1 + 0x3c) + 0x8c), uVar3, local_18.v[param_2]);
    FUN_001f8d7c(*(int *)(*(int *)(param_1 + 0x3c) + 0x8c), uVar3 ^ 1, local_18.v[5 - param_2]);
}
