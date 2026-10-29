/* HSTMATCH module=EBOOT.BIN start=0x00283660 end=0x00283874 symbol=FUN_00283660 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: recovered loop order and slot initialization branches; readability pass; exact match verified; names and types await human review. */

#include "hst/types.h"
#include "hst/adhoc_net.h"

#define SLOT_COUNT 4
#define SLOT_ID_COUNT 4
#define SLOTS_OFFSET 0x940 /* offset of the slot table inside the owner */

/* 0x458-byte slot state; the objects named unkNN are reset by helper calls (their extents run up to the next field). */
typedef struct SlotState {
  int ids[SLOT_ID_COUNT];   /* 0x000 reset to -1 */
  int unk10;                /* 0x010 reset to -1 */
  u8 unk14;                 /* 0x014 */
  char pad15[3];
  char unk18[0x28];         /* 0x018 */
  char unk40[0xcc];         /* 0x040 */
  u8 unk10c;                /* 0x10c */
  char pad10d[0x12d - 0x10d];
  u8 inUse;                 /* 0x12d zero: the slot may be set up; set to 1 afterwards */
  char pad12e[0x144 - 0x12e];
  u32 unk144;               /* 0x144 */
  char unk148[0x10];        /* 0x148 */
  char unk158[8];           /* 0x158 */
  char unk160[0xcc];        /* 0x160 */
  u8 unk22c;                /* 0x22c */
  char pad22d[0x280 - 0x22d];
  char unk280[0xcc];        /* 0x280 */
  u8 unk34c;                /* 0x34c */
  char pad34d[0x458 - 0x34d];
} SlotState;                /* size 0x458 */

typedef struct SlotOwner {
  char pad000[0x615];
  u8 unk615;                /* 0x615 */
  char pad616[0x62c - 0x616];
  u32 unk62c;               /* 0x62c */
  char pad630[SLOTS_OFFSET - 0x630];
  SlotState slot[SLOT_COUNT]; /* 0x940 */
} SlotOwner;

/* View of the owner that starts at the slot origin minus the table offset: stepping it by the slot size keeps
   the slot fields at their full offsets (the form that compiles to retail). */
typedef struct SlotView {
  char pad000[SLOTS_OFFSET];
  SlotState s;
} SlotView;

extern AdhocNet * DAT_00338ac4;
extern char * DAT_003415a8;
extern void FUN_000133f4(u32);
extern u32 FUN_0001342c(void);
extern void * FUN_0008d0cc(void *, void *);
extern void * FUN_0008d0e4(void *, void *);
extern void FUN_0008d114(void *);
extern void FUN_0008d2ec(void *);
extern int FUN_000bd378(void *, void *, int);
extern int FUN_000bd480(void *, int, void *, int);
extern u32 FUN_002b78f8(void);

/* Resets a slot to its start-up state and seeds its random word. */
#define RESET_SLOT(pv) \
    u32 k = 0; \
    int *q = (int *)(pv); /* walks the id words; the table offset is added at each store */ \
    do { \
        k++; \
        *(q + SLOTS_OFFSET / sizeof(int)) = -1; \
        q++; \
    } while (k < SLOT_ID_COUNT); \
    (pv)->s.unk10 = -1; \
    (pv)->s.unk14 = 0; \
    FUN_0008d114((pv)->s.unk18); \
    FUN_0008d2ec((pv)->s.unk40); \
    (pv)->s.unk10c = 0; \
    FUN_0008d2ec((pv)->s.unk160); \
    FUN_0008d2ec((pv)->s.unk280); \
    (pv)->s.unk22c = 0; \
    (pv)->s.unk34c = 0; \
    FUN_0008d0e4((pv)->s.unk148, DAT_003415a8 + 4); \
    FUN_0008d0cc((pv)->s.unk158, DAT_003415a8 + 0x18); \
    (pv)->s.inUse = 1; \
    FUN_000133f4(FUN_002b78f8()); \
    (pv)->s.unk144 = FUN_0001342c()

/* For each of the four slots that the adhoc table marks present and that is not in use yet, loads it (own slot
   or remote slot) and, on success, resets it. */
void FUN_00283660(SlotOwner *self)
{
    int i = 0;
    int off = 0;
    SlotView *p = (SlotView *)self;

    do {
        if ((*(u8 *)((char *)DAT_00338ac4 + off + 0x5e) != 0) && (p->s.inUse == 0)) {
            if (i == DAT_00338ac4->unk198) {
                if ((u8)FUN_000bd378(DAT_00338ac4, &p->s, sizeof(SlotState))) {
                    RESET_SLOT(p);
                    self->unk615 = 1;
                    FUN_000133f4(FUN_002b78f8());
                    self->unk62c = FUN_0001342c();
                }
            } else {
                if ((u8)FUN_000bd480(DAT_00338ac4, i, &p->s, sizeof(SlotState))) {
                    RESET_SLOT(p);
                }
            }
        }
        i++;
        off += 7;
        p = (SlotView *)((char *)p + sizeof(SlotState));
    } while (i < SLOT_COUNT);
}
