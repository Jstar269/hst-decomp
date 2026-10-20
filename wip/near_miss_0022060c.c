/* HSTMATCH module=EBOOT.BIN start=0x0022060c end=0x00220704 symbol=FUN_0022060c lang=c99 */
extern char DAT_003096c4[];
extern char DAT_002f0bc4[];
extern char DAT_002eff88[];
extern char DAT_002f0b8c[];
extern int DAT_002f0ba4[];
extern void FUN_00102e38(void);
extern void FUN_00104118(void *, char *, int);
extern void FUN_00103540(char *, void *);
extern int FUN_001039d8(void *, char *, int);
extern int FUN_001026b8(int, int);
extern void FUN_00220b4c(int *);

int *FUN_0022060c(int *self)
{
    int i;

    FUN_00102e38();
    self[0] = (int)DAT_003096c4;
    FUN_00104118(self, DAT_002f0bc4, 0);
    FUN_00103540(DAT_002eff88, self);
    self[0x1b] = FUN_001039d8(self, DAT_002f0b8c, 0);
    for (i = 0; i < 2; i++) {
        int *entry = DAT_002f0ba4 + i * 3;
        int child = FUN_001026b8(self[entry[0] + 0x1b], entry[1]);

        self[i + 0x1c] = child;
        entry[2] = *(int *)(child + 0x24);
    }
    self[0x17] = 0;
    self[0x18] = 0;
    self[0x19] = -1;
    self[0x1a] = 0x3f800000;
    FUN_00220b4c(self);
    return self;
}
// Near miss: 60/62 words; the item-store base fold now matches; retail still materializes DAT_002f0b8c with lui+addiu then lw (a one-member struct, a 2-D array and an explicit &slot[0] all compile to lui+lw).
// near miss from lane ds8 (unreviewed)
