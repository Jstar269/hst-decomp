/* HSTMATCH module=EBOOT.BIN start=0x001833f4 end=0x0018379c symbol=FUN_001833f4 lang=c++ */
struct Cfg {
  char pad0[0x43];
  unsigned char f43;
  char pad44[0x3c];
  int v0, v1;
  int count;
};
struct Rec {
  char pad[8];
  unsigned char f8;
  char pad9[2];
  unsigned char fb;
  unsigned char fc;
};
struct RowArr {
  Rec **items;
  int n, pad;
};
struct Ctx {
  char pad[4];
  int col;
  int row;
  char pad0c[0xc];
  RowArr *rows;
};
struct Label {
  char pad[4];
  void *text;
  char pad8[0x173c];
  char buf[1];
};

extern "C" {
extern char *DAT_002e082c;
extern char DAT_002e097c[];
Cfg *FUN_0016bc70();
char *FUN_001fea10(int, int, int);
char *FUN_001fecb4(int);
char *FUN_001fec00(int);
void FUN_00110a78(void *, char *, int);
void FUN_000143b0(char *, char *, ...);
void FUN_00014a40(char *);
void *FUN_00000a90(unsigned);
void FUN_000149a8(void *, char *);
int FUN_00014934(void *, char *);
void FUN_000009e4(void *);

void FUN_001833f4(Label *self, int id, int arg, int flag, Ctx *ctx)
{
  char *p = (char *)ctx->rows[ctx->row].items[ctx->col];
  bool alt;
  char *str;
  if (self->text == 0) {
    return;
  }
  if (id == 0x7fff) {
    FUN_00110a78(self->text, FUN_001fea10(0x12, 0x18, 2), 0);
    return;
  }
  if (id == 0x7ffe) {
    FUN_00110a78(self->text, FUN_001fea10(0x12, 0x18, 1), 0);
    return;
  }
  alt = false;
  str = 0;
  if (FUN_0016bc70()->f43 != 0) {
    alt = true;
    str = FUN_001fea10(0x12, 0x1a, 0);
  } else if (((Rec *)p)->f8 != 0) {
    FUN_00110a78(self->text, FUN_001fea10(0x12, 0x16, 0), 0);
  } else if (((Rec *)p)->fb != 0) {
    FUN_00110a78(self->text, FUN_001fea10(0x12, 0x16, 1), 0);
  } else if (((Rec *)p)->fc != 0) {
    p = (char *)FUN_0016bc70();
    switch (((Cfg *)p)->count) {
    case 1: {
      p = (char *)FUN_0016bc70();
      int a = ((Cfg *)p)->count > 0 ? ((Cfg *)p)->v0 : 0;
      char *fmt = FUN_001fea10(0x12, 0x16, 2);
      char *sa = FUN_001fecb4(a);
      FUN_000143b0(self->buf, fmt, sa);
      break;
    }
    case 2: {
      p = (char *)FUN_0016bc70();
      int a = ((Cfg *)p)->count > 0 ? ((Cfg *)p)->v0 : 0;
      p = (char *)FUN_0016bc70();
      int b = ((Cfg *)p)->count > 1 ? ((Cfg *)p)->v1 : 0;
      char *fmt = FUN_001fea10(0x12, 0x16, 3);
      char *sa = FUN_001fecb4(a);
      char *sb = FUN_001fecb4(b);
      FUN_000143b0(self->buf, fmt, sa, sb);
      break;
    }
    }
    FUN_00110a78(self->text, self->buf, 0);
  } else {
    alt = true;
    str = FUN_001fea10(0x12, 0x17, id);
  }
  if (alt) {
    char *s1 = FUN_001fea10(0xd, 0, arg);
    char *s2 = FUN_001fec00(arg);
    FUN_00014a40(DAT_002e082c);
    FUN_00014a40(s1);
    FUN_00014a40(str);
    FUN_00014a40(s2);
    p = (char *)FUN_00000a90(0x800);
    FUN_000149a8(p, self->buf);
    if (flag != 0) {
      FUN_000143b0(self->buf, DAT_002e097c, str, DAT_002e082c, s1, DAT_002e082c, s2);
    } else {
      FUN_000143b0(self->buf, DAT_002e097c, s1, DAT_002e082c, s2, DAT_002e082c, str);
    }
    if (FUN_00014934(p, self->buf) == 0) {
      FUN_00110a78(self->text, self->buf, 0);
    } else {
      FUN_00110a78(self->text, self->buf, 1);
    }
    if (p != 0) {
      FUN_000009e4(p);
    }
  }
}
}
// NEAR MISS (234/234 words; 60 words differ, ALL of them saved-register names only; sn3, ~25 compiles): opcodes, branches, delay slots and schedule match
// retail once (a) the Ghidra goto web is written as an else-if chain (cfg->f43, rec->f8, rec->fb, rec->fc != 0 {switch (cfg->count) {case 1, case 2}}, else alt),
// (b) the count picks are `count > 0 ? v0 : 0` / `count > 1 ? v1 : 0` (zero in the likely slot), (c) the flag test is `if (flag != 0) {fmt(str,..)} else {fmt(s1,..)}`.
// Retail colours: flag s6, id s5, rec s4 (reused for the count/aux values), self s3, arg s2 (reused for B), alt s1 (reused for the buffer), str s0;
// ours: flag s6, id s5, self s4, arg s3, alt s2, str s1, rec s0. Ruled out: declaration order of rec/alt/str (6 permutations), alias copies of self/arg, rec
// declared late, reusing one `p` for rec/cfg/buffer (word count drops to 231 and the colours do not change).
// near miss from lane sn3 (unreviewed)
