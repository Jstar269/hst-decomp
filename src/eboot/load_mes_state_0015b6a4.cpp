/* HSTMATCH module=EBOOT.BIN start=0x0015b6a4 end=0x0015b958 symbol=FUN_0015b6a4 lang=c++ rodata=0x2c1cf8 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: `if (flag != 0) { else-call } else { switch }` puts the else call first like retail, member-array delete loop indexed as self->arr[i] (self-based walker with displacement), delete on a virtual-destructor pointee for the null-check chain, rodata=0x2c1cf8 is the 12-entry jump table; names and types await human review. */
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
extern char DAT_002de254[];
extern int DAT_00340404;
extern "C" {
void FUN_00000020(void *);
void FUN_00000028();
void FUN_0015a2b0(Self *, int);
void FUN_0015b958(Self *, int);
void FUN_0015ba80(Self *, int);
void FUN_0015bc5c(Self *, int);
void FUN_0015be74(Self *, int, int);
void FUN_0015c078(Self *, int);
void FUN_0015c1a0(Self *, int);
void FUN_0015c2c8(Self *, int, int);
void FUN_0015c4e0(Self *, int);
void FUN_0015c854(Self *, int);
void FUN_0015cbc4(int, int *, int *);
void FUN_0015d184(Self *, int);
}

extern "C" void FUN_0015b6a4(Self *self, int a, int flag, int d)
{
    FUN_00000020(DAT_002de254);
    DAT_00340404 = a;
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
    FUN_0015cbc4(a, &kind, &v);
    if (flag != 0) {
        FUN_0015c4e0(self, a);
    } else {
        switch (kind) {
        case 0:
            FUN_0015b958(self, v);
            break;
        case 1:
            FUN_0015bc5c(self, v);
            break;
        case 2:
            FUN_0015be74(self, v, 0);
            break;
        case 3:
            FUN_0015c078(self, v);
            break;
        case 4:
            FUN_0015c1a0(self, v);
            break;
        case 6:
            FUN_0015c2c8(self, v, d);
            break;
        case 7:
            FUN_0015c854(self, v);
            break;
        case 10:
            FUN_0015ba80(self, v);
            break;
        case 11:
            FUN_0015be74(self, v, 1);
            break;
        }
    }
    if (kind == 6 || (flag != 0 && a == 1) || (kind == 7 && v == 7)) {
        FUN_0015a2b0(self, 2);
        self->f18 = 0;
        self->b1c = 1;
        self->f8 = 0x5a;
    } else {
        FUN_0015a2b0(self, 2);
        self->f18 = 0;
        self->b1c = 0;
        self->f8 = 1;
    }
    if (flag == 0 && d != 0) {
        FUN_0015d184(self, a);
    }
    FUN_00000028();
}
