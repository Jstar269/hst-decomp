/* HSTMATCH module=EBOOT.BIN start=0x001e1e24 end=0x001e1ed8 symbol=FUN_001e1e24 lang=c99 data=0x002ebe18 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ebe18-0x002ebe46) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/result_layout.h"

enum { RANK_ITEMS = 9, RANK_REFS = 3 };

typedef struct ResultRank {
    char pad[0x175c];
    void *layout;                 /* 0x175c */
    ModeNode *panes[1];           /* 0x1760 */
    LayoutItem items[RANK_ITEMS]; /* 0x1764 */
    LayoutRef refs[RANK_REFS];    /* 0x1818 */
    Animator layout_anim;         /* 0x183c */
    Animator item_anim;           /* 0x18c8 */
} ResultRank;

extern void FUN_00104118(void *layout, char *path, int flag);
extern void FUN_00103540(void *layout, float value);
extern void FUN_001037c8(void *layout, int mode);
extern void FUN_00216e90(ModeNode **out, void *layout, char **names, int count);
extern void FUN_00216f14(LayoutItem *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_002170ec(LayoutRef *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_00217778(Animator *anim, void *layout);
extern void FUN_00217614(Animator *anim, void *quad);

extern char *DAT_002ebbe0[];
extern LayoutEnt DAT_002c7c28[];
extern LayoutEnt DAT_002c7d54[];

/* Set up the rank layout: load it, look up its panes, items and refs, and start the two animators. */
void FUN_001e1e24(ResultRank *self)
{
    FUN_00104118(self->layout, "data/menu/result/result_rank/ranklayouter.lay", 0);
    FUN_00103540(self->layout, 2900.0f);
    FUN_001037c8(self->layout, -256);
    FUN_00216e90(self->panes, self->layout, DAT_002ebbe0, 1);
    FUN_00216f14(self->items, self->panes, DAT_002c7c28, RANK_ITEMS);
    FUN_002170ec(self->refs, self->panes, DAT_002c7d54, RANK_REFS);
    FUN_00217778(&self->layout_anim, self->layout);
    FUN_00217614(&self->item_anim, self->items[2].quad);
}
