/* HSTMATCH module=hstp_trans_main.prx start=0x002b6dac end=0x002b70fc symbol=FUN_002b6dac lang=c++ */
/* Clone of src/eboot/format_panel_text_002a761c.cpp (hstclone.py tag c180307): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: real panel/record struct layouts instead of global offsets, real call signatures (0x20f5c takes only the float and overwrites a0 itself), the 38-row text-pointer pass, and the `rec = f(base = ...)` assignment-in-argument spelling that fixes the base/record register colouring; exact match verified; names and types await human review. */

struct Entry_002b6dac {
    char pad_000[0x24];
    int f24;
    int f28;
    char pad_02c[0xf8 - 0x2c];
    char *text;
    char pad_0fc[0x138 - 0xfc];
    int flag;
};

struct Rec_002b6dac {
    char v000[0x18];
    char s18[0x18];
    float f30;
    int v34;
    int v38;
    char s3c[0x4c];
    int v88;
    int v8c;
    int v90;
    int v94;
    int v98;
    int v9c;
    float fA0;
    float fA4;
    int vA8;
    int vAC;
};

struct Panel_002b6dac {
    char pad_000[0x1d0];
    Entry_002b6dac *p1d0;
    Entry_002b6dac *p1d4;
    char pad_1d8[0x1f8 - 0x1d8];
    Entry_002b6dac *p1f8;
    Entry_002b6dac *p1fc;
    char pad_200[0x270 - 0x200];
    Entry_002b6dac *p270;
    char pad_274[0x290 - 0x274];
    Entry_002b6dac *arr[38];
    char pad_328[0x361 - 0x328];
    char text[38][0x80];
    char pad_1661[0x1668 - 0x1661];
    int n1668;
    int n166c;
};

extern "C" {
extern char *DAT_003ea8e8;
extern int DAT_003aaa7c;
extern int DAT_003aaa88;
extern int DAT_003aabe4;
extern char DAT_003aa0d4[];
int FUN_002beb30(void *);
void *FUN_002beb38(void *, int);
char *FUN_0020d1e0(int, int, int);
void FUN_000143b0(char *, char *, ...);
char *FUN_000149a8(char *, char *);
int FUN_002beb28(Rec_002b6dac *);
long long FUN_00020f84(float);
void FUN_002b497c(char *, char *, char *);
void FUN_00105470(Entry_002b6dac *, int);
void FUN_00113a50(Entry_002b6dac *);
}

extern "C" void FUN_002b6dac(Panel_002b6dac *p)
{
    Entry_002b6dac *e;
    char *base;
    Entry_002b6dac *a2e;
    Rec_002b6dac *rec;
    int a;
    int b;
    int m;
    long long v;
    int i;

    if (FUN_002beb30(DAT_003ea8e8 + 0x87128) < 1) {
        return;
    }
    rec = (Rec_002b6dac *)FUN_002beb38(base = DAT_003ea8e8 + 0x87128, p->n1668 + p->n166c);

    FUN_000143b0(p->text[24], FUN_0020d1e0(0x13, 0xd, 2), rec->v88, rec->v8c);
    FUN_000143b0(p->text[25], FUN_0020d1e0(0x13, 0xd, 3), rec->v90);
    FUN_000143b0(p->text[26], FUN_0020d1e0(0x13, 0xd, 2), rec->v94, rec->v98);
    FUN_000149a8(p->text[27], FUN_0020d1e0(0xe, 1, rec->v9c));
    FUN_000143b0(p->text[28], FUN_0020d1e0(0x13, 0xd, 0), (int)(rec->fA0 * 100.0f));
    FUN_000143b0(p->text[29], FUN_0020d1e0(0x13, 0xd, 0), (int)(rec->fA4 * 100.0f));

    b = rec->vAC;
    a = rec->vA8;
    m = b % 10;

    FUN_000149a8(p->text[30], FUN_0020d1e0(0xc, 0, a));
    FUN_000149a8(p->text[31], FUN_0020d1e0(0xd, 1, b));

    i = DAT_003aaa7c + a;
    a2e = p->p1f8;
    a2e->f24 = i;
    a2e->f28 = i;

    if (b != 0 && b != 500) {
        FUN_00105470(p->p1fc, 0);
        i = (DAT_003aaa88 + 2) - m;
        a2e = p->p1fc;
        a2e->f24 = i;
        a2e->f28 = i;
    } else {
        FUN_00105470(p->p1fc, 1);
    }

    FUN_000149a8(p->text[32], rec->s18);
    float f = rec->f30;
    int n = FUN_002beb28(rec);
    v = FUN_00020f84(f);
    FUN_000143b0(p->text[33], DAT_003aa0d4, (int)v, (int)(v >> 32));

    i = DAT_003aabe4 + n;
    a2e = p->p270;
    a2e->f24 = i;
    a2e->f28 = i;

    FUN_000143b0(p->text[34], FUN_0020d1e0(0x13, 0xd, 1), rec->v34);
    FUN_000143b0(p->text[35], FUN_0020d1e0(0x13, 0xd, 1), rec->v38);

    FUN_002b497c(rec->s3c, p->text[36], p->text[37]);

    FUN_00105470(p->p1d0, (p->n1668 + p->n166c) == 0);
    FUN_00105470(p->p1d4, (p->n1668 + p->n166c) == FUN_002beb30(base) - 1);

    for (int k = 0; k < 38; k++) {
        e = p->arr[k];
        e->text = p->text[k];
        e->flag = 1;
        FUN_00113a50(e);
    }
}
