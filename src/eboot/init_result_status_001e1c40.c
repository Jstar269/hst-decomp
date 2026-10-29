/* HSTMATCH module=EBOOT.BIN start=0x001e1c40 end=0x001e1d70 symbol=FUN_001e1c40 lang=c99 data=0x002ebd78 */
/* ResultStatus_LoadUnitList: result_status_unitlist.txt; see docs/DATA-TABLES.md Data: its string literals (2 strings, 0x002ebd78-0x002ebde5) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/result_layout.h"

enum { STATUS_PANES = 5, STATUS_UNITS = 123, STATUS_REFS_A = 4, STATUS_REFS_B = 60 };

typedef struct ResultStatus {
    char pad[0x9b4];
    void *layout;                          /* 0x9b4 */
    ModeNode *panes[STATUS_PANES];         /* 0x9b8 */
    LayoutItem units[STATUS_UNITS];        /* 0x9cc */
    LayoutRef refs_a[STATUS_REFS_A];       /* 0x1368 */
    LayoutRef refs_b[STATUS_REFS_B];       /* 0x1398 */
    char pad1668[0x1748 - 0x1668];
    int pane_x[STATUS_PANES];              /* 0x1748 */
} ResultStatus;

extern void FUN_002172f4(void *dst, char *name, int n);
extern void FUN_00104118(void *layout, char *path, int flag);
extern void FUN_00103540(void *layout, float value);
extern void FUN_001037c8(void *layout, int mode);
extern void FUN_00216e90(ModeNode **out, void *layout, char **names, int count);
extern void FUN_00216f14(LayoutItem *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_00216fb0(LayoutRef *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_002170ec(LayoutRef *out, ModeNode **panes, LayoutEnt *ents, int count);
extern LayoutEnt *DAT_0034a130;
extern char *DAT_002ebbb8[];
extern LayoutEnt DAT_002c72fc[];
extern LayoutEnt DAT_002c7380[];

/* Load the unit list and the status layout, look up its panes, units and refs, and record each pane's x position. */
void FUN_001e1c40(ResultStatus *self)
{
    FUN_002172f4(&DAT_0034a130, "data/menu/result/result_status/result_status_unitlist.txt", STATUS_UNITS);
    FUN_00104118(self->layout, "data/menu/result/result_status/result_status.lay", 0);
    FUN_00103540(self->layout, 2900.0f);
    FUN_001037c8(self->layout, -256);
    FUN_00216e90(self->panes, self->layout, DAT_002ebbb8, STATUS_PANES);
    FUN_00216f14(self->units, self->panes, DAT_0034a130, STATUS_UNITS);
    FUN_00216fb0(self->refs_a, self->panes, DAT_002c72fc, STATUS_REFS_A);
    FUN_002170ec(self->refs_b, self->panes, DAT_002c7380, STATUS_REFS_B);
    for (int i = 0; i < STATUS_PANES; i++)
        self->pane_x[i] = (int)self->panes[i]->x;
}
