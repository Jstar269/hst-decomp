/* HSTMATCH module=EBOOT.BIN start=0x002954c8 end=0x002955b4 symbol=FUN_002954c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_000ff3cc(int, int);
extern int FUN_000ff3f0(int, int);
extern int FUN_000ff678(int, int, int, int);
extern void FUN_00294684(int *, int);
extern int DAT_002cad60; /* "Send File Size = %d\n" */
extern int DAT_002cad48; /* "EBOOT.PBP Size = %d\n" */

#define BUF_CAPACITY 0x80000   /* size of the staging buffer */
#define SIZE_UNKNOWN 0x7fffffff /* file size before the header has been parsed */

typedef struct Buf {
  int f0;
  int data;        /* 0x04 staging buffer */
  int pos;         /* 0x08 bytes currently in the staging buffer */
  int total;       /* 0x0c bytes read so far */
  int size;        /* 0x10 file size to send, SIZE_UNKNOWN until known */
  int pbp_size;    /* 0x14 size of the EBOOT.PBP part */
  char pad18[0x21 - 0x18];
  unsigned char eof;
  char pad22[0x334 - 0x22];
  int reader;      /* 0x334 handle the data is read from */
} Buf;

/* Read more of the file into the staging buffer until `want` bytes are available. */
void FUN_002954c8(Buf *b, int want)
{
  int n;

  if (b->total >= b->size) {
    b->eof = 1;
    return;
  }
  if (b->total >= want) {
    return;
  }
  if (b->pos >= BUF_CAPACITY) {
    return;
  }
  n = FUN_000ff678(b->reader, b->data + b->pos, BUF_CAPACITY - b->pos, 0);
  b->pos = b->pos + n;
  b->total = b->total + n;
  if (b->size != SIZE_UNKNOWN) {
    return;
  }
  n = FUN_000ff3cc(b->data, b->pos);
  if (n < 0) {
    return;
  }
  b->size = n;
  n = FUN_000ff3f0(b->data, b->pos);
  b->pbp_size = n;
  FUN_00294684(&DAT_002cad60, b->size);
  FUN_00294684(&DAT_002cad48, b->pbp_size);
}
