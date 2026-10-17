/* HSTMATCH module=EBOOT.BIN start=0x001f14a4 end=0x001f15d0 symbol=FUN_001f14a4 lang=c99 */
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

extern Node *DAT_003415ac;
extern void *DAT_003415d4;

extern void FUN_001905b8(void *, int);
extern int FUN_00190724(void *);
extern void FUN_001e1614(int);
extern void FUN_001f3770(BigObj *);
extern void FUN_001f474c(BigObj *, int);
extern void FUN_001f47a4(BigObj *);
extern void FUN_001f4bfc(BigObj *);
extern void FUN_001ff668(void);

void FUN_001f14a4(BigObj *param_1)
{
    Node *node;
    Node *node2;

    if (param_1->f_44 == 0) {
        param_1->f_816c = 1;
        FUN_001f474c(param_1, 0);
        FUN_001ff668();
        FUN_001e1614(param_1->f_510);
        node = DAT_003415ac;
        if (node != 0) {
            (*node->inner)->f_60 = 304.0f;
            (*node->inner)->f_64 = 136.0f;
        }
        FUN_001905b8(DAT_003415d4, 3);
        FUN_001ff668();
    }

    switch (param_1->f_816c) {
    case 1:
        if (FUN_00190724(DAT_003415d4) != 0) {
            node = DAT_003415ac;
            if (node != 0) {
                node->f_74 = 1.0f;
                node->f_78 = 1.0f;
                node2 = DAT_003415ac;
                (*node2->inner)->f_60 = 240.0f;
                (*node2->inner)->f_64 = 136.0f;
            }
            FUN_001f3770(param_1);
        }
        break;
    }

    FUN_001f4bfc(param_1);
    FUN_001f47a4(param_1);
}
