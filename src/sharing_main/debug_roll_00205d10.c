/* HSTMATCH module=hstp_trans_main.prx start=0x00205d10 end=0x00205e38 symbol=FUN_00205d10 lang=c99 helpers=FUN_001fbc18@0x001fbc18-0x001fbc44 */
/* Clone of src/eboot/debug_roll_001f76e4.c (hstclone.py tag a0db26h2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (near miss wip/debug_roll_00205d10.c, completed with its same-file static helper FUN_001fbc18 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
typedef struct Slot {
    int f0;
    int f4;
    int val;
    int f12;
    int f16;
} Slot;

extern unsigned int DAT_003ba2c8;
extern char DAT_00396b90[];
extern char DAT_00396ba0[];
extern char DAT_00396bb8[];
extern int FUN_00205bb0(int, int, int);

static void FUN_001fbc18(...)
{
}

int FUN_00205d10(int param_1, Slot *slots, int param_3, int param_4)
{
    int result = 0;
    int total = 0;
    int i;
    for (i = 0; i < 128; i++) {
        total += slots[i].val;
    }
    FUN_001fbc18(DAT_00396b90, total);
    int prob = FUN_00205bb0(total, param_3, param_4);
    FUN_001fbc18(DAT_00396ba0, prob / 100, prob % 100);
    DAT_003ba2c8 = DAT_003ba2c8 * 0x343fd + 0x269ec3;
    int rv = (int)((DAT_003ba2c8 >> 16) & 0x7fff) % 10000;
    FUN_001fbc18(DAT_00396bb8, rv);
    if (rv < prob) {
        result = 1;
    }
    return result;
}
