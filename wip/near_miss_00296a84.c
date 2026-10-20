/* HSTMATCH module=EBOOT.BIN start=0x00296a84 end=0x00296adc symbol=FUN_00296a84 lang=c99 */
extern int FUN_002969e0(char *, int);

int FUN_00296a84(char *text, int unused, int size)
{
    int i = 0;

    if (size != 0) {
        if (text[0] != 0) {
            i = 1;
            while (i < size) {
                if (text[i] == 0)
                    break;
                i++;
            }
        }
    }
    return FUN_002969e0(text + i, size - i);
}
// Near miss: frame + calls are right at gcc171-O2 (22/22 words) but gcc keeps the walking pointer in a0 while retail keeps i in a0, text in a3/v1
// near miss from lane ds8 (unreviewed)
