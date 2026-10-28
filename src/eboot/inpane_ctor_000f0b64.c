/* HSTMATCH module=EBOOT.BIN start=0x000f0b64 end=0x000f0d84 symbol=FUN_000f0b64 lang=c99 data=0x002d7454 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 3 strings, 0x002d7454-0x002d7480) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
#include "hst/types.h"

typedef struct { short pad[2]; short x, y, x2, y2; } Rect;
extern void FUN_00102e38(void);
extern void FUN_00104118(int, char *, int);
extern void FUN_00103540(int, float);
extern void FUN_001037c8(int, int);
extern int FUN_001039d8(int, char *, int);
extern int FUN_001026b8(int, int);
extern void FUN_000f1090(int);
extern void FUN_000f0d84(int);

extern int DAT_00307894;
extern float DAT_002d6c9c;
extern const float DAT_002d757c;
extern const float DAT_002d7580;
extern char DAT_002d7584[];
char *DAT_002d7474[] = {
    "minipoint",
    "point",
    "regulation",
};
extern int DAT_002d74f8[];

static inline int Width(Rect *r) { return r->x2 - r->x; }
static inline int Height(Rect *r) { return r->y2 - r->y; }
int FUN_000f0b64(int param_1)
{
  int i;
  int j;
  int k;
  char **name;
  int off;
  int obj;
  int *tbl;

  FUN_00102e38();
  *(u32 *)param_1 = (u32)&DAT_00307894;
  FUN_00104118(param_1, (char *)&DAT_002d7584, 0);
  FUN_00103540(param_1, DAT_002d6c9c);
  FUN_001037c8(param_1, 0xffffff05);
  i = 0;
  name = DAT_002d7474;
  off = 0;
  do {
    obj = FUN_001039d8(param_1, *name, 0);
    *(u32 *)(param_1 + off + 0x58) = obj;
    i = i + 1;
    name = name + 1;
    off = off + 4;
  } while (i < 3);
  j = 0;
  tbl = DAT_002d74f8;
  off = 0;
  do {
    obj = FUN_001026b8(*(u32 *)(param_1 + tbl[0] * 4 + 0x58), tbl[1]);
    *(u32 *)(param_1 + off + 0x64) = obj;
    j = j + 1;
    off = off + 4;
    tbl[2] = *(u32 *)(obj + 0x24);
    tbl = tbl + 3;
  } while (j < 0xb);
  for (k = 0; k < 0xb; k++) {
    int w = Width(((Rect *)((int *)param_1)[k + 0x19]));
    int h = Height(((Rect *)((int *)param_1)[k + 0x19]));
    float t, u, v;
    t = (float)((Rect *)((int *)param_1)[k + 0x19])->x;
    ((Rect *)((int *)param_1)[k + 0x19])->x = (short)(int)(t * DAT_002d757c);
    t = (float)((Rect *)((int *)param_1)[k + 0x19])->x;
    ((Rect *)((int *)param_1)[k + 0x19])->x = (short)(int)(t + DAT_002d7580);
    u = (float)w;
    t = (float)((Rect *)((int *)param_1)[k + 0x19])->x;
    ((Rect *)((int *)param_1)[k + 0x19])->x2 = (short)(int)(t + u * DAT_002d757c);
    t = (float)((Rect *)((int *)param_1)[k + 0x19])->y;
    ((Rect *)((int *)param_1)[k + 0x19])->y = (short)(int)(t * DAT_002d757c);
    v = (float)h;
    t = (float)((Rect *)((int *)param_1)[k + 0x19])->y;
    ((Rect *)((int *)param_1)[k + 0x19])->y2 = (short)(int)(t + v * DAT_002d757c);
  }
  FUN_000f1090(param_1);
  FUN_000f0d84(param_1);
  *(u32 *)(param_1 + 0x90) = 0x3f800000;
  *(u8 *)(param_1 + 0x94) = 0;
  *(u32 *)(param_1 + 0x98) = 0;
  *(u32 *)(param_1 + 0x9c) = 0;
  *(u8 *)(param_1 + 0xa0) = 0;
  return param_1;
}

