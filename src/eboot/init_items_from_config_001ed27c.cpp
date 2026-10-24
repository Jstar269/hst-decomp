/* HSTMATCH module=EBOOT.BIN start=0x001ed27c end=0x001ed460 symbol=FUN_001ed27c lang=c++ */
/* PrizeCamera_LoadCommonCamera: data/prize/commoncamera.csv; see docs/DATA-TABLES.md */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: C++ with an inline-constructed `new Res` (matching shape for `beqz v0; move s0,v0`), typed query results as floats, the two-entry item array indexed by the loop counter, first-call argument restored; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_002ee434[];
extern char DAT_002ee450[];
extern char DAT_002ee454[];
extern char DAT_002ee460[];
extern char DAT_002ee468[];
extern char DAT_002ee470[];
extern char DAT_002ee47c[];
extern char DAT_002ee484[];
extern char DAT_002ee48c[];
extern char DAT_002ee494[];
extern char DAT_002ee498[];
extern char DAT_003070bc[];
extern void FUN_000649c0(void *);
extern void FUN_0008c230(void *);
extern void FUN_000651b8(void *, char *, int, int, char *);
extern float FUN_000657e4(void *, char *, int);
extern void FUN_001ed460(void *);
}

struct Res {
  char pad[0x30];
  Res() {
    FUN_000649c0(this);
    *(char **)this = DAT_003070bc;
    FUN_0008c230(pad + 16);
    FUN_0008c230(pad + 32);
  }
};

struct Item {
  float a, b, c, d, e, f, g, h, i;
};

struct Obj {
  char pad[0x90];
  Res *res;
  char pad2[8];
  Item items[2];
};

extern "C" void FUN_001ed27c(Obj *self)
{
  FUN_001ed460(self);
  Res *p = new Res;
  self->res = p;
  FUN_000651b8(p, DAT_002ee434, 1, 1, DAT_002ee450);
  for (unsigned int i = 0; i < 2; i++) {
    Item *it = &self->items[i];
    int n = i + 1;
    it->a = FUN_000657e4(self->res, DAT_002ee454, n) * 0.017453292f * 0.033333335f;
    it->b = FUN_000657e4(self->res, DAT_002ee460, n) * 0.017453292f;
    it->c = FUN_000657e4(self->res, DAT_002ee468, n) * 0.017453292f;
    it->d = FUN_000657e4(self->res, DAT_002ee470, n);
    it->e = FUN_000657e4(self->res, DAT_002ee47c, n);
    it->f = FUN_000657e4(self->res, DAT_002ee484, n);
    it->g = FUN_000657e4(self->res, DAT_002ee48c, n);
    it->h = FUN_000657e4(self->res, DAT_002ee494, n);
    it->i = FUN_000657e4(self->res, DAT_002ee498, n) * 0.017453292f;
  }
}
