/* HSTMATCH module=EBOOT.BIN start=0x001e185c end=0x001e1964 symbol=FUN_001e185c lang=c99 data=0x002ebcc4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ebcc4-0x002ebcf3) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/result_layout.h"

enum { OVERALL_ITEMS = 5 };

typedef struct ResultOverall {
    char pad[0xd4];
    void *layout;                      /* 0xd4 */
    ModeNode *panes[1];                /* 0xd8 */
    LayoutItem items[OVERALL_ITEMS];   /* 0xdc */
    int item_left[OVERALL_ITEMS];      /* 0x140 */
    int item_right[OVERALL_ITEMS];     /* 0x154 */
    Animator anim;                     /* 0x168 */
} ResultOverall;

extern void FUN_00104118(void *layout, char *path, int flag);
extern void FUN_00103540(void *layout, float value);
extern void FUN_001037c8(void *layout, int mode);
extern void FUN_00216e90(ModeNode **out, void *layout, char **names, int count);
extern void FUN_00216f14(LayoutItem *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_00217778(Animator *anim, void *layout);
extern char *DAT_002ebb44[];
extern LayoutEnt DAT_002c6fc0[];

/* Set up the overall-result layout: load it, look up the panes and items, and cache each item's left/right edges. */
void FUN_001e185c(ResultOverall *self)
{
    FUN_00104118(self->layout, "data/menu/result/result_main/result_sougou.lay", 0);
    FUN_00103540(self->layout, 2900.0f);
    FUN_001037c8(self->layout, -256);
    FUN_00216e90(self->panes, self->layout, DAT_002ebb44, 1);
    FUN_00216f14(self->items, self->panes, DAT_002c6fc0, OVERALL_ITEMS);
    for (int i = 0; i < OVERALL_ITEMS; i++) {
        self->item_left[i] = self->items[i].quad->left;
        self->item_right[i] = self->items[i].quad->right;
    }
    FUN_00217778(&self->anim, self->layout);
}
