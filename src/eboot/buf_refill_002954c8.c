/* HSTMATCH module=EBOOT.BIN start=0x002954c8 end=0x002955b4 symbol=FUN_002954c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_000ff3cc(int, int);
extern int FUN_000ff3f0(int, int);
extern int FUN_000ff678(int, int, int, int);
extern void FUN_00294684(int *, int);
extern int DAT_002cad60;
extern int DAT_002cad48;

typedef struct Buf {
  int f0;
  int f4;
  int pos;
  int len;
  int cap;
  int f14;
  char pad18[0x21 - 0x18];
  unsigned char eof;
  char pad22[0x334 - 0x22];
  int h334;
} Buf;

void FUN_002954c8(Buf *b, int param_2)
{
  int iVar1;

  if (b->len >= b->cap) {
    b->eof = 1;
    return;
  }
  if (b->len >= param_2) {
    return;
  }
  if (b->pos >= 0x80000) {
    return;
  }
  iVar1 = FUN_000ff678(b->h334, b->f4 + b->pos, 0x80000 - b->pos, 0);
  b->pos = b->pos + iVar1;
  b->len = b->len + iVar1;
  if (b->cap != 0x7fffffff) {
    return;
  }
  iVar1 = FUN_000ff3cc(b->f4, b->pos);
  if (iVar1 < 0) {
    return;
  }
  b->cap = iVar1;
  iVar1 = FUN_000ff3f0(b->f4, b->pos);
  b->f14 = iVar1;
  FUN_00294684(&DAT_002cad60, b->cap);
  FUN_00294684(&DAT_002cad48, b->f14);
}
