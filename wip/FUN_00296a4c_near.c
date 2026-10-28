/* HSTMATCH module=EBOOT.BIN start=0x00296a4c end=0x00296a84 symbol=FUN_00296a4c lang=c99 */
int FUN_00296a4c(const char *s, unsigned int max)
{
    unsigned int i = 0;
    if (max == 0)
        return i;
    if (*s == 0)
        return i;
    for (;;) {
        i++;
        if (i >= max)
            break;
        s++;
        if (*s == 0)
            break;
    }
    return i;
}
// NEAR (5 words, 56 bytes): retail's bnezl loop-back targets the bounds test (`sltu` first, counter
// incremented in the branch delay) and the pointer step sits in the beqz delay; our statement order puts
// i++ first and produces a 19-word function (predicated hoisting).
// near miss from lane dsn3 (unreviewed)
