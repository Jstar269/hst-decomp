/* HSTMATCH module=hstp_trans_main.prx start=0x002bd0f4 end=0x002bd154 symbol=FUN_002bd0f4 lang=c99 */
/* Clone of src/eboot/select_global_mode_002ad938.c (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Earlier lane sn7 reconstruction corrected by GPT-6.1 Terra (Freebuff): disabled common-subexpression optimization to match constant materialization; exact match verified; names and types await human review. */
#pragma opt_common_subs off

extern int DAT_003f39a8;
extern int FUN_00177d4c();
extern void FUN_002bcf14(int, int, int);

void FUN_002bd0f4(void)
{
    int m = 0;
    switch (DAT_003f39a8) {
    case 2: m = 2; break;
    case 0x20: m = 2; break;
    }
    FUN_002bcf14(m, FUN_00177d4c(), 0);
}
