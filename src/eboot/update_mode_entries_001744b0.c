/* HSTMATCH module=EBOOT.BIN start=0x001744b0 end=0x00174634 symbol=FUN_001744b0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char u8;

extern int FUN_0017947c(void *self, int a, int b);
extern int FUN_001bb8b8(int id, int ctx);
extern void FUN_0017d590(int obj, int *arr, int zero1, int zero2);
extern int FUN_00179560(void *self, int mode);
extern void FUN_0018629c(int f174, int mode, int f5cc, int f5d0, int f5d8, int one, int res1, int res2);

#define ENTRY_NONE 0x7fffffff /* "no value" marker in the result array */
#define MODE_ENTRY_COUNT 5

/* Per-mode entry (20 bytes); only three of its words are read. */
struct Entry {
    int unk0;   /* 0x00 */
    int unk4;   /* 0x04 */
    int pad;
    int unkc;   /* 0x0c */
    int pad2;
};

struct Obj {
    char pad0[0x174];
    int unk174;               /* 0x174 */
    int unk178;               /* 0x178 */
    char pad1[0x3dc];
    int (*fn)(void);          /* 0x558 returns the context handed to the lookups */
    char pad2[0x42];
    short selected[4];        /* 0x59e chosen value per mode, mirrors arr[1], arr[3], arr[4] */
    char pad3[0x12];
    int mode;                 /* 0x5b8 */
    char pad4[0x10];
    struct Entry entries[MODE_ENTRY_COUNT]; /* 0x5cc indexed by mode */
    char pad5[8];
    u8 flags[3];              /* 0x638 force the lookup for modes 0, 2 and 3 */
};

/* Builds the six-value array for the current mode (entry lookups, optionally overridden by the flags), applies it and refreshes the mode. */
void FUN_001744b0(struct Obj *self) {
    int arr[6];
    arr[0] = ENTRY_NONE;
    arr[1] = ENTRY_NONE;
    arr[2] = ENTRY_NONE;
    arr[3] = ENTRY_NONE;
    arr[4] = ENTRY_NONE;
    arr[5] = ENTRY_NONE;

    int ctx = self->fn();
    short *shorts = self->selected;
    int res1 = FUN_0017947c(self, self->entries[self->mode].unk0, self->entries[self->mode].unk4);

    switch (self->mode) {
    case 0:
        arr[1] = res1;
        shorts[0] = (short)res1;
        break;
    case 2:
        arr[3] = res1;
        shorts[2] = (short)res1;
        break;
    case 3:
        arr[4] = res1;
        shorts[3] = (short)res1;
        break;
    }

    if (self->flags[0] != 0) {
        int v = FUN_001bb8b8(1, ctx);
        arr[1] = v;
        shorts[0] = (short)v;
    }
    if (self->flags[1] != 0) {
        int v = FUN_001bb8b8(3, ctx);
        arr[3] = v;
        shorts[2] = (short)v;
    }
    if (self->flags[2] != 0) {
        int v = FUN_001bb8b8(4, ctx);
        arr[4] = v;
        shorts[3] = (short)v;
    }

    FUN_0017d590(self->unk178, arr, 0, 0);
    int res2 = FUN_00179560(self, self->mode);
    FUN_0018629c(self->unk174, self->mode, self->entries[self->mode].unk0, self->entries[self->mode].unk4, self->entries[self->mode].unkc, 1, res1, res2);
}
