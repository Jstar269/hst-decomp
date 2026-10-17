/* HSTMATCH module=hstp_trans_main.prx start=0x00235074 end=0x002350e0 symbol=FUN_00235074 lang=c99 */
/* Clone of src/eboot/init_nine_table_entries_00225b00.c (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_00235074.c (tag: a1) */
extern int DAT_003995dc[];
extern void FUN_000fbfa8(int, int);
extern void FUN_002350ec(int, int);

void FUN_00235074(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    FUN_000fbfa8(*(int *)(*(int *)(param_1 + 0x3c) + 0x30), DAT_003995dc[param_2]);
    if (param_5 != 0) {
        FUN_002350ec(param_1, param_2);
    }
}
