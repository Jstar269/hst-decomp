/* HSTMATCH module=EBOOT.BIN start=0x0022060c end=0x00220704 symbol=FUN_0022060c lang=c99 */
extern char DAT_003096c4[];
extern char DAT_002f0bc4[];
extern float DAT_002eff88;
extern int DAT_002f0ba4[];
extern void FUN_00102e38(void);
extern void FUN_00104118(void *, char *, int);
extern void FUN_00103540(void *, float);
extern int FUN_001039d8(void *, char *, int);
extern int FUN_001026b8(int, int);
extern void FUN_00220b4c(int *);

int *FUN_0022060c(int *self)
{
    int i;

    FUN_00102e38();
    self[0] = (int)DAT_003096c4;
    FUN_00104118(self, DAT_002f0bc4, 0);
    FUN_00103540(self, DAT_002eff88);
    self[0x1b] = FUN_001039d8(self, ((char **)DAT_002f0ba4)[-6], 0);
    for (i = 0; i < 2; i++) {
        int *e = DAT_002f0ba4 + i * 3;
        int child = FUN_001026b8(self[e[0] + 0x1b], e[1]);

        *(int *)((unsigned int)self + i * 4 + 0x70) = child;
        e[2] = *(int *)(child + 0x24);
    }
    self[0x17] = 0;
    self[0x18] = 0;
    self[0x19] = -1;
    self[0x1a] = 0x3f800000;
    FUN_00220b4c(self);
    return self;
}

// near miss from lane ds9 (unreviewed)
