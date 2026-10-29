/* HSTMATCH module=hstp_trans_main.prx start=0x001efe64 end=0x001eff94 symbol=FUN_001efe64 lang=c99 data=0x00393c84 */
/* Clone of src/eboot/init_result_status_001e1c40.c (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00393c84-0x00393cf1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern void FUN_002262f8(void *dst, char *name, int n);
extern void FUN_00109a44(void *layout, char *path, int flag);
extern void FUN_00108e6c(void *layout, float value);
extern void FUN_001090f4(void *layout, int mode);
extern void FUN_00225e94(ModeNode **out, void *layout, char **names, int count);
extern void FUN_00225f18(LayoutItem *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_00225fb4(LayoutRef *out, ModeNode **panes, LayoutEnt *ents, int count);
extern void FUN_002260f0(LayoutRef *out, ModeNode **panes, LayoutEnt *ents, int count);
extern LayoutEnt *DAT_003f3468;
extern char *DAT_00393ac4[];
extern LayoutEnt DAT_002d773c[];
extern LayoutEnt DAT_002d77c0[];

/* Load the unit list and the status layout, look up its panes, units and refs, and record each pane's x position. */
void FUN_001efe64(ResultStatus *self)
{
    FUN_002262f8(&DAT_003f3468, "data/menu/result/result_status/result_status_unitlist.txt", STATUS_UNITS);
    FUN_00109a44(self->layout, "data/menu/result/result_status/result_status.lay", 0);
    FUN_00108e6c(self->layout, 2900.0f);
    FUN_001090f4(self->layout, -256);
    FUN_00225e94(self->panes, self->layout, DAT_00393ac4, STATUS_PANES);
    FUN_00225f18(self->units, self->panes, DAT_003f3468, STATUS_UNITS);
    FUN_00225fb4(self->refs_a, self->panes, DAT_002d773c, STATUS_REFS_A);
    FUN_002260f0(self->refs_b, self->panes, DAT_002d77c0, STATUS_REFS_B);
    for (int i = 0; i < STATUS_PANES; i++)
        self->pane_x[i] = (int)self->panes[i]->x;
}
