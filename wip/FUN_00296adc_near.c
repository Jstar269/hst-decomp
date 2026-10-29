/* HSTMATCH module=EBOOT.BIN start=0x00296adc end=0x00296b14 symbol=FUN_00296adc lang=c99 */
int FUN_00296adc(signed char *a, signed char *b, int n)
{
    int r = 0;
    if (n != 0) {
        for (;;) {
            if (*a++ != *b++) { r = 1; break; }
            if (--n == 0) { r = 0; break; }
        }
    }
    return r;
}
// improved by lane dsn3 (unreviewed): 16 -> 14 differing words
