/* HSTMATCH module=hstp_trans_main.prx start=0x001ff8a8 end=0x001ff9d4 symbol=FUN_001ff8a8 lang=c99 */
/* Clone of src/eboot/hud_state_update_001f14a4.c (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: typed high-offset struct access, single-case switch dispatch, and helper call arguments; exact match verified; names and types await human review. */

typedef struct Inner Inner;
typedef struct Node Node;
typedef struct BigObj BigObj;

struct Inner {
    char pad0[0x60];
    float f_60;
    float f_64;
};

struct Node {
    char pad0[4];
    Inner **inner;
    char pad8[0x74 - 8];
    float f_74;
    float f_78;
};

struct BigObj {
    char pad0[0x44];
    int f_44;
    char pad48[0x510 - 0x48];
    int f_510;
    char pad514[0x816c - 0x514];
    int f_816c;
};

extern Node *DAT_003ea8ec;
extern void *DAT_003ea914;

extern void FUN_0019cdc8(void *, int);
extern int FUN_0019cf34(void *);
extern void FUN_001ef838(int);
extern void FUN_00201c30(BigObj *);
extern void FUN_00202cdc(BigObj *, int);
extern void FUN_00202d34(BigObj *);
extern void FUN_002031c4(BigObj *);
extern void FUN_0020de38(void);

void FUN_001ff8a8(BigObj *param_1)
{
    Node *node;
    Node *node2;

    if (param_1->f_44 == 0) {
        param_1->f_816c = 1;
        FUN_00202cdc(param_1, 0);
        FUN_0020de38();
        FUN_001ef838(param_1->f_510);
        node = DAT_003ea8ec;
        if (node != 0) {
            (*node->inner)->f_60 = 304.0f;
            (*node->inner)->f_64 = 136.0f;
        }
        FUN_0019cdc8(DAT_003ea914, 3);
        FUN_0020de38();
    }

    switch (param_1->f_816c) {
    case 1:
        if (FUN_0019cf34(DAT_003ea914) != 0) {
            node = DAT_003ea8ec;
            if (node != 0) {
                node->f_74 = 1.0f;
                node->f_78 = 1.0f;
                node2 = DAT_003ea8ec;
                (*node2->inner)->f_60 = 240.0f;
                (*node2->inner)->f_64 = 136.0f;
            }
            FUN_00201c30(param_1);
        }
        break;
    }

    FUN_002031c4(param_1);
    FUN_00202d34(param_1);
}
