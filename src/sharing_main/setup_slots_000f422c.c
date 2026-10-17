/* HSTMATCH module=hstp_trans_main.prx start=0x000f422c end=0x000f435c symbol=FUN_000f422c lang=c99 */
/* Clone of src/eboot/setup_slots_000eeb64.c (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
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

extern Cfg *DAT_003e95e0;
extern void *DAT_003f3b1c;
extern int DAT_0037dd3c;
extern int DAT_0037dd48;
extern void FUN_000f438c(Obj *);
extern void FUN_00109024(Obj *, int);
extern Info *FUN_00290230(void *, int);
extern int FUN_000ce044(void);
extern void FUN_00105470(void *, int);

static inline void Set2(Node *n, int v)
{
  n->v24 = v;
  n->v28 = v;
}

void FUN_000f422c(Obj *self)
{
  int mode;
  int idx;
  Info *info;
  int h, w;
  int i;

  FUN_000f438c(self);
  FUN_00109024(self, 0);
  mode = 0;
  idx = DAT_003e95e0->idx;
  i = idx - 1;
  info = FUN_00290230(DAT_003f3b1c, idx);
  w = info->w;
  h = info->h;
  switch (FUN_000ce044()) {
  case 1:
    mode = 1;
    break;
  case 0:
    mode = 2;
    break;
  case 2:
    break;
  }
  Set2(self->n64, DAT_0037dd3c + i);
  Set2(self->n68, DAT_0037dd48 + mode);
  for (i = 0; i < 5; i++) {
    if (i < w) {
      FUN_00105470(self->a[i], 0);
    } else {
      FUN_00105470(self->a[i], 1);
    }
    if (i < h) {
      FUN_00105470(self->b[i], 0);
    } else {
      FUN_00105470(self->b[i], 1);
    }
  }
}
