/* HSTMATCH module=hstp_trans_main.prx start=0x0011173c end=0x0011177c symbol=FUN_0011173c */
/* Clone of src/eboot/FUN_0010b564.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern void FUN_00107684(void *a, int b);
extern void FUN_00110f78(void *a);

void FUN_0011173c(void *a, int b)
{
    FUN_00107684(a, b);
    if (b == 0) FUN_00110f78(a);
}
