/* HSTMATCH module=hstp_trans_main.prx start=0x001808f4 end=0x00180a78 symbol=FUN_001808f4 lang=c99 */
/* Clone of src/eboot/update_mode_entries_001744b0.c (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char u8;

extern int FUN_00185b70(void *self, int a, int b);
extern int FUN_001c96a0(int id, int ctx);
extern void FUN_00189c84(int obj, int *arr, int zero1, int zero2);
extern int FUN_00185c54(void *self, int mode);
extern void FUN_001929e8(int f174, int mode, int f5cc, int f5d0, int f5d8, int one, int res1, int res2);

struct Entry {
    int f5cc;
    int f5d0;
    int pad;
    int f5d8;
    int pad2;
};

struct Obj {
    char pad0[372];
    int f174;
    int f178;
    char pad1[988];
    int (*fn)(void);
    char pad2[66];
    short shorts[4];
    char pad3[18];
    int mode;
    char pad4[16];
    struct Entry entries[5];
    char pad5[8];
    u8 flags[3];
};

void FUN_001808f4(struct Obj *self) {
    int arr[6];
    arr[0] = 0x7fffffff;
    arr[1] = 0x7fffffff;
    arr[2] = 0x7fffffff;
    arr[3] = 0x7fffffff;
    arr[4] = 0x7fffffff;
    arr[5] = 0x7fffffff;

    int ctx = self->fn();
    short *shorts = self->shorts;
    int res1 = FUN_00185b70(self, self->entries[self->mode].f5cc, self->entries[self->mode].f5d0);

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
        int v = FUN_001c96a0(1, ctx);
        arr[1] = v;
        shorts[0] = (short)v;
    }
    if (self->flags[1] != 0) {
        int v = FUN_001c96a0(3, ctx);
        arr[3] = v;
        shorts[2] = (short)v;
    }
    if (self->flags[2] != 0) {
        int v = FUN_001c96a0(4, ctx);
        arr[4] = v;
        shorts[3] = (short)v;
    }

    FUN_00189c84(self->f178, arr, 0, 0);
    int res2 = FUN_00185c54(self, self->mode);
    FUN_001929e8(self->f174, self->mode, self->entries[self->mode].f5cc, self->entries[self->mode].f5d0, self->entries[self->mode].f5d8, 1, res1, res2);
}
