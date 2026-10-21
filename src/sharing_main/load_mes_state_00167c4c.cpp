/* HSTMATCH module=hstp_trans_main.prx start=0x00167c4c end=0x00167f00 symbol=FUN_00167c4c lang=c++ rodata=0x002d2134 */
/* Clone of src/eboot/load_mes_state_0015b6a4.cpp (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: `if (flag != 0) { else-call } else { switch }` puts the else call first like retail, member-array delete loop indexed as self->arr[i] (self-based walker with displacement), delete on a virtual-destructor pointee for the null-check chain, rodata=0x2d2134 is the 12-entry jump table; names and types await human review. */
struct VC {
    virtual ~VC();
};
struct Self {
    char pad0[8];
    int f8;
    char pad1[0x18 - 0xc];
    int f18;
    unsigned char b1c;
    char pad2[0x24 - 0x1d];
    VC *m24;
    VC *m28;
    int m2c;
    int m30;
    VC *arr[3];
};
extern char DAT_00385810[];
extern int DAT_003e9744;
extern "C" {
void FUN_00000020(void *);
void FUN_00000028();
void FUN_00166888(Self *, int);
void FUN_00167f00(Self *, int);
void FUN_00168028(Self *, int);
void FUN_00168204(Self *, int);
void FUN_0016841c(Self *, int, int);
void FUN_00168620(Self *, int);
void FUN_00168748(Self *, int);
void FUN_00168870(Self *, int, int);
void FUN_00168a88(Self *, int);
void FUN_00168dfc(Self *, int);
void FUN_0016916c(int, int *, int *);
void FUN_0016972c(Self *, int);
}

extern "C" void FUN_00167c4c(Self *self, int a, int flag, int d)
{
    FUN_00000020(DAT_00385810);
    DAT_003e9744 = a;
    if (self->m24 != 0) {
        delete self->m24;
        self->m24 = 0;
    }
    if (self->m28 != 0) {
        delete self->m28;
        self->m28 = 0;
    }
    int i = 0;
    do {
        if (self->arr[i] != 0) {
            delete self->arr[i];
            self->arr[i] = 0;
        }
        i++;
    } while (i < 3);
    self->m2c = 0;
    self->m30 = 0;
    int kind = 0;
    int v = 0;
    FUN_0016916c(a, &kind, &v);
    if (flag != 0) {
        FUN_00168a88(self, a);
    } else {
        switch (kind) {
        case 0:
            FUN_00167f00(self, v);
            break;
        case 1:
            FUN_00168204(self, v);
            break;
        case 2:
            FUN_0016841c(self, v, 0);
            break;
        case 3:
            FUN_00168620(self, v);
            break;
        case 4:
            FUN_00168748(self, v);
            break;
        case 6:
            FUN_00168870(self, v, d);
            break;
        case 7:
            FUN_00168dfc(self, v);
            break;
        case 10:
            FUN_00168028(self, v);
            break;
        case 11:
            FUN_0016841c(self, v, 1);
            break;
        }
    }
    if (kind == 6 || (flag != 0 && a == 1) || (kind == 7 && v == 7)) {
        FUN_00166888(self, 2);
        self->f18 = 0;
        self->b1c = 1;
        self->f8 = 0x5a;
    } else {
        FUN_00166888(self, 2);
        self->f18 = 0;
        self->b1c = 0;
        self->f8 = 1;
    }
    if (flag == 0 && d != 0) {
        FUN_0016972c(self, a);
    }
    FUN_00000028();
}
