/* HSTMATCH module=EBOOT.BIN start=0x0029e024 end=0x0029e0e0 symbol=FUN_0029e024 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_002b7c18(int id);
extern int FUN_002b7cc0(int id);
extern void FUN_0029a584(char *msg, int val);
extern char DAT_002cb598[];
extern char DAT_002cb548[];
extern char DAT_002cb63c[];
extern char DAT_002cb5e8[];

enum { RESOURCE_FIRST = 256, RESOURCE_SECOND = 257 };  /* ids passed to the acquire/release calls */

/* Acquires both resources; on failure logs, releases both in reverse order (logging failures) and returns the error. */
int FUN_0029e024(void)
{
    int status;
    int release_status;

    status = FUN_002b7c18(RESOURCE_FIRST);
    if (status < 0) {
        FUN_0029a584(DAT_002cb598, status);
        goto release;
    }
    status = FUN_002b7c18(RESOURCE_SECOND);
    if (status < 0) {
        FUN_0029a584(DAT_002cb548, status);
        goto release;
    }
    return status;
release:
    release_status = FUN_002b7cc0(RESOURCE_SECOND);
    if (release_status < 0)
        FUN_0029a584(DAT_002cb63c, release_status);
    release_status = FUN_002b7cc0(RESOURCE_FIRST);
    if (release_status < 0)
        FUN_0029a584(DAT_002cb5e8, release_status);
    return status;
}
