/* HSTMATCH module=hstp_trans_main.prx start=0x000c893c end=0x000c8a98 symbol=FUN_000c893c lang=c99 */
/* Hand-written reconstruction (port of src/eboot/slot_scan_update_000c4eb8.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/online_game.h"

#define SLOT_MAX 4          /* slots tracked by the manager */
#define SLOT_COUNT_SHORT 2  /* slots scanned while the first config byte is clear */
#define SLOT_COUNT_FULL 4

typedef struct SlotEnt { char pad[6]; unsigned char on; } SlotEnt;   /* 7 bytes */
typedef struct SlotMgr { char pad0[0x58]; SlotEnt ent[SLOT_MAX]; char pad1[0x178 - 0x58 - 28]; unsigned char flag178; char pad2[0x198 - 0x179]; int cur; } SlotMgr;
typedef struct SlotCfg { unsigned char first; char pad1[0xdf]; unsigned char flag; char pad2[3]; char x[0x120 - 0xe4]; } SlotCfg;  /* 0x120 bytes */

extern SlotMgr *DAT_003e1e04;
extern SlotCfg DAT_003eaaf0[];
extern int FUN_0029754c(void *);
extern void FUN_00297a1c(void *, int, int, void *);
extern void FUN_000be5d8(SlotMgr *);
extern void FUN_000be53c(SlotMgr *, SlotEnt *);
extern void FUN_000c0bf4(SlotMgr *, int);
extern int FUN_000c0e5c(SlotMgr *, int);
extern int FUN_000c0e74(SlotMgr *, int);

/* Per-frame scan of the slots: selects the entry that is on, or sets up the idle ones; bumps the frame counter. */
void FUN_000c893c(OnlineGame *self)
{
    if (DAT_003e1e04 != 0) {
        int current;
        int count;
        int index;
        if (FUN_0029754c(self->link) == 0)
            return;
        FUN_000be5d8(DAT_003e1e04);
        current = DAT_003e1e04->cur;
        if (DAT_003eaaf0[0].first == 0) {
            count = SLOT_COUNT_SHORT;
        } else {
            count = SLOT_COUNT_FULL;
        }
        for (index = 0; index < count; index++) {
            SlotMgr *mgr = DAT_003e1e04;
            if (mgr->ent[index].on != 0) {
                if (index != current)
                    FUN_000c0bf4(mgr, index);
            } else if (DAT_003eaaf0[index].flag == 0) {
                int argA = FUN_000c0e5c(mgr, index);
                int argB = FUN_000c0e74(mgr, index);
                FUN_00297a1c(self->link, argA, argB, DAT_003eaaf0[index].x);
                if (DAT_003e1e04->flag178 != 0)
                    FUN_000be53c(DAT_003e1e04, &DAT_003e1e04->ent[index]);
            }
        }
    }
    self->frame = self->frame + 1;
}
