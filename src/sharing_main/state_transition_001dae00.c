/* HSTMATCH module=hstp_trans_main.prx start=0x001dae00 end=0x001daeb0 symbol=FUN_001dae00 lang=c99 */
/* Clone of src/eboot/state_transition_001cc6cc.c (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed the three cases in retail test order with a switch; exact match verified; names and types await human review. */

extern int DAT_003f3610;
extern void FUN_001d06dc(void *);
extern void FUN_001dbf68(void *, int, int);
extern void FUN_002351a8(int, int, int);

struct Sub {
    char pad0[4];
    int state;
    char pad1[169];
    char flag_b1;
    char pad2[2];
    int f_b4;
    int f_b8;
    int f_bc;
    int f_c0;
};

struct Obj {
    char pad0[340];
    int f_154;
    char pad1[4];
    struct Sub *sub;
};

void FUN_001dae00(struct Obj *param_1, int param_2)
{
    struct Sub *sub = param_1->sub;
    if (sub->state != 6) {
        sub->f_b4 = sub->state;
    }
    sub->f_b8 = -1;
    sub->f_bc = -1;
    sub->f_c0 = -1;
    sub->flag_b1 = 1;

    int uVar1 = 0;
    switch (param_2) {
    case 12:
    case 13:
    case 14:
        uVar1 = 1;
        break;
    }

    FUN_002351a8(DAT_003f3610, param_2, uVar1);
    FUN_001dbf68(sub, 6, 1);
    FUN_001d06dc(sub);
    param_1->f_154 = -1;
}
