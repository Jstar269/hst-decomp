/* HSTMATCH module=EBOOT.BIN start=0x001e1d70 end=0x001e1e24 symbol=FUN_001e1d70 lang=c99 data=0x002ebde8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ebde8-0x002ebe18) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/result_layout.h"

enum { PHASE_ITEMS = 6 };

typedef struct ResultPhase {
    char pad[0x810];
    void *layout;                  /* 0x810 */
    ModeNode *panes[1];            /* 0x814 */
    LayoutItem items[PHASE_ITEMS]; /* 0x818 */
    LayoutRef refs[1];             /* 0x890 */
    Animator layout_anim;          /* 0x89c */
    Animator item_anim;            /* 0x928 */
} ResultPhase;

extern void FUN_00104118(void *layout, char *path, int flag);
extern void FUN_00103540(void *layout, float value);
extern void FUN_001037c8(void *layout, int mode);
extern void FUN_00216e90(ModeNode **out, void *layout, char **names, int count);
extern void FUN_00216f14(LayoutItem *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_00216fb0(LayoutRef *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_00217778(Animator *anim, void *layout);
extern void FUN_00217614(Animator *anim, void *quad);

extern char *DAT_002ebbd4[];
extern LayoutEnt DAT_002c7b3c[];
extern LayoutEnt DAT_002c7c04[];

/* Set up the phase layout: load it, look up its panes, items and refs, and start the two animators. */
void FUN_001e1d70(ResultPhase *self)
{
    FUN_00104118(self->layout, "data/menu/result/result_phase/phaselayouter.lay", 0);
    FUN_00103540(self->layout, 2900.0f);
    FUN_001037c8(self->layout, -256);
    FUN_00216e90(self->panes, self->layout, DAT_002ebbd4, 1);
    FUN_00216f14(self->items, self->panes, DAT_002c7b3c, PHASE_ITEMS);
    FUN_00216fb0(self->refs, self->panes, DAT_002c7c04, 1);
    FUN_00217778(&self->layout_anim, self->layout);
    FUN_00217614(&self->item_anim, self->items[0].quad);
}
