/* HSTMATCH module=EBOOT.BIN start=0x0022060c end=0x00220704 symbol=FUN_0022060c lang=c99 */
extern char DAT_003096c4[];
extern float DAT_002eff88;
extern void FUN_00102e38(void);
extern void FUN_00104118(void *, char *, int);
extern void FUN_00103540(void *, float);
extern int FUN_001039d8(void *, char *, int);
extern int FUN_001026b8(int, int);
extern void FUN_00220b4c(int *);

struct ItemEntry {
    int index;
    int arg;
    int value;
};

struct ItemTable {
    char *name;
    int pad[5];
    struct ItemEntry items[2];
};

extern struct ItemTable DAT_002f0b8c;

int *FUN_0022060c(int *self)
{
    int i;

    FUN_00102e38();
    self[0] = (int)DAT_003096c4;
    FUN_00104118(self, DAT_002f0b8c.name, 0);
    FUN_00103540(self, DAT_002eff88);
    self[0x1b] = FUN_001039d8(self, DAT_002f0b8c.name, 0);
    for (i = 0; i < 2; i++) {
        struct ItemEntry *e = &DAT_002f0b8c.items[i];
        int child = FUN_001026b8(self[e->index + 0x1b], e->arg);

        self[i + 0x1c] = child;
        e->value = *(int *)(child + 0x24);
    }
    self[0x17] = 0;
    self[0x18] = 0;
    self[0x19] = -1;
    self[0x1a] = 0x3f800000;
    FUN_00220b4c(self);
    return self;
}
// near miss from lane ds9 (unreviewed)
