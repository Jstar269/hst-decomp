/* HSTMATCH module=hstp_trans_main.prx start=0x0013d10c end=0x0013d2b0 symbol=FUN_0013d10c lang=c99 rodata=0x002d19c4 */
/* Hand-written reconstruction (port of src/eboot/switch_flags_00131b54.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
typedef struct Cfg { char pad[0x1364]; unsigned f1364; } Cfg;
struct Inner { char pad[0x67]; unsigned char f67; };
typedef struct Slot { char pad[0x154]; struct Inner *f154; } Slot;
typedef struct Game { char pad[0x70]; Slot *slots[2]; } Game;
typedef struct Cur { char pad[0x198]; int f198; } Cur;
typedef struct Obj {
    char pad0[0x44];
    float f44;
    char pad1[0xf2 - 0x48];
    unsigned char f0f2;
    char pad2;
    unsigned f0f4;
} Obj;
extern int DAT_003e1e84;
extern Cfg *DAT_003e95e0;
extern Cur *DAT_003e1e04;
extern Game *DAT_003e19f0;
extern unsigned char DAT_003e19f8;

extern int FUN_000e2454(int, int);
extern int FUN_000e23f4(int, int);
extern int FUN_000e2484(int, int);
extern int FUN_0023ba3c(int, unsigned, int);
extern int FUN_000e30f8(int);
extern unsigned char FUN_002c7788(void);

unsigned char FUN_0013d10c(Obj *o, unsigned kind, int arg)
{
    unsigned char ret = 1;
    switch (kind) {
    case 0:
        ret = 1;
        break;
    case 1:
        ret = FUN_000e2454(DAT_003e1e84, -1);
        break;
    case 2:
        ret = FUN_000e23f4(DAT_003e1e84, -1);
        break;
    case 3:
        ret = FUN_000e2484(DAT_003e1e84, -1);
        break;
    case 4:
        ret = !(arg & (1 << DAT_003e95e0->f1364));
        break;
    case 5:
        ret = FUN_0023ba3c(7, arg - 1, 0);
        break;
    case 6: {
        int i = DAT_003e1e04 ? DAT_003e1e04->f198 : 0;
        ret = arg <= DAT_003e19f0->slots[i]->f154->f67;
        break;
    }
    case 7:
        ret = !FUN_000e30f8(DAT_003e1e84);
        break;
    case 8: {
        int b = DAT_003e19f8 != 0;
        if (!b) {
            b = (FUN_002c7788() & 8) != 0;
        }
        ret = b ^ 1;
        break;
    }
    case 9: {
        int r = 1;
        if (o->f44 >= 90.0f) {
        } else {
            r = 0;
        }
        ret = r;
        break;
    }
    case 10:
    case 14:
        ret = o->f0f2 != 0 && o->f0f4 == arg;
        break;
    }
    return ret;
}
