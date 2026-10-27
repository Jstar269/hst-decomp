/* HSTMATCH module=EBOOT.BIN start=0x002adca0 end=0x002add24 symbol=FUN_002adca0 lang=c99 */
/* Clone of src/sharing_main/frames_to_hms_002bd4c8.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Split a 30-per-second frame count into hours, minutes and seconds, saturating at 99:59:59. */
void FUN_002adca0(unsigned int frames, unsigned int *h, unsigned int *m, unsigned int *s)
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
