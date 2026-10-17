/* HSTMATCH module=EBOOT.BIN start=0x000c2028 end=0x000c2074 symbol=FUN_000c2028 */
/* Clone of src/eboot/FUN_000c20c0.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern int DAT_002d5a8c;
extern float DAT_003412e4, DAT_003412ec, DAT_003412f4;
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
