/* HSTMATCH module=hstp_trans_main.prx start=0x0028dae4 end=0x0028dc10 symbol=FUN_0028dae4 lang=c99 */
/* Clone of src/eboot/pick_weighted_entry_0027c774.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Picks a random slot among the table entries whose key equals the key of entry `sel` (each weighted 100), starting from the entry itself. Matching idiom: the result is a separate local `sel` initialised from the parameter (using the parameter itself shifts the entry offset into the callee-saved copy); `total += weights[n]` reads the just-stored weight back. */
typedef struct Item {
    char pad0[0x30];
    int key;
    char pad34[8];
    int count;
} Item;

extern Item *DAT_003f3b14;
extern int FUN_0001342c(void);

int FUN_0028dae4(int param_1, int param_2)
{
    int sel = param_2;
    int target = DAT_003f3b14[sel].key;
    int count = DAT_003f3b14[sel].count;
    int indices[128] = {0};
    int weights[128] = {0};
    int total = 0;
    int n = 0;
    int i;
    int r;
    int j;

    for (i = 0; i < 128; i++) {
        if (target == DAT_003f3b14[i].key) {
            indices[n] = i;
            weights[n] = 100;
            total += weights[n];
            n++;
        }
    }
    if (total < 1)
        return -1;
    r = FUN_0001342c() % total;
    for (j = 0; j < count; j++) {
        if (r < weights[j]) {
            sel = indices[j];
            break;
        }
        r -= weights[j];
    }
    return sel;
}
