/* HSTMATCH module=EBOOT.BIN start=0x002ad938 end=0x002ad998 symbol=FUN_002ad938 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Earlier lane sn7 reconstruction corrected by GPT-6.1 Terra (Freebuff): disabled common-subexpression optimization to match constant materialization; exact match verified; names and types await human review. */
#pragma opt_common_subs off

extern int DAT_0034a678;
extern int FUN_0016bb88();
extern void FUN_002ad758(int, int, int);

void FUN_002ad938(void)
{
    int m = 0;
    switch (DAT_0034a678) {
    case 2: m = 2; break;
    case 0x20: m = 2; break;
    }
    FUN_002ad758(m, FUN_0016bb88(), 0);
}
