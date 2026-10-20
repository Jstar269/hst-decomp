/* HSTMATCH module=EBOOT.BIN start=0x00250cec end=0x00250f48 symbol=FUN_00250cec lang=c++ */
#pragma opt_strength_reduction off

extern unsigned char DAT_002fbef9;
extern unsigned char DAT_002fbefa;
extern int DAT_002fcbc8;
extern int DAT_002fcbcc;
extern char *DAT_003415a8;
extern int DAT_0034a780;
extern int DAT_0034a784;

struct Entry {
    int val;
};

struct Obj {
    char pad[0x2f8];
    int mode;
    int f2fc;
    int f300;
    char pad2[0x350 - 0x304];
    Entry **entries;
};

extern "C" {
void FUN_002ada80(int);
}

extern "C" void FUN_00250cec(Obj *self, int param_2)
{
    bool bVar1 = true;
    if (self->mode != 4 && self->mode != 6) {
        bVar1 = false;
    }
    if (bVar1) {
        self->f300 = param_2;
        if (param_2 == 0) {
            DAT_0034a784 = 0;
            DAT_002fbefa = 1;
        } else {
            DAT_0034a784 = self->entries[param_2]->val;
            DAT_002fbefa = 0;
        }
    } else {
        self->f2fc = param_2;
        if (param_2 == 0) {
            DAT_0034a780 = 0;
            DAT_002fbef9 = 1;
        } else {
            DAT_0034a780 = self->entries[param_2]->val;
            DAT_002fbef9 = 0;
        }

        int iVar3 = param_2 * 6;
        for (int iVar5 = 0; iVar5 < 5; ++iVar5) {
            for (int iVar4 = 0; iVar4 < 2; ++iVar4) {
                float fVar6 = (float)(signed char)*(char *)(DAT_003415a8 + 0x86c10 + iVar3 + iVar5 + (iVar4 != 0 ? 0x60 : 0));
                if (fVar6 >= 0.0f) {
                    FUN_002ada80((int)fVar6);
                }

                int local_4 = iVar5 - 1;
                const int *p1 = (DAT_002fcbc8 < local_4) ? &local_4 : &DAT_002fcbc8;
                fVar6 = (float)(signed char)*(char *)(DAT_003415a8 + 0x86c10 + iVar3 + *p1 + 0x60);
                if (fVar6 >= 0.0f) {
                    FUN_002ada80((int)fVar6);
                }

                int local_8 = iVar5 - 1;
                const int *p2 = (DAT_002fcbcc < local_8) ? &local_8 : &DAT_002fcbcc;
                fVar6 = (float)(signed char)*(char *)(DAT_003415a8 + 0x86c10 + iVar3 + *p2);
                if (fVar6 >= 0.0f) {
                    FUN_002ada80((int)fVar6);
                }
            }
        }
    }
}
// near miss from lane s10171846g1r1-0 (unreviewed)
