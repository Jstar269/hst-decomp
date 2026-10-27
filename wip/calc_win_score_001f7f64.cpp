/* HSTMATCH module=EBOOT.BIN start=0x001f7f64 end=0x001f8858 symbol=FUN_001f7f64 lang=c++ rodata=0x002c9130 helpers=FUN_001ef3f8@0x001ef3f8-0x001ef424 */
struct Cfg {
  char pad[0xb8];
  int sets[2];
};
struct Match {
  char pad0[0x25c];
  char win[2][80];
  char val[2][80];
  char pad1[0x3dc - 0x39c];
  int my;
  int rival;
  char pad2[0x521 - 0x3e4];
  unsigned char won;
  char pad3[2];
  int result;
  int res[2];
  int pad530;
  int score[2];
  char pad4[0x548 - 0x53c];
  int numGames;
  int rate[2];
  float yuragi;
  char pad5[0x590 - 0x558];
  int forced;
  char pad6[0x5ae - 0x594];
  unsigned char flag;
};

extern "C" {
extern Cfg *DAT_00338b44;
extern int DAT_002eebb8;
extern int DAT_002eebbc;
extern float DAT_002eebc0;
extern float DAT_002eebc4;
extern char DAT_0034b5a0[];
extern char DAT_002eeb40[];
extern char DAT_002eebc8[];
extern char DAT_002eebdc[];
extern char DAT_002eebf0[];
extern char DAT_002eec00[];
extern char DAT_002eec10[];
extern char DAT_002eec1c[];
extern char DAT_002eec28[];
extern char DAT_002eec34[];
extern char DAT_002eec48[];
extern char DAT_002eec50[];
extern char DAT_002eec58[];
extern char DAT_002eec70[];
extern char DAT_002eec84[];
extern char DAT_002eec98[];
extern char DAT_002eeca0[];
extern char DAT_002eeca8[];
extern char DAT_002eecb4[];
extern char DAT_002eecc0[];
extern char DAT_002eecc8[];
extern char DAT_002eecd0[];
extern char DAT_002eecd8[];
extern char DAT_002eece4[];
extern char DAT_002eecf4[];
int FUN_00065740(void *, const char *, int);
int FUN_0006531c(void *, const char *);
int FUN_00065104(void *, int, int);
int FUN_000143b0(char *, const char *, ...);
int FUN_0000d62c(const char *);
static void FUN_001ef3f8(...) { }
}

static inline int Clamp(const int &v, const int &lo, const int &hi) { return v < lo ? lo : (hi < v ? hi : v); }
static inline float ClampV(float v, float lo, float hi) { return v < lo ? lo : (!(v > hi) ? v : hi); }
static inline float ClampF(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (!(v > hi) ? v : hi); }

extern "C" void FUN_001f7f64(Match *self)
{
  int my = self->my;
  int rv = self->rival;
  int rate[2] = {0};
  bool forced = false;
  FUN_001ef3f8(DAT_002eebc8);
  if (self->flag != 0) {
    rate[my] = 0;
    self->numGames = 0;
    self->result = 0;
    rate[rv] = 100;
  } else {
    int games[2] = {0};
    int i;
    int *pgm = &games[my];
    int *pgr = &games[rv];
    for (i = 0; i < 50; i++) {
      if (self->win[my][i] != 0) {
        (*pgm)++;
      } else if (self->win[rv][i] != 0) {
        (*pgr)++;
      } else {
        break;
      }
    }
    self->numGames = i;
    FUN_001ef3f8(DAT_002eebdc, i);
    FUN_001ef3f8(DAT_002eebf0, games[0], games[1]);
    int gr = games[rv];
    int total = Clamp(games[my] + gr, DAT_002eebb8, DAT_002eebbc);
    int *pm = &rate[my];
    *pm = games[my] * 100 / total;
    int *pr = &rate[rv];
    *pr = gr * 100 / total;
    FUN_001ef3f8(DAT_002eec00, *pm);
    if (DAT_00338b44->sets[my] > DAT_00338b44->sets[rv]) {
      int f = self->forced;
      if (f > 0) {
        switch (f) {
        case 1:
          forced = true;
          self->result = 5;
          *pm = 100;
          *pr = 0;
          break;
        case 2:
          self->result = 4;
          *pm = 80;
          forced = true;
          *pr = 20;
          break;
        case 3:
          self->result = 3;
          *pm = 60;
          forced = true;
          *pr = 40;
          break;
        }
      } else if (*pm >= FUN_00065740(DAT_0034b5a0, DAT_002eec10, 1)) {
        self->result = 5;
      } else if (*pm >= FUN_00065740(DAT_0034b5a0, DAT_002eec1c, 1)) {
        self->result = 4;
      } else {
        self->result = 3;
      }
    } else if (DAT_00338b44->sets[rv] > DAT_00338b44->sets[my]) {
      if (*pr >= FUN_00065740(DAT_0034b5a0, DAT_002eec10, 1)) {
        self->result = 0;
      } else if (*pr >= FUN_00065740(DAT_0034b5a0, DAT_002eec1c, 1)) {
        self->result = 1;
      } else {
        self->result = 2;
      }
    }
  }
  self->res[my] = self->result;
  self->res[rv] = 5 - self->result;
  switch (self->result) {
  case 0:
  case 1:
  case 2:
    self->won = 0;
    break;
  case 3:
  case 4:
  case 5:
    self->won = 1;
    break;
  }
  FUN_001ef3f8(DAT_002eec28, self->result);
  self->rate[0] = rate[0];
  self->rate[1] = rate[1];
  FUN_001ef3f8(DAT_002eec34);
  float score = 0.0f;
  int t, o;
  if (self->won) {
    t = my;
    o = rv;
  } else {
    t = rv;
    o = my;
  }
  if (self->flag != 0) {
    self->yuragi = 0.0f;
    score = 100.0f;
  } else if (forced) {
    switch (self->forced) {
    case 1:
      score = 100.0f;
      self->yuragi = 1.0f;
      break;
    case 2:
      score = (float)(FUN_00065740(DAT_0034b5a0, DAT_002eec48, 1) - 1);
      self->yuragi = 1.0f;
      break;
    case 3:
      score = (float)(FUN_00065740(DAT_0034b5a0, DAT_002eec50, 1) - 1);
      self->yuragi = 1.0f;
      break;
    }
  } else {
    int n = self->numGames;
    int sum = 0;
    for (int i = 0; i < self->numGames; i++) {
      FUN_001ef3f8(DAT_002eec58, i, self->win[0][i], self->win[1][i], self->val[0][i], self->val[1][i]);
      if (self->win[t][i] != 0) {
        FUN_001ef3f8(DAT_002eec70, 3 - self->val[o][i]);
        sum += 3 - self->val[o][i];
      } else {
        FUN_001ef3f8(DAT_002eec70, self->val[t][i]);
        sum += self->val[t][i];
      }
    }
    FUN_001ef3f8(DAT_002eec84, sum);
    FUN_001ef3f8(DAT_002eec98, 3);
    FUN_001ef3f8(DAT_002eeca0, n);
    int d = n * 3;
    if (d == 0) d = 1;
    float y = ClampF((float)sum / (float)d, DAT_002eebc0, DAT_002eebc4);
    FUN_001ef3f8(DAT_002eeca8, (double)y);
    int v = rate[t];
    self->yuragi = y;
    int idx;
    bool lim = false;
    if (v >= 100) {
      idx = FUN_0006531c(DAT_0034b5a0, DAT_002eecb4);
    } else if (v >= 80) {
      idx = FUN_0006531c(DAT_0034b5a0, DAT_002eecc0);
      lim = true;
    } else if (v >= 65) {
      idx = FUN_0006531c(DAT_0034b5a0, DAT_002eecc8);
      lim = true;
    } else {
      idx = FUN_0006531c(DAT_0034b5a0, DAT_002eecd0);
      lim = true;
    }
    int lo = FUN_00065104(DAT_0034b5a0, idx, 1);
    int hi = FUN_00065104(DAT_0034b5a0, idx + 1, 1);
    float df = (float)(hi - lo);
    df *= y;
    score = (float)lo + df;
    if (lim) score = ClampV(score, (float)lo, (float)(hi - 1));
  }
  char buf[32];
  FUN_000143b0(buf, DAT_002eeb40, (double)score);
  int n = FUN_0000d62c(buf);
  if (n <= FUN_00065740(DAT_0034b5a0, DAT_002eecd0, 1)) n = FUN_00065740(DAT_0034b5a0, DAT_002eecd0, 1) + 1;
  if (self->won) {
    self->score[self->my] = n;
    self->score[self->rival] = 100 - self->score[self->my];
  } else {
    self->score[self->rival] = n;
    self->score[self->my] = 100 - self->score[self->rival];
  }
  FUN_001ef3f8(DAT_002eecd8, self->score[self->my]);
  FUN_001ef3f8(DAT_002eece4, self->score[self->rival]);
  if (self->score[self->my] == 89) FUN_001ef3f8(DAT_002eecf4);
}
// NEAR MISS 573/573 words, 28 differ. Remaining: (1) win-count loop prelude: retail computes the rival row
// (self+rv*80) first and keeps my-row in v0, &games[rv] in t0 (ours a3/v0); (2) retail keeps games[my] and the
// rival's val byte in t0 where ours uses a2 (same "t0 instead of an a-reg" class as 0x20da38); (3) score clamp
// `bc1f` + speculative `addiu v0,v0,-1` in the slot, ours `bc1fl`. Ruled out for (1): pointer-free loop,
// Ghidra-shaped nested if, do/while, row pointer locals (+3 words), pgr declared first, games read via the
// pointers afterwards. For (3): ClampV with const& on v/lo/hi (hi const& +114), hoisted `top` local.
// Solved: static log stub via helpers=, rodata=0x002c9130 (lui 0x2d -28368), int Clamp by const& returning
// a value, `sets[my] > sets[rv]` operand order (MWCC loads the right operand first), *pm/*pr compared after
// the calls (pm/pr live in s0/s5), forced=true before the *pr store, `float df=(float)(hi-lo); df*=y;`
// (value-first mul), by-value ClampV for the score (hi converted lazily), idx declared before lim.
// near miss from lane wf20261026-e01-10 (unreviewed)
