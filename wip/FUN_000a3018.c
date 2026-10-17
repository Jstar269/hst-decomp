/* HSTMATCH module=EBOOT.BIN start=0x000a3018 end=0x000a3054 symbol=FUN_000a3018 */
int FUN_000a3018(int a, int b)
{
    switch (a) {
    case 1:
        return 0;
    case 11:
        return 0;
    }
    switch (b) {
    case 0:
    case 1:
        return 0;
    }
    return 1;
}
