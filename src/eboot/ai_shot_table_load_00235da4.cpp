/* HSTMATCH module=EBOOT.BIN start=0x00235da4 end=0x00235fe0 symbol=FUN_00235da4 lang=c++ data=0x002f5198 */
/* LoadAiShotTable: data/common/parameter/AI_Shot.csv; see docs/DATA-TABLES.md Data: its string literals (7 strings, 0x002f5198-0x002f5212) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag fm7 near miss, wip/ai_shot_table_load_00235da4.cpp) corrected by hand: string symbols renamed to DAT_ names; count incremented through an int & local (gives the hoisted addiu a3,a0,4); ctx address taken through a pointer reference (matching idiom: `Loader *lp0 = &ctx; Loader *&lp = lp0;` keeps lp live in s0 so the bufB address is s0+32); readability pass; exact match verified; names and types await human review. */

extern "C" char DAT_002f4a64;
extern "C" char DAT_003070bc;

/* Empty marker argument passed by value to the container helpers. */
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

enum { TABLE_COUNT = 3, AI_NOS_PER_TABLE = 100 };

struct Pair {
  short lo;
  short hi;
};

/* One CSV row as three short pairs (copied as an array): [0] ShotAINo / ShotSituationLimit,
   [1] ShotAllRank / ShotBaseRank, [2] ShotNetRank / ShotFrequency. */
struct Shot {
  Pair p[3];
};

/* Vector of rows (data, count, capacity). */
struct List {
  Shot *data;
  int count;
  int cap;
};

/* Local CSV reader object: vtable pointer, then two 16-byte sub-objects. */
struct Loader {
  void *vtable;
  char pad04[12];
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

  for (u = 0; u < TABLE_COUNT; u++)
    FUN_0008b198(&tables[u], tables[u].count, Tag());

  Loader *lp0 = &ctx;
  Loader *&lp = lp0;
  FUN_000649c0(lp);
  ctx.vtable = &DAT_003070bc;
  FUN_0008c230(&ctx.bufA);
  FUN_0008c230(&lp->bufB);

  if (FUN_000651b8(lp, "data/common/parameter/AI_Shot.csv", 0, 1, &DAT_002f4a64) != 0) {
    n = FUN_000650e0(lp);
    /* row 0 is the header; each row goes to table ai_no / 100 */
    for (i = 1; i < n; i++) {
      shot.p[0].lo =  FUN_00065554(&ctx, i, "ShotAINo");
      shot.p[0].hi =  FUN_00065554(&ctx, i, "ShotSituationLimit");
      shot.p[2].lo =  FUN_00065554(&ctx, i, "ShotNetRank");
      shot.p[1].lo =  FUN_00065554(&ctx, i, "ShotAllRank");
      shot.p[1].hi =  FUN_00065554(&ctx, i, "ShotBaseRank");
      shot.p[2].hi =  FUN_00065554(&ctx, i, "ShotFrequency");
      list = &tables[shot.p[0].lo / AI_NOS_PER_TABLE];
      int &c = list->count;
      if ((unsigned int)list->count < (unsigned int)list->cap) {
        elem = list->data + list->count;
        if (elem != 0)
          *elem = shot;
        c = c + 1;
      } else {
        FUN_002370b0(list, &shot, Tag());
      }
    }
  }

  ctx.vtable = &DAT_003070bc;
  FUN_00066338(&ctx.bufB, 0);
  FUN_00066338(&ctx.bufA, 0);
  FUN_00064a08(&ctx, 0);
}
