/* HSTMATCH module=hstp_trans_main.prx start=0x002bd4c8 end=0x002bd54c symbol=FUN_002bd4c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split a 30-per-second frame count into hours, minutes and seconds, saturating at 99:59:59. */
void FUN_002bd4c8(unsigned int frames, unsigned int *h, unsigned int *m, unsigned int *s)
{
    *s = frames / 30;
    *m = *s / 60;
    *h = *m / 60;
    if (*h > 99) {
        *h = 99;
        *m = 59;
        *s = 59;
    } else {
        *s %= 60;
        *m %= 60;
    }
}
