/* HSTMATCH module=EBOOT.BIN start=0x00235da4 end=0x00235fe0 symbol=FUN_00235da4 lang=c++ */
// NEAR MISS 141/143 words, 125 differ (retail 143). Two words short, everything else agrees in shape.
// What is confirmed: the three `List` slots at param_1 stride 0xc are { Shot *data; int count; int cap; },
// the loader object is ONE 0x30-byte local (void *key[4] at +0, two 16-byte buffers at +0x10/+0x20) because
// retail addresses the second buffer as `s0+0x20` with s0 = &ctx, the six keyed lookups land in a 12-byte
// Shot, `shot.aino / 100` is the signed /100 sequence (*0x51eb851f, mfhi, sra 5, + sign) then *12, and the
// 12-byte copy is MWCC's own 3-iteration two-halfword block-copy loop: a struct made of THREE 4-byte
// `Pair { short lo, hi; }` members (`*elem = shot` with `struct Shot { Pair p[3]; }`) reproduces it exactly,
// while a flat six-short Shot is fully unrolled into six lh/sh pairs (13 words vs 10) and any hand-written
// loop with a literal trip count is unrolled too.
// What still differs: retail materialises `addiu a3,a0,4` (&list->count) in the branch delay slot and does
// both count reloads plus the final store through a3 (`lw v0,0(a3)` / `sw v0,0(a3)`); ours keeps `4(a0)`.
// Because a3 is taken, retail's loop colours src=a1 dst=a2 counter=a0, ours colours src=a2 dst=a3 counter=a1,
// and retail also keeps `&ctx` in s0 for the four setup calls (`addiu s0,sp,48`, then `move a0,s0`,
// `addiu a0,s0,32`) where every spelling here re-materialises `sp,48`. Ruled out: a pointer local
// `int *cnt = &list->count;` for the count accesses (no a3 materialisation, 126 differ), separate bufA/bufB
// locals instead of the one struct (no s0 hoist), and `do { *d++ = *s++ } while (--k)` over Pair (MWCC adds
// two `move`s to keep the pre-increment bases). The s0 hoist is the more interesting half: it appears only
// when a stack object's address is live across the setup calls AND later reused for a member address, which
// every source shape tried so far hands back to the allocator as separate `sp,N` immediates.

extern "C" char s_data_common_parameter_AI_Shot_cs_002f5198[];
extern "C" char s_ShotAINo_002f51bc[];
extern "C" char s_ShotSituationLimit_002f51c8[];
extern "C" char s_ShotNetRank_002f51dc[];
extern "C" char s_ShotAllRank_002f51e8[];
extern "C" char s_ShotBaseRank_002f51f4[];
extern "C" char s_ShotFrequency_002f5204[];
extern "C" char DAT_002f4a64;
extern "C" char DAT_003070bc;

struct Tag {
  char c;
};

extern "C" void FUN_0008b198(void *, int, Tag);
extern "C" void FUN_000649c0(void *);
extern "C" void FUN_00064a08(void *, int);
extern "C" void FUN_0008c230(void *);
extern "C" void FUN_00066338(void *, int);
extern "C" int FUN_000651b8(void *, char *, int, int, void *);
extern "C" int FUN_000650e0(void *);
extern "C" int FUN_00065554(void *, int, char *);
extern "C" void FUN_002370b0(void *, void *, Tag);

struct Pair {
  short lo;
  short hi;
};

struct Shot {
  Pair p[3];
};

struct List {
  Shot *data;
  int count;
  int cap;
};

struct Loader {
  void *key[4];
  char bufA[16];
  char bufB[16];
};

extern "C" void FUN_00235da4(List *tables)
{
  Loader ctx;
  Shot shot;
  List *list;
  Shot *elem;
  unsigned int u;
  int i;
  int n;

  for (u = 0; u < 3; u++)
    FUN_0008b198(&tables[u], tables[u].count, Tag());

  FUN_000649c0(&ctx);
  ctx.key[0] = &DAT_003070bc;
  FUN_0008c230(&ctx.bufA);
  FUN_0008c230(&ctx.bufB);

  if (FUN_000651b8(&ctx, s_data_common_parameter_AI_Shot_cs_002f5198, 0, 1, &DAT_002f4a64) != 0) {
    n = FUN_000650e0(&ctx);
    for (i = 1; i < n; i++) {
      shot.p[0].lo =  FUN_00065554(&ctx, i, s_ShotAINo_002f51bc);
      shot.p[0].hi =  FUN_00065554(&ctx, i, s_ShotSituationLimit_002f51c8);
      shot.p[2].lo =  FUN_00065554(&ctx, i, s_ShotNetRank_002f51dc);
      shot.p[1].lo =  FUN_00065554(&ctx, i, s_ShotAllRank_002f51e8);
      shot.p[1].hi =  FUN_00065554(&ctx, i, s_ShotBaseRank_002f51f4);
      shot.p[2].hi =  FUN_00065554(&ctx, i, s_ShotFrequency_002f5204);
      list = &tables[shot.p[0].lo / 100];
      if ((unsigned int)list->count < (unsigned int)list->cap) {
        elem = list->data + list->count;
        if (elem != 0)
          *elem = shot;
        list->count = list->count + 1;
      } else {
        FUN_002370b0(list, &shot, Tag());
      }
    }
  }

  ctx.key[0] = &DAT_003070bc;
  FUN_00066338(&ctx.bufB, 0);
  FUN_00066338(&ctx.bufA, 0);
  FUN_00064a08(&ctx, 0);
}
// near miss from lane fm7 (unreviewed)
