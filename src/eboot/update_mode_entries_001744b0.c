/* HSTMATCH module=EBOOT.BIN start=0x001744b0 end=0x00174634 symbol=FUN_001744b0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char u8;

extern int FUN_0017947c(void *self, int a, int b);
extern int FUN_001bb8b8(int id, int ctx);
extern void FUN_0017d590(int obj, int *arr, int zero1, int zero2);
extern int FUN_00179560(void *self, int mode);
extern void FUN_0018629c(int f174, int mode, int f5cc, int f5d0, int f5d8, int one, int res1, int res2);

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

void FUN_001744b0(struct Obj *self) {
    int arr[6];
    arr[0] = 0x7fffffff;
    arr[1] = 0x7fffffff;
    arr[2] = 0x7fffffff;
    arr[3] = 0x7fffffff;
    arr[4] = 0x7fffffff;
    arr[5] = 0x7fffffff;

    int ctx = self->fn();
    short *shorts = self->shorts;
    int res1 = FUN_0017947c(self, self->entries[self->mode].f5cc, self->entries[self->mode].f5d0);

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

    FUN_0017d590(self->f178, arr, 0, 0);
    int res2 = FUN_00179560(self, self->mode);
    FUN_0018629c(self->f174, self->mode, self->entries[self->mode].f5cc, self->entries[self->mode].f5d0, self->entries[self->mode].f5d8, 1, res1, res2);
}
