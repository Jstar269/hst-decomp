/* HSTMATCH module=EBOOT.BIN start=0x000c4eb8 end=0x000c5014 symbol=FUN_000c4eb8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: typed 7-byte entry array and 0x120-byte table, for-loop with signed bound and index declared first, int-returning callees, early return before the counter bump; readability pass; exact match verified; names and types await human review. */
#include "hst/online_game.h"

#define SLOT_MAX 4          /* slots tracked by the manager */
#define SLOT_COUNT_SHORT 2  /* slots scanned while the first config byte is clear */
#define SLOT_COUNT_FULL 4

typedef struct SlotEnt { char pad[6]; unsigned char on; } SlotEnt;   /* 7 bytes */
typedef struct SlotMgr { char pad0[0x58]; SlotEnt ent[SLOT_MAX]; char pad1[0x178 - 0x58 - 28]; unsigned char flag178; char pad2[0x198 - 0x179]; int cur; } SlotMgr;
typedef struct SlotCfg { unsigned char first; char pad1[0xdf]; unsigned char flag; char pad2[3]; char x[0x120 - 0xe4]; } SlotCfg;  /* 0x120 bytes */

extern SlotMgr *DAT_00338ac4;
extern SlotCfg DAT_003417b8[];
extern int FUN_00285f3c(void *);
extern void FUN_0028637c(void *, int, int, void *);
extern void FUN_000bb190(SlotMgr *);
extern void FUN_000bb0f4(SlotMgr *, SlotEnt *);
extern void FUN_000bd6a4(SlotMgr *, int);
extern int FUN_000bd8e0(SlotMgr *, int);
extern int FUN_000bd8f8(SlotMgr *, int);

/* Per-frame scan of the slots: selects the entry that is on, or sets up the idle ones; bumps the frame counter. */
void FUN_000c4eb8(OnlineGame *self)
{
    if (DAT_00338ac4 != 0) {
        int current;
        int count;
        int index;
        if (FUN_00285f3c(self->link) == 0)
            return;
        FUN_000bb190(DAT_00338ac4);
        current = DAT_00338ac4->cur;
        if (DAT_003417b8[0].first == 0) {
            count = SLOT_COUNT_SHORT;
        } else {
            count = SLOT_COUNT_FULL;
        }
        for (index = 0; index < count; index++) {
            SlotMgr *mgr = DAT_00338ac4;
            if (mgr->ent[index].on != 0) {
                if (index != current)
                    FUN_000bd6a4(mgr, index);
            } else if (DAT_003417b8[index].flag == 0) {
                int argA = FUN_000bd8e0(mgr, index);
                int argB = FUN_000bd8f8(mgr, index);
                FUN_0028637c(self->link, argA, argB, DAT_003417b8[index].x);
                if (DAT_00338ac4->flag178 != 0)
                    FUN_000bb0f4(DAT_00338ac4, &DAT_00338ac4->ent[index]);
            }
        }
    }
    self->frame = self->frame + 1;
}
