/* HSTMATCH module=EBOOT.BIN start=0x00200f48 end=0x00201114 symbol=FUN_00200f48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct SubObj {
    char pad[0x24];
    int field_0x24;
    int field_0x28;
};

struct Param2Obj {
    short id;
    char pad2[0x20 - 2];
    unsigned short s10;
    char pad22[0x68 - 0x22];
    short s34;
    char pad6a[0x7c - 0x6a];
    unsigned char f7c;
    unsigned char f7d;
};

extern "C" {
extern char *DAT_0034a13c;
extern int FUN_001fea10(int, int, int);
extern void FUN_0010d4a8(void *);
extern int FUN_0016bb98(short, void *);
extern void FUN_000ffb3c(SubObj *, int);

void FUN_00200f48(int param_1, Param2Obj *param_2, int param_3, int param_4) {

    SubObj **p0 = (SubObj **)(param_1 + param_3 * 20 + 48);
    SubObj **p1 = (SubObj **)(param_1 + (param_3 + 1) * 20 + 48);
    SubObj **p2 = (SubObj **)(param_1 + (param_3 + 2) * 20 + 48);
    int iVar3 = *(int *)(DAT_0034a13c + 0x4c);
    param_3 = FUN_001fea10(7, 0, param_2->s10);
    int iVar2 = *(int *)(param_1 + param_4 * 12 + 0x64c);
    *(int *)(iVar2 + 0xf8) = param_3;
    *(int *)(iVar2 + 0x138) = 1;
    FUN_0010d4a8((void *)iVar2);
    
    SubObj *o1 = *p1;
    int off = iVar3 * 3;
    o1->field_0x24 = o1->field_0x28 + *(unsigned char *)(off + (int)param_2 + 0x7d);
    
    int kind = FUN_0016bb98(param_2->id, &param_2->s34);
    switch (kind) {
    case 1:
        (*p2)->field_0x24 = (*p2)->field_0x28;
        break;
    case 2:
        (*p2)->field_0x24 = (*p2)->field_0x28 + 2;
        break;
    case 3:
        (*p2)->field_0x24 = (*p2)->field_0x28 + 1;
        break;
    case 4:
        (*p2)->field_0x24 = (*p2)->field_0x28 + 3;
        break;
    case 5:
        (*p2)->field_0x24 = (*p2)->field_0x28 + 4;
        break;
    default:
        (*p2)->field_0x24 = (*p2)->field_0x28;
        break;
    }
    
    if (param_2->f7c == 2) {
        FUN_000ffb3c(*p0, 0);
    } else {
        FUN_000ffb3c(*p0, 1);
    }

}
}
