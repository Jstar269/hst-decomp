/* HSTMATCH module=hstp_trans_main.prx start=0x00124214 end=0x001244f0 symbol=FUN_00124214 lang=c++ */
/* Clone of src/eboot/menu_banner_load_00119040.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Banner {
    virtual void v0();
    virtual void v1();
    virtual void Load(char *path, char *name, int a, int b, int c, int d);
    char pad[0x8c - 4];
    void *f8c;
};

struct Names { const char *n[11]; };

struct Screen {
    char pad0[0x3c];
    void *f3c;
    void *f40;
    char pad44[4];
    Banner *banners[27];
    char padb4[0x270 - 0xb4];
    void *icons[2][11];
};

extern "C" {
void FUN_00000020(const char *, ...);
void FUN_00000028(...);
void FUN_0001c684(void *, int, const char *);
void FUN_0001c73c(void *);
int FUN_000143b0(char *, const char *, ...);
Banner *FUN_000577ec(void *);
void FUN_00057ff4(Banner *, int, char *, int, int);
void FUN_000549dc(float, void *, int);
void *FUN_00125b30(void *);
void *FUN_0012668c(void *);
void *FUN_001fc5fc();
void *FUN_00066a84(void *, const char *, int);
void *FUN_00000bcc(unsigned);
}

extern char DAT_003b7ebc;
extern const char DAT_00380c0c[];
extern const char DAT_00380c14[];
extern const char DAT_00380c28[];
extern const char DAT_00380c3c[];
extern const char *DAT_003805c8[];
extern const char *DAT_003808a0[];
extern const char *DAT_00380b0c[];
extern float DAT_00380b80;
extern const Names DAT_00380be0;

inline void *operator new[](unsigned int, void *p) { return p; }

extern "C" void FUN_00124214(Screen *self)
{
    FUN_00000020(DAT_00380c0c);
    char path[128];
    new (path) char[128]();
    char name[128];
    new (name) char[128]();
    FUN_0001c684(&DAT_003b7ebc, 1, DAT_00380c14);
    for (int i = 0; i < 27; i++) {
        Banner *b = (Banner *)FUN_00000bcc(0x1b0);
        if (b)
            b = FUN_000577ec(b);
        self->banners[i] = b;
        FUN_000143b0(name, DAT_00380c28, DAT_003805c8[i]);
        FUN_000143b0(path, DAT_00380c3c, name, DAT_003808a0[i]);
        self->banners[i]->Load(path, name, 0, 0, 0, 0);
        FUN_000143b0(path, DAT_00380c3c, name, DAT_00380b0c[i]);
        FUN_00057ff4(self->banners[i], 0, path, 0, 0);
        if (i != 1 && i != 9)
            FUN_000549dc(DAT_00380b80, self->banners[i]->f8c, 0);
    }
    void *p = FUN_00000bcc(0xac);
    if (p)
        p = FUN_00125b30(p);
    self->f3c = p;
    void *q = FUN_00000bcc(0x10);
    if (q)
        q = FUN_0012668c(q);
    self->f40 = q;
    FUN_0001c73c(&DAT_003b7ebc);
    void *res = FUN_001fc5fc();
    if (res) {
        Names names = DAT_00380be0;
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 11; k++)
                self->icons[j][k] = FUN_00066a84(res, names.n[k], j + 1);
    }
    FUN_00000028();
}
