/* HSTMATCH module=EBOOT.BIN start=0x002215b8 end=0x002216c4 symbol=FUN_002215b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00102e38(void *self);
extern void FUN_00104118(void *self, char *name, int flag);
extern void FUN_00103540(void *self, float value);
extern void *FUN_001039d8(void *self, void *src, int flag);
extern void *FUN_001026b8(void *model, char *name);
extern void FUN_002217b8(void *self);
extern char DAT_00309684[];
extern char DAT_002f0d9c[];
extern float DAT_002eff88;
extern char *DAT_002f0d5c[];
struct Entry_002215b8 { int idx; char *name; int result; };
extern struct Entry_002215b8 DAT_002f0d70[];

char *FUN_002215b8(char *self)
{
    FUN_00102e38(self);
    *(void **)self = &DAT_00309684;
    FUN_00104118(self, DAT_002f0d9c, 0);
    FUN_00103540(self, DAT_002eff88);
    int i = 0;
    char **src = DAT_002f0d5c;
    int off = 0;
    do {
        *(void **)(self + off + 0x60) = FUN_001039d8(self, *src, 0);
        i++;
        src++;
        off += 4;
    } while (i < 2);
    int j = 0;
    struct Entry_002215b8 *e = DAT_002f0d70;
    off = 0;
    do {
        int *h = (int *)FUN_001026b8(*(void **)(self + e->idx * 4 + 0x60), e->name);
        *(void **)(self + off + 0x68) = h;
        e->result = h[9];
        j++;
        off += 4;
        e++;
    } while (j < 3);
    *(int *)(self + 0x5c) = -1;
    *(char *)(self + 0x74) = 0;
    FUN_002217b8(self);
    return self;
}
