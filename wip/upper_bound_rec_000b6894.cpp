/* HSTMATCH module=EBOOT.BIN start=0x000b6894 end=0x000b6990 symbol=FUN_000b6894 lang=c++ */
struct Rec {
  float f[20];
};

struct It {
  Rec *p;
  It() {}
  It(Rec *q) : p(q) {}
  int operator-(const It &o) const { return p - o.p; }
};

static inline bool Less(Rec a, Rec b)
{
  return a.f[14] < b.f[14];
}

static inline int Dist(It a, It b)
{
  return b.p - a.p;
}

extern "C" It FUN_000b6894(It first, It last, const Rec *key)
{
  int n = last - first;
  while (n > 0) {
    int half = n / 2;
    It mid(first.p + half);
    if (!Less(*key, *mid.p)) {
      first = It(mid.p + 1);
      n = n - (half + 1);
    } else {
      n = half;
    }
  }
  return first;
}
// NEAR (sy2): upper_bound over 80-byte records. Decoded this pass: sret return of a one-word iterator class WITH user ctors (hidden a0,
// `sw a1,0(a0)` in the blezl slot, matches retail), comparison = inline Less(Rec a, Rec b) taking BOTH records by value (first param copy at
// sp+96, second at sp+16: the lower_bound twin 0xb6990 has them the other way round because its call is Less(*mid, key)), key copy hoisted
// out of the loop, result `!Less(*key, *mid)` -> first = mid + 1. 58/63 words but the tail diff is dominated by retail's 192-byte frame:
// retail spills the by-value iterator `first` (sw a1,184; lwc1/swc1 to 180; lw t0,180 feeding `last - first`) and ours keeps it in a1,
// so the copies sit at 92/8 instead of 96/16. Not found: what makes `first` (but not `last`) memory resident without volatile
// (tried: Dist(It,It) inline by value, It::operator-(const It&), local copy `It f = first`, POD It (then returns in v0)).
// near miss from lane sy2 (unreviewed)
