/* HSTMATCH module=EBOOT.BIN start=0x0029f70c end=0x0029f818 symbol=FUN_0029f70c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct view (readability pass), the early-return guard written as a nested if, typed prototypes (the two print calls take a format string and a value); exact match verified; names and types await human review. */

enum { READ_BUF_SIZE = 0x40000, READ_LEN_UNKNOWN = 0x7fffffff };

typedef struct ReadBuf {
  int unk0;               /* 0x00 */
  int source;             /* 0x04 handle passed to the source-empty check */
  char *buf;              /* 0x08 destination buffer of READ_BUF_SIZE bytes */
  int fill;               /* 0x0c bytes currently in buf */
  int total_read;         /* 0x10 bytes read so far */
  int length;             /* 0x14 total length, READ_LEN_UNKNOWN until probed */
  int unk18;              /* 0x18 second value probed together with length */
  char pad1c[9];
  unsigned char at_end;   /* 0x25 set when the source has nothing more */
  char pad26[0x1b4 - 0x26];
  int reader;             /* 0x1b4 handle passed to the read call */
} ReadBuf;

extern char DAT_002cba34[];
extern char DAT_002cba4c[];
extern int FUN_000c06dc(int);
extern int FUN_000ff3cc(char *, int);
extern int FUN_000ff3f0(char *, int);
extern int FUN_000ff678(int, char *, int, int);
extern void FUN_0029e3cc(char *, int);

/* Tops the buffer up from the reader until target bytes were read; the first successful read also probes the stream length. */
void FUN_0029f70c(ReadBuf *self, int target)
{
  int filled;
  int got;

  if (self->total_read >= self->length) {
    if (FUN_000c06dc(self->source) < 1) {
      self->at_end = 1;
      return;
    }
  }
  if (self->total_read < target && (filled = self->fill) < READ_BUF_SIZE) {
    got = FUN_000ff678(self->reader, self->buf + filled, READ_BUF_SIZE - filled, 0);
    self->fill = self->fill + got;
    self->total_read = self->total_read + got;
    if (self->length == READ_LEN_UNKNOWN && (got = FUN_000ff3cc(self->buf, self->fill)) >= 0) {
      self->length = got;
      self->unk18 = FUN_000ff3f0(self->buf, self->fill);
      FUN_0029e3cc(DAT_002cba4c, self->length);
      FUN_0029e3cc(DAT_002cba34, self->unk18);
    }
  }
}
