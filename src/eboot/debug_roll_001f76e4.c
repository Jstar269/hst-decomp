/* HSTMATCH module=EBOOT.BIN start=0x001f76e4 end=0x001f780c symbol=FUN_001f76e4 lang=c99 helpers=FUN_001ef3f8@0x001ef3f8-0x001ef424 */
/* Hand-written reconstruction from the disassembly (near miss wip/debug_roll_001f76e4.c, completed with its same-file static helper FUN_001ef3f8 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
#define SLOT_COUNT 128
#define ROLL_RANGE 10000  /* the roll is compared with the probability in 1/10000 units */

typedef struct Slot {
    int unk0;
    int unk4;
    int val;      /* summed over all slots */
    int unkc;
    int unk10;
} Slot;

extern unsigned int DAT_00310fc8;
extern char DAT_002eeb80[];
extern char DAT_002eeb90[];
extern char DAT_002eeba8[];
extern int FUN_001f7584(int, int, int);

static void FUN_001ef3f8(...)
{
}

/* Sums the slot values, logs the resulting probability (percent with two decimals), rolls the random generator against it and returns 1 on success. */
int FUN_001f76e4(int unused, Slot *slots, int arg3, int arg4)
{
    int result = 0;
    int total = 0;
    int i;
    for (i = 0; i < SLOT_COUNT; i++) {
        total += slots[i].val;
    }
    FUN_001ef3f8(DAT_002eeb80, total);
    int prob = FUN_001f7584(total, arg3, arg4);
    FUN_001ef3f8(DAT_002eeb90, prob / 100, prob % 100);
    DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3; /* linear congruential step */
    int rv = (int)((DAT_00310fc8 >> 16) & 0x7fff) % ROLL_RANGE;
    FUN_001ef3f8(DAT_002eeba8, rv);
    if (rv < prob) {
        result = 1;
    }
    return result;
}
