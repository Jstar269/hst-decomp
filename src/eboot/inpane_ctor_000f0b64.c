/* HSTMATCH module=EBOOT.BIN start=0x000f0b64 end=0x000f0d84 symbol=FUN_000f0b64 lang=c99 data=0x002d7454 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 3 strings, 0x002d7454-0x002d7480) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
#include "hst/ingame_panes.h"

extern void FUN_00102e38(void);
extern void FUN_00104118(PointPane *, char *, int);
extern void FUN_00103540(PointPane *, float);
extern void FUN_001037c8(PointPane *, int);
extern FadeNode *FUN_001039d8(PointPane *, char *, int);
extern PaneQuad *FUN_001026b8(FadeNode *, char *);
extern void FUN_000f1090(PointPane *);
extern void FUN_000f0d84(PointPane *);

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
extern PaneItemDef DAT_002d74f8[];

static inline int Width(PaneQuad *r) { return r->x1 - r->x0; }
static inline int Height(PaneQuad *r) { return r->y1 - r->y0; }

/* Point pane constructor: loads its three layers and eleven named quad items, then rescales the items. */
PointPane *FUN_000f0b64(PointPane *self)
{
  int i;
  int j;
  int k;
  char **name;
  int off;
  PaneQuad *item;
  PaneItemDef *def;
  char *bytes = (char *)self;

  FUN_00102e38();
  *(u32 *)self = (u32)&DAT_00307894;
  FUN_00104118(self, (char *)&DAT_002d7584, 0);
  FUN_00103540(self, DAT_002d6c9c);
  FUN_001037c8(self, 0xffffff05);
  i = 0;
  name = DAT_002d7474;
  off = 0;
  do {
    FadeNode *layer = FUN_001039d8(self, *name, 0);
    *(FadeNode **)(bytes + off + 0x58) = layer;
    i = i + 1;
    name = name + 1;
    off = off + 4;
  } while (i < POINT_LAYER_COUNT);
  j = 0;
  def = DAT_002d74f8;
  off = 0;
  do {
    item = FUN_001026b8(*(FadeNode **)(bytes + def->layer * 4 + 0x58), def->name);
    *(PaneQuad **)(bytes + off + 0x64) = item;
    j = j + 1;
    off = off + 4;
    def->value = item->value;
    def = def + 1;
  } while (j < POINT_ITEM_COUNT);
  for (k = 0; k < POINT_ITEM_COUNT; k++) {
    int w = Width(self->item[k]);
    int h = Height(self->item[k]);
    float t, u, v;
    t = (float)self->item[k]->x0;
    self->item[k]->x0 = (short)(int)(t * DAT_002d757c);
    t = (float)self->item[k]->x0;
    self->item[k]->x0 = (short)(int)(t + DAT_002d7580);
    u = (float)w;
    t = (float)self->item[k]->x0;
    self->item[k]->x1 = (short)(int)(t + u * DAT_002d757c);
    t = (float)self->item[k]->y0;
    self->item[k]->y0 = (short)(int)(t * DAT_002d757c);
    v = (float)h;
    t = (float)self->item[k]->y0;
    self->item[k]->y1 = (short)(int)(t + v * DAT_002d757c);
  }
  FUN_000f1090(self);
  FUN_000f0d84(self);
  self->scale = 1.0f;
  self->unk94 = 0;
  self->unk98 = 0;
  self->unk9c = 0;
  self->unka0 = 0;
  return self;
}
