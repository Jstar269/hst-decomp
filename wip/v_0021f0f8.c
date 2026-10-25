/* HSTMATCH module=EBOOT.BIN start=0x0021f0f8 end=0x0021f1f4 symbol=FUN_0021f0f8 lang=c99 */
typedef struct {
    unsigned char pad0[0x5c];
    int f5c;
    int f60;
    int head;
    int items[2];
    unsigned char b70;
} Self;
extern char DAT_00309724[];
extern char DAT_002f0920[];
extern float DAT_002eff88;
extern void *DAT_002f08e4[];
extern int DAT_002f0904[];
extern void FUN_00102e38(void);
extern void FUN_00104118(void *, char *, int);
extern void FUN_00103540(void *, float);
extern int FUN_001039d8(void *, void *, int);
extern int FUN_001026b8(int, int);
extern void FUN_0021f2d4(Self *);

Self *FUN_0021f0f8(Self *self)
{
    int i;

    FUN_00102e38();
    *(int *)self = (int)DAT_00309724;
    FUN_00104118(self, DAT_002f0920, 0);
    FUN_00103540(self, 10.0f + DAT_002eff88);
    self->head = FUN_001039d8(self, DAT_002f08e4[0], 0);
    for (i = 0; i < 2; i++) {
        int *e = DAT_002f0904 + i * 3;
        int child = FUN_001026b8(*(int *)((char *)self + e[0] * 4 + 0x64), e[1]);

        *(int *)((unsigned int)self + i * 4 + 0x68) = child;
        e[2] = *(int *)(child + 0x24);
    }
    self->f5c = -1;
    self->b70 = 0;
    self->f60 = -1;
    FUN_0021f2d4(self);
    return self;
}
// near miss from lane ds9 (unreviewed)
