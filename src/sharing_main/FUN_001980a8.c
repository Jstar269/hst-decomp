/* HSTMATCH module=hstp_trans_main.prx start=0x001980a8 end=0x001980f4 symbol=FUN_001980a8 */
/* Clone of src/eboot/FUN_0018b8f8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[60]; int value; char rest[0x2000 - 64]; } Slot18b;
typedef struct { Slot18b slots[4]; } Row18b;

int *FUN_001980a8(Row18b *rows, int row, int slot)
{
    if (row >= 0 && row < 15 && slot >= 0 && slot < 4) return &rows[row].slots[slot].value;
    return 0;
}
