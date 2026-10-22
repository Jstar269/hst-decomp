/* HSTMATCH module=hstp_trans_main.prx start=0x0025df78 end=0x0025dfc4 symbol=FUN_0025df78 lang=c99 */
/* Clone of src/eboot/threshold_search_0024dd40.c (hstclone.py tag c23fbop): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: the loop-exit return is a plain 0 (the counter is already -1 there, which is
   why retail folds it to `move v0,zero` instead of `addiu v0,a1,1`); exact match verified; names and types await human review. */
int FUN_0025df78(float value, int base)
{
    base += 0x20;
    int i = 8;
    do {
        if (*(float *)(base + 0x30) <= value)
            return i + 1;
        i--;
        base -= 4;
    } while (i >= 0);
    return 0;
}
