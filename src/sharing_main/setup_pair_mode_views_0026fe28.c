/* HSTMATCH module=hstp_trans_main.prx start=0x0026fe28 end=0x0026feec symbol=FUN_0026fe28 lang=c99 */
/* Clone of src/eboot/setup_pair_mode_views_0025f000.c (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a7/v21/FUN_0026fe28.c (tag: a7) */
extern unsigned char DAT_003eaaf6;
extern void FUN_00105470(int, int);

void FUN_0026fe28(int param_1, int param_2)
{
    if (*(unsigned char *)(param_1 + 0x64) != 0 && (*(unsigned char *)(param_1 + 0x65) == 0 || DAT_003eaaf6 != 0)) {
        FUN_00105470(*(int *)(param_1 + 0x7c), 1);
        FUN_00105470(*(int *)(param_1 + 0x80), 1);
        FUN_00105470(*(int *)(param_1 + 0x88), 1);
        FUN_00105470(*(int *)(param_1 + 0x8c), 1);
    } else {
        if (*(unsigned char *)(param_1 + 0x65) != 0) {
            FUN_00105470(*(int *)(param_1 + 0x7c), 0);
            FUN_00105470(*(int *)(param_1 + 0x80), 0);
        }
        FUN_00105470(*(int *)(param_1 + 0x88), param_2);
        FUN_00105470(*(int *)(param_1 + 0x8c), param_2);
    }
}
