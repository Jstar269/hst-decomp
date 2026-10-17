/* HSTMATCH module=EBOOT.BIN start=0x0013788c end=0x00137940 symbol=FUN_0013788c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256c) corrected by hand: typed char buffers, variadic sprintf-style prototype, do/while with unsigned counter; exact match verified; names and types await human review. */
extern int DAT_003313c4;
extern int DAT_003402a4;
extern char DAT_002db9bc[];
extern int FUN_000143b0(char *, const char *, ...);
extern int FUN_0004ccb8(char *, int, int);
extern void FUN_0004cfd0(int);
extern void FUN_0004d028(int, char *, int);
extern void FUN_0005c780(int, char *);
extern void FUN_0005c854(int, int, char *, char *);

void FUN_0013788c(int unused, int p2)
{
  char path[256];
  char data[80];
  int fd;
  unsigned i;
  char *p;
  FUN_000143b0(path, DAT_002db9bc, DAT_003402a4, p2);
  fd = FUN_0004ccb8(path, 1, 1);
  if (fd >= 0) {
    FUN_0004d028(fd, data, 0x50);
    FUN_0004cfd0(fd);
    FUN_0005c780(DAT_003313c4, data);
    i = 0;
    p = data;
    do {
      FUN_0005c854(DAT_003313c4, i, p + 0x10, p + 0x20);
      i++;
      p += 0x20;
    } while (i < 2);
  }
}
