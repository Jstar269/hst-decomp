/* HSTMATCH module=hstp_trans_main.prx start=0x001eff94 end=0x001f0048 symbol=FUN_001eff94 lang=c99 data=0x00393cf4 */
/* Hand-written reconstruction from the disassembly (same source as the EBOOT twin src/eboot/subobject_init_001e1d70.c, addresses substituted); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00393cf4-0x00393d24) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern void FUN_00109a44(void *layout, char *path, int flag);
extern void FUN_00108e6c(void *layout, float value);
extern void FUN_001090f4(void *layout, int mode);
extern void FUN_00225e94(ModeNode **out, void *layout, char **names, int count);
extern void FUN_00225f18(LayoutItem *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_00225fb4(LayoutRef *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_00226820(Animator *anim, void *layout);
extern void FUN_002266bc(Animator *anim, void *quad);

extern char *DAT_00393ae0[];
extern LayoutEnt DAT_002d7f7c[];
extern LayoutEnt DAT_002d8044[];

/* Set up the phase layout: load it, look up its panes, items and refs, and start the two animators. */
void FUN_001eff94(ResultPhase *self)
{
    FUN_00109a44(self->layout, "data/menu/result/result_phase/phaselayouter.lay", 0);
    FUN_00108e6c(self->layout, 2900.0f);
    FUN_001090f4(self->layout, -256);
    FUN_00225e94(self->panes, self->layout, DAT_00393ae0, 1);
    FUN_00225f18(self->items, self->panes, DAT_002d7f7c, PHASE_ITEMS);
    FUN_00225fb4(self->refs, self->panes, DAT_002d8044, 1);
    FUN_00226820(&self->layout_anim, self->layout);
    FUN_002266bc(&self->item_anim, self->items[0].quad);
}
