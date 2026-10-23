/* HSTMATCH module=EBOOT.BIN start=0x001f76e4 end=0x001f780c symbol=FUN_001f76e4 lang=c99 helpers=FUN_001ef3f8@0x001ef3f8-0x001ef424 */
/* Hand-written reconstruction from the disassembly (near miss wip/debug_roll_001f76e4.c, completed with its same-file static helper FUN_001ef3f8 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
typedef struct Slot {
    int f0;
    int f4;
    int val;
    int f12;
    int f16;
} Slot;

extern unsigned int DAT_00310fc8;
extern char DAT_002eeb80[];
extern char DAT_002eeb90[];
extern char DAT_002eeba8[];
extern int FUN_001f7584(int, int, int);

static void FUN_001ef3f8(...)
{
}

int FUN_001f76e4(int param_1, Slot *slots, int param_3, int param_4)
{
    int result = 0;
    int total = 0;
    int i;
    for (i = 0; i < 128; i++) {
        total += slots[i].val;
    }
    FUN_001ef3f8(DAT_002eeb80, total);
    int prob = FUN_001f7584(total, param_3, param_4);
    FUN_001ef3f8(DAT_002eeb90, prob / 100, prob % 100);
    DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
    int rv = (int)((DAT_00310fc8 >> 16) & 0x7fff) % 10000;
    FUN_001ef3f8(DAT_002eeba8, rv);
    if (rv < prob) {
        result = 1;
    }
    return result;
}
