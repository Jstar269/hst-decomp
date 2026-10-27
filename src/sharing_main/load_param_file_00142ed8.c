/* HSTMATCH module=hstp_trans_main.prx start=0x00142ed8 end=0x00142f8c symbol=FUN_00142ed8 lang=c99 data=0x00382c1c */
/* Clone of src/eboot/load_param_file_0013788c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00382c1c-0x00382c41) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag s256c) corrected by hand: typed char buffers, variadic sprintf-style prototype, do/while with unsigned counter; exact match verified; names and types await human review. */
extern int DAT_003da704;
extern int DAT_003e95e4;
extern int FUN_000143b0(char *, const char *, ...);
extern int FUN_0004cfac(char *, int, int);
extern void FUN_0004d2c4(int);
extern void FUN_0004d31c(int, char *, int);
extern void FUN_0005d408(int, char *);
extern void FUN_0005d580(int, int, char *, char *);

void FUN_00142ed8(int unused, int p2)
{
  char path[256];
  char data[80];
  int fd;
  unsigned i;
  char *p;
  FUN_000143b0(path, "data/court/%s/setting/light_%02d.dat", DAT_003e95e4, p2);
  fd = FUN_0004cfac(path, 1, 1);
  if (fd >= 0) {
    FUN_0004d31c(fd, data, 0x50);
    FUN_0004d2c4(fd);
    FUN_0005d408(DAT_003da704, data);
    i = 0;
    p = data;
    do {
      FUN_0005d580(DAT_003da704, i, p + 0x10, p + 0x20);
      i++;
      p += 0x20;
    } while (i < 2);
  }
}
