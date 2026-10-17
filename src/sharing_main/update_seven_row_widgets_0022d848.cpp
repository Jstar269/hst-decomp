/* HSTMATCH module=hstp_trans_main.prx start=0x0022d848 end=0x0022da40 symbol=FUN_0022d848 lang=c++ */
/* Clone of src/eboot/update_seven_row_widgets_0021e2d4.cpp (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0c/FUN_0022d848.c (tag: a1) */
struct VC {
    virtual void d0();
    virtual void m(int);
};

struct Sub16c {
    char pad[0x68];
    int cur;
    int pad6c;
    VC *slots[3];
};

struct Widget {
    char pad[0x24];
    int v24;
    int v28;
};

struct Row24 {
    Widget *w60;
    Widget *w64;
    char pad[0x10];
};

struct Self {
    char pad54[0x54];
    VC *vc54[3];
    Row24 rows[3];
    char pada8[0x16c - 0xa8];
    Sub16c *sub16c;
    char pad170[0x1c8 - 0x170];
    int mode;
    int val;
    int pad1d0;
    float f1d4;
};

extern "C" {
extern int DAT_00398a60[];
extern void FUN_00105470(Widget *, int);

void FUN_0022d848(Self *param_1, int param_2)
{
    Self *iVar6;
    int iVar5;
    int iVar10;
    Self *iVar9;
    int *puVar7;
    int iVar8;

    param_1->mode = param_2;
    Sub16c *sub = param_1->sub16c;
    sub->cur = param_2;
    iVar9 = 0;
    puVar7 = (int *)sub;
    do {
        ((VC *)puVar7[0x1c])->m(1);
        iVar9 = (Self *)((int)iVar9 + 1);
        puVar7++;
    } while ((int)iVar9 < 3);
    sub->slots[sub->cur]->m(0);
    iVar5 = 0;
    iVar6 = param_1;
    do {
        iVar6->vc54[0]->m(iVar5 != param_1->mode);
        if (iVar5 == param_1->mode) {
            iVar8 = param_1->val - 1;
            if (iVar8 != -1) {
                param_1->val = iVar8 + 1;
            }
            iVar10 = 0;
            iVar9 = param_1;
            puVar7 = DAT_00398a60;
            do {
                if (iVar8 == -1) {
                    FUN_00105470(iVar9->rows[0].w60, 1);
                    int v = 10 + puVar7[5];
                    Widget *w = iVar9->rows[0].w64;
                    w->v24 = v;
                    w->v28 = v;
                } else {
                    int bVar4 = param_1->val < 10;
                    if (bVar4 == 0) {
                        bVar4 = iVar10 != param_1->mode;
                    }
                    FUN_00105470(iVar9->rows[0].w60, bVar4);
                    int v = param_1->val / 10 + puVar7[2];
                    Widget *w = iVar9->rows[0].w60;
                    w->v24 = v;
                    w->v28 = v;
                    v = param_1->val % 10 + puVar7[5];
                    w = iVar9->rows[0].w64;
                    w->v24 = v;
                    w->v28 = v;
                }
                iVar10++;
                iVar9 = (Self *)((char *)iVar9 + 0x18);
                puVar7 += 0x12;
            } while (iVar10 < 3);
        }
        iVar5++;
        iVar6 = (Self *)((char *)iVar6 + 4);
    } while (iVar5 < 3);
    param_1->f1d4 = (param_1->mode == 2) ? 84.0f : 95.0f;
}
}
