/* HSTMATCH module=EBOOT.BIN start=0x0021f0f8 end=0x0021f1f4 symbol=FUN_0021f0f8 lang=c99 */
typedef struct {
    unsigned char pad0[0x5c];
    int head;
    int items[2];
    unsigned char pad1[0x10];
    int v17;
    int v18;
    unsigned char b70;
    unsigned char pad2[3];
} Self;
extern char DAT_00309724[];
extern char DAT_002f0920[];
extern float DAT_002eff88;
extern void *DAT_002f08e4[];
extern int DAT_002f0904[];
extern void FUN_00102e38(void);
extern void FUN_00104118(void *, char *, int);
extern void FUN_00103540(float, void *);
extern int FUN_001039d8(void *, void *, int);
extern int FUN_001026b8(int, int);
extern void FUN_0021f2d4(Self *);

Self *FUN_0021f0f8(Self *self)
{
    int i;

    FUN_00102e38();
    self->head = (int)DAT_00309724;
    FUN_00104118(self, DAT_002f0920, 0);
    FUN_00103540(DAT_002eff88, self);
    *(int *)((char *)self + 0x64) = FUN_001039d8(self, DAT_002f08e4[0], 0);
    for (i = 0; i < 2; i++) {
        int *entry = DAT_002f0904 + i * 3;
        int child = FUN_001026b8(*(int *)((char *)self + entry[0] * 4 + 0x64), entry[1]);

        self->items[i] = child;
        entry[2] = *(int *)(child + 0x24);
    }
    self->v17 = -1;
    self->b70 = 0;
    self->v18 = -1;
    FUN_0021f2d4(self);
    return self;
}
// Near miss: the 0x64/0x68/0x70 member offsets were lifted from pseudocode only; the head store and
// the item loop base fold differently from retail (same pattern as 0x0022060c).
// near miss from lane ds8 (unreviewed)
