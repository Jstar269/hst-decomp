/* HSTMATCH module=hstp_trans_main.prx start=0x001a3c4c end=0x001a3c68 symbol=FUN_001a3c4c */
/* Clone of src/eboot/FUN_001972fc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[0x1bc]; int value; } Global1bc;
extern Global1bc *DAT_003eaaa8;

void FUN_001a3c4c(void)
{
    if (DAT_003eaaa8) DAT_003eaaa8->value = 0;
}
