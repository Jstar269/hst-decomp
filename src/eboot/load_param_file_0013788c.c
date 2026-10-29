/* HSTMATCH module=EBOOT.BIN start=0x0013788c end=0x00137940 symbol=FUN_0013788c lang=c99 data=0x002db9bc */
/* Ghidra pseudocode (hstgen.py tag s256c) corrected by hand: typed char buffers, variadic sprintf-style prototype, do/while with unsigned counter; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002db9bc-0x002db9e1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern int DAT_003313c4;
extern int DAT_003402a4;
extern int FUN_000143b0(char *, const char *, ...);
extern int FUN_0004ccb8(char *, int, int);
extern void FUN_0004cfd0(int);
extern void FUN_0004d028(int, char *, int);
extern void FUN_0005c780(int, char *);
extern void FUN_0005c854(int, int, char *, char *);

#define LIGHT_FILE_SIZE 0x50  /* bytes read from the file */
#define LIGHT_COUNT 2

typedef struct LightEntry {
  char a[0x10];  /* 0x00 */
  char b[0x10];  /* 0x10 */
} LightEntry;

typedef struct LightFile {
  char head[0x10];                /* 0x00 handed to the first call */
  LightEntry entry[LIGHT_COUNT];  /* 0x10 */
} LightFile;

/* Reads the per-court light file number `index` (data/court/<name>/setting) and applies it entry by entry. */
void FUN_0013788c(int unused, int index)
{
  char path[256];
  LightFile data;
  int fd;
  unsigned i;
  FUN_000143b0(path, "data/court/%s/setting/light_%02d.dat", DAT_003402a4, index);
  fd = FUN_0004ccb8(path, 1, 1);
  if (fd >= 0) {
    FUN_0004d028(fd, (char *)&data, LIGHT_FILE_SIZE);
    FUN_0004cfd0(fd);
    FUN_0005c780(DAT_003313c4, data.head);
    i = 0;
    do {
      FUN_0005c854(DAT_003313c4, i, data.entry[i].a, data.entry[i].b);
      i++;
    } while (i < LIGHT_COUNT);
  }
}
