/* HSTMATCH module=EBOOT.BIN start=0x00131b54 end=0x00131cf8 symbol=FUN_00131b54 lang=c99 rodata=0x002c15e4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Cfg { char pad[0x1364]; unsigned unk1364; } Cfg;
struct Inner { char pad[0x67]; unsigned char unk67; };
typedef struct Slot { char pad[0x154]; struct Inner *unk154; } Slot;
typedef struct Game { char pad[0x70]; Slot *slots[2]; } Game;
typedef struct Cur { char pad[0x198]; int current_slot; } Cur;
/* Object tested by kinds 9, 10 and 14. */
typedef struct Obj {
    char pad0[0x44];
    float unk44;
    char pad1[0xf2 - 0x48];
    unsigned char unkf2;
    char pad2;
    unsigned unkf4;
} Obj;
extern int DAT_00338b44;
extern Cfg *DAT_003402a0;
extern Cur *DAT_00338ac4;
extern Game *DAT_003386b0;
extern unsigned char DAT_003386b8;

extern int FUN_000de268(int, int);
extern int FUN_000de208(int, int);
extern int FUN_000de298(int, int);
extern int FUN_0022bfcc(int, unsigned, int);
extern int FUN_000def0c(int);
extern unsigned char FUN_002b79e8(void);

/* Evaluates condition number `kind` (0 to 14) against the object and arg; unlisted kinds return 1. */
unsigned char FUN_00131b54(Obj *obj, unsigned kind, int arg)
{
    unsigned char ret = 1;
    switch (kind) {
    case 0:
        ret = 1;
        break;
    case 1:
        ret = FUN_000de268(DAT_00338b44, -1);
        break;
    case 2:
        ret = FUN_000de208(DAT_00338b44, -1);
        break;
    case 3:
        ret = FUN_000de298(DAT_00338b44, -1);
        break;
    case 4:
        ret = !(arg & (1 << DAT_003402a0->unk1364));
        break;
    case 5:
        ret = FUN_0022bfcc(7, arg - 1, 0);
        break;
    case 6: {
        int i = DAT_00338ac4 ? DAT_00338ac4->current_slot : 0;
        ret = arg <= DAT_003386b0->slots[i]->unk154->unk67;
        break;
    }
    case 7:
        ret = !FUN_000def0c(DAT_00338b44);
        break;
    case 8: {
        int b = DAT_003386b8 != 0;
        if (!b) {
            b = (FUN_002b79e8() & 8) != 0;
        }
        ret = b ^ 1;
        break;
    }
    case 9: {
        int r = 1;
        if (obj->unk44 >= 90.0f) {
        } else {
            r = 0;
        }
        ret = r;
        break;
    }
    case 10:
    case 14:
        ret = obj->unkf2 != 0 && obj->unkf4 == arg;
        break;
    }
    return ret;
}
