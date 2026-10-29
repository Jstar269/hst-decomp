/* HSTMATCH module=EBOOT.BIN start=0x001e1ed8 end=0x001e1fb0 symbol=FUN_001e1ed8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/result_layout.h"

enum { MEMBER_PANES = 5, MEMBER_ITEMS = 8, MEMBER_REFS = 22, MEMBER_PANE_ANIMS = 4 };

struct ResultMembers {
    char pad[0x1d68];
    void *layout;                          /* 0x1d68 */
    ModeNode *panes[MEMBER_PANES];         /* 0x1d6c */
    LayoutItem items[MEMBER_ITEMS];        /* 0x1d80 */
    LayoutRef refs[MEMBER_REFS];           /* 0x1e20 */
    Animator layout_anim;                  /* 0x1f28 */
    Animator pane_anim[MEMBER_PANE_ANIMS]; /* 0x1fb4 */
};

extern "C" char DAT_002ebe48[];
extern "C" char *DAT_002ebc1c[];
extern "C" LayoutEnt DAT_002c7db8[];
extern "C" LayoutEnt DAT_002c7ec0[];

extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" void FUN_00216e90(ModeNode **, void *, char **, int);
extern "C" void FUN_00216f14(LayoutItem *, ModeNode **, LayoutEnt *, int);
extern "C" void FUN_002170ec(LayoutRef *, ModeNode **, LayoutEnt *, int);
extern "C" void FUN_00217778(Animator *, void *);
extern "C" void FUN_00217704(Animator *, ModeNode *);

/* Set up the member layout: load it, look up panes, items and refs, then start the layout and per-pane animators. */
extern "C" void FUN_001e1ed8(ResultMembers *o) {
    FUN_00104118(o->layout, DAT_002ebe48, 0);
    FUN_00103540(o->layout, 2900.0f);
    FUN_001037c8(o->layout, -256);
    FUN_00216e90(o->panes, o->layout, DAT_002ebc1c, MEMBER_PANES);
    FUN_00216f14(o->items, o->panes, DAT_002c7db8, MEMBER_ITEMS);
    FUN_002170ec(o->refs, o->panes, DAT_002c7ec0, MEMBER_REFS);
    FUN_00217778(&o->layout_anim, o->layout);
    FUN_00217704(&o->pane_anim[0], o->panes[0]);
    FUN_00217704(&o->pane_anim[1], o->panes[1]);
    FUN_00217704(&o->pane_anim[2], o->panes[2]);
    FUN_00217704(&o->pane_anim[3], o->panes[3]);
}
