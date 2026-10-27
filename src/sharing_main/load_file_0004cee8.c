/* HSTMATCH module=hstp_trans_main.prx start=0x0004cee8 end=0x0004cfac symbol=FUN_0004cee8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed prototypes, fd declared before size, the size test kept as the comma expression `(size = F(fd), size < 0)`, `fd >= 0` for the close test (the generated `-1 < fd` gives slti at); exact match verified; names and types await human review. */
extern char DAT_00376208[]; /* format string: LoadFile failed "%s" */
extern void FUN_0004cd60(const char *fmt, ...);
extern int FUN_0004cfac(const char *name, int a, int b);
extern int FUN_0004d3fc(int fd);
extern int FUN_0004d31c(int fd, void *buf, int size);
extern void FUN_0004d2c4(int fd);

void *FUN_0004cee8(void *buf, const char *name, int *psize)
{
    int fd;
    int size = 0;
    fd = FUN_0004cfac(name, 1, 1);
    if (fd < 0 || (size = FUN_0004d3fc(fd), size < 0) || FUN_0004d31c(fd, buf, size) != size)
        FUN_0004cd60(DAT_00376208, name);
    if (fd >= 0)
        FUN_0004d2c4(fd);
    if (psize)
        *psize = size;
    return buf;
}
