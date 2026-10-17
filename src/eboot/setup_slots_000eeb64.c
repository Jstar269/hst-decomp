/* HSTMATCH module=EBOOT.BIN start=0x000eeb64 end=0x000eec94 symbol=FUN_000eeb64 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Node {
  char pad[0x24];
  int v24;
  int v28;
} Node;

typedef struct Obj {
  char pad[0x64];
  Node *n64;
  Node *n68;
  void *a[5];
  void *b[5];
} Obj;

typedef struct Info {
  char pad[0xc];
  short w;
  short h;
} Info;

typedef struct Cfg {
  char pad[0x1364];
  int idx;
} Cfg;

extern Cfg *DAT_003402a0;
extern void *DAT_0034a7ec;
extern int DAT_002d6f64;
extern int DAT_002d6f70;
extern void FUN_000eecc4(Obj *);
extern void FUN_001036f8(Obj *, int);
extern Info *FUN_0027edbc(void *, int);
extern int FUN_000ca4a4(void);
extern void FUN_000ffb3c(void *, int);

static inline void Set2(Node *n, int v)
{
  n->v24 = v;
  n->v28 = v;
}

void FUN_000eeb64(Obj *self)
{
  int mode;
  int idx;
  Info *info;
  int h, w;
  int i;

  FUN_000eecc4(self);
  FUN_001036f8(self, 0);
  mode = 0;
  idx = DAT_003402a0->idx;
  i = idx - 1;
  info = FUN_0027edbc(DAT_0034a7ec, idx);
  w = info->w;
  h = info->h;
  switch (FUN_000ca4a4()) {
  case 1:
    mode = 1;
    break;
  case 0:
    mode = 2;
    break;
  case 2:
    break;
  }
  Set2(self->n64, DAT_002d6f64 + i);
  Set2(self->n68, DAT_002d6f70 + mode);
  for (i = 0; i < 5; i++) {
    if (i < w) {
      FUN_000ffb3c(self->a[i], 0);
    } else {
      FUN_000ffb3c(self->a[i], 1);
    }
    if (i < h) {
      FUN_000ffb3c(self->b[i], 0);
    } else {
      FUN_000ffb3c(self->b[i], 1);
    }
  }
}
