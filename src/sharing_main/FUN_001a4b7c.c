/* HSTMATCH module=hstp_trans_main.prx start=0x001a4b7c end=0x001a4bcc symbol=FUN_001a4b7c */
/* Clone of src/eboot/FUN_00198228.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
extern void FUN_001a49ec(void *a, void *b, char *buf);
extern void FUN_001a4184(void *a, char *buf, void *c, int d, int e, int f);

void FUN_001a4b7c(void *a, void *b, void *c)
{
    char buf[1024];
    FUN_001a49ec(a, b, buf);
    FUN_001a4184(a, buf, c, 1, 0, 0);
}
