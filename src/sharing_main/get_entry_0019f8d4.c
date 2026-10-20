/* HSTMATCH module=hstp_trans_main.prx start=0x0019f8d4 end=0x0019f928 symbol=FUN_0019f8d4 lang=c99 */
/* Clone of src/eboot/get_entry_001930c4.c (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { int count; unsigned char *items; } Table;
extern Table *DAT_003eaa74;

unsigned char *FUN_0019f8d4(int index)
{
    if (DAT_003eaa74 != 0 && index >= 0 && (unsigned int)index < (unsigned int)DAT_003eaa74->count)
        return DAT_003eaa74->items + index * 108;
    return 0;
}
