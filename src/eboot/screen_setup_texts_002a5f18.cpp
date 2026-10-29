/* HSTMATCH module=EBOOT.BIN start=0x002a5f18 end=0x002a625c symbol=FUN_002a5f18 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
enum { TEXT_COUNT = 14, TEXT_SIZE = 0x80 };

struct Model {
  char pad[0x24];
  int f24, f28;
};
struct Item {
  char pad[0xf8];
  char *name;
  char pad_fc[0x3c];
  int flag;
};
struct Screen {
  char pad0[0xb8];
  Model *model_b8;                   /* 0xb8 */
  char padbc[0x11c - 0xbc];
  Model *model_11c;                  /* 0x11c */
  char pad120[0x140 - 0x120];
  Item *items[TEXT_COUNT];           /* 0x140: item i shows text[i] */
  void *unk178;                      /* 0x178 */
  char pad17c[1];
  char text[TEXT_COUNT][TEXT_SIZE];  /* 0x17d */
  char pad87d[7];
  int unk884;                        /* 0x884 */
  char pad888[0x1558 - 0x888];
  unsigned char unk1558;             /* 0x1558 */
  char pad1559[0x16fc - 0x1559];
  int unk16fc;                       /* 0x16fc */
};

extern "C" {
extern char *DAT_003415a8;
extern int DAT_00300e48;
extern int DAT_00300f74;
extern char DAT_00301038[];
void FUN_0010b8cc(void *, int, int);
void FUN_002a69d0(void *, int);
int FUN_002af0e4(char *);
char *FUN_001fea10(int, int, int);
void FUN_000143b0(char *, char *, ...);
void FUN_002af0ec(char *, int *, int *);
int FUN_002af1ac(char *);
void FUN_000149a8(char *, char *);
float FUN_002af1bc(char *);
float FUN_002af1e8(char *);
int FUN_002af214(char *);
int FUN_002af21c(char *);
char *FUN_002af094(char *);
float FUN_002af0b4(char *);
int FUN_002af0a4(char *);
int FUN_002af0c4(char *);
int FUN_002af0cc(char *);
int FUN_002af0d4(char *);
void FUN_002a51ec(int, char *, char *);
void FUN_002a625c(void *);
void FUN_002a5e3c(void *, int);
void FUN_0010d4a8();

void FUN_002a5f18(Screen *self)
{
  char *stats;
  int n;
  int val_a, val_b;
  int v;
  float f;
  int p, q, r, rem;
  Model *m;

  stats = DAT_003415a8 + 0x87128;
  self->unk1558 = 0;
  self->unk884 = 9;
  FUN_0010b8cc(self->unk178, self->unk884, 2);
  FUN_002a69d0(self, self->unk884);
  v = FUN_002af0e4(stats);
  FUN_000143b0(self->text[1], FUN_001fea10(0x13, 0xd, 3), v);
  val_a = 0;
  val_b = 0;
  FUN_002af0ec(stats, &val_a, &val_b);
  FUN_000143b0(self->text[2], FUN_001fea10(0x13, 0xd, 2), val_a, val_b);
  FUN_000149a8(self->text[3], FUN_001fea10(0xe, 1, FUN_002af1ac(stats)));
  v = (int)(100.0f * FUN_002af1bc(stats));
  FUN_000143b0(self->text[4], FUN_001fea10(0x13, 0xd, 0), v);
  v = (int)(100.0f * FUN_002af1e8(stats));
  FUN_000143b0(self->text[5], FUN_001fea10(0x13, 0xd, 0), v);
  p = FUN_002af214(stats);
  q = FUN_002af21c(stats);
  rem = FUN_002af21c(stats) % 10;
  FUN_000149a8(self->text[6], FUN_001fea10(0xc, 0, p));
  FUN_000149a8(self->text[7], FUN_001fea10(0xd, 1, q));
  r = DAT_00300e48 + p;
  m = self->model_b8;
  m->f24 = r;
  m->f28 = r;
  if (q != 0 && q != 500) {
    self->unk16fc = rem;
  } else {
    self->unk16fc = -1;
  }
  FUN_000149a8(self->text[8], FUN_002af094(stats));
  f = FUN_002af0b4(stats);
  n = FUN_002af0a4(stats);
  FUN_000143b0(self->text[9], DAT_00301038, (double)f);
  r = DAT_00300f74 + n;
  m = self->model_11c;
  m->f24 = r;
  m->f28 = r;
  v = FUN_002af0c4(stats);
  FUN_000143b0(self->text[10], FUN_001fea10(0x13, 0xd, 1), v);
  v = FUN_002af0cc(stats);
  FUN_000143b0(self->text[11], FUN_001fea10(0x13, 0xd, 1), v);
  FUN_002a51ec(FUN_002af0d4(stats), self->text[12], self->text[13]);
  FUN_002a625c(self);
  {
    int i = 0;
    do {
      Item *it = self->items[i];
      it->name = self->text[i];
      it->flag = 1;
      FUN_0010d4a8();
      i++;
    } while (i < TEXT_COUNT);
  }
  FUN_002a5e3c(self, 0);
}
}
