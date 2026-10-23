/* HSTMATCH module=EBOOT.BIN start=0x000f075c end=0x000f0938 symbol=FUN_000f075c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Draw {
  int f00;
  char pad04[2];
  short f06;
  char pad08[2];
  short f0a;
  char pad0c[2];
  unsigned short f0e;
  char pad10[0x14];
  int f24;
  int f28;
} Draw;

extern int DAT_002d73f8[];
extern int *DAT_00338b44;

extern int FUN_000de208(int *, int);
extern int FUN_000de238(int *, int);
extern int FUN_000de268(int *, int);
extern int FUN_000de298(int *, int);
extern void FUN_000ffb3c(Draw *, int);

void FUN_000f075c(int param_1)
{
  int i;
  char *pp;
  int *tab;
  Draw *p;
  int base;
  short nv;
  short old;
  short d;

  pp = (char *)param_1;
  i = 0;
  tab = DAT_002d73f8;
  for (; i < 2; i++) {
    FUN_000ffb3c(*(Draw **)(pp + 0x60), 0);
    **(int **)(pp + 0x60) = 0x80808080;
    base = tab[2];
    if (FUN_000de208(DAT_00338b44, i) != 0) {
      p = *(Draw **)(pp + 0x60);
      p->f24 = base;
      p->f28 = base;
    } else if (FUN_000de238(DAT_00338b44, i) != 0) {
      p = *(Draw **)(pp + 0x60);
      p->f24 = base + 1;
      p->f28 = base + 1;
    } else if (FUN_000de268(DAT_00338b44, i) != 0) {
      p = *(Draw **)(pp + 0x60);
      p->f24 = base + 2;
      p->f28 = base + 2;
    } else {
      FUN_000ffb3c(*(Draw **)(pp + 0x60), 1);
      **(int **)(pp + 0x60) = 0x808080;
    }
    FUN_000ffb3c(*(Draw **)(pp + 0x68), 0);
    **(int **)(pp + 0x68) = 0x80808080;
    if (FUN_000de298(DAT_00338b44, i) != 0) {
      p = *(Draw **)(pp + 0x68);
      p->f24 = base + 3;
      p->f28 = base + 3;
      if ((*(unsigned short *)(*(int *)(pp + 0x60) + 0xe) & 3) != 0) {
        Draw *q = *(Draw **)(pp + 0x68);
        nv = (short)(int)*(float *)(pp + 0x70);
        old = q->f06;
        q->f06 = nv;
        d = nv - old;
        q->f0a = q->f0a + d;
      } else {
        Draw *q = *(Draw **)(pp + 0x68);
        nv = (short)(int)*(float *)(pp + 0x78);
        old = q->f06;
        q->f06 = nv;
        d = nv - old;
        q->f0a = q->f0a + d;
      }
    } else {
      FUN_000ffb3c(*(Draw **)(pp + 0x68), 1);
      **(int **)(pp + 0x68) = 0x808080;
    }
    pp += 4;
    tab += 3;
  }
}
