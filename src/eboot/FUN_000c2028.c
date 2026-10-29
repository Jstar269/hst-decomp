/* HSTMATCH module=EBOOT.BIN start=0x000c2028 end=0x000c2074 symbol=FUN_000c2028 */
/* Clone of src/eboot/FUN_000c20c0.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern int DAT_002d5a8c;  /* selector, 0 to 2 */
extern float DAT_003412e4, DAT_003412ec, DAT_003412f4;  /* constants for selector 1, 0 and 2 */
/* Returns the float constant that belongs to the current selector (0.0f when it is out of range). */
float FUN_000c2028(void)
{
    switch (DAT_002d5a8c) {
    case 1:
        return DAT_003412e4;
    case 0:
        return DAT_003412ec;
    case 2:
        return DAT_003412f4;
    }
    return 0.0f;
}
