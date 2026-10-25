/* HSTMATCH module=EBOOT.BIN start=0x0024e30c end=0x0024e6a0 symbol=FUN_0024e30c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Npc {
    char pad0[0x20];
    unsigned short id;
    unsigned short sub;
    char pad24[0x12];
    short x;
    short y;
    char pad3a[0x16];
    short state;
};
struct Spot;
inline void *operator new[](unsigned, void *p) { return p; }
extern "C" {
extern char DAT_002fbf00[];
extern char DAT_002fbf04[];
extern char DAT_002fbf38[];
extern char DAT_002fbf44[];
extern char DAT_002fbf4c[];
extern char DAT_002fbf50[];
extern char DAT_002fbf64[];
extern char DAT_002fbf88[];
extern unsigned DAT_00310fc8;
int FUN_001930a8(void);
Npc *FUN_00192fd0(int);
unsigned char FUN_0022c988(int);
int FUN_0019319c(void);
Spot *FUN_001930c4(int);
int FUN_0022ab44(int, int, int);
void FUN_0019335c(Npc **, Npc **, Spot *);
void FUN_0024e6a0(const char *, ...);
void FUN_0001cfa4(unsigned *, int, int);
}
struct SpotPos {
    char pad[0x36];
    short x;
    short y;
};

extern "C" Npc *FUN_0024e30c(unsigned want)
{
    Npc *chosen[256];
    Npc *pool[256];
    unsigned pairs[512];
    Npc *who[2];
    int count = 0;
    int npool = 0;
    for (int i = 0; i < 256; i++) {
        chosen[i] = 0;
        pool[i] = 0;
    }
    int n = FUN_001930a8();
    for (int i = 0; i < n; i++) {
        Npc *p = FUN_00192fd0(i);
        if (p) {
            int st = p->state;
            unsigned char ok = 0;
            if (st >= 0) {
                if (st == 0) {
                    pool[npool++] = p;
                } else if (st < 11) {
                    ok = FUN_0022c988(st - 1);
                } else if (st == 99) {
                    ok = 1;
                }
            }
            if (ok) {
                chosen[count] = p;
                pairs[count * 2] = p->id;
                pairs[count * 2 + 1] = p->id;
                count++;
            }
        }
    }
    int m = FUN_0019319c();
    for (int i = 0; i < m; i++) {
        Spot *s = FUN_001930c4(i);
        if (s && FUN_0022ab44(((SpotPos *)s)->x, ((SpotPos *)s)->y, 0) >= 4) {
            new (who) char[8]();
            FUN_0019335c(&who[0], &who[1], s);
            for (int j = 0; j < npool; j++) {
                if ((who[0] && who[0] == pool[j]) || (who[1] && who[1] == pool[j])) {
                    chosen[count] = pool[j];
                    Npc *p = pool[j];
                    pool[j] = 0;
                    pairs[count * 2] = p->id;
                    pairs[count * 2 + 1] = p->id;
                    count++;
                }
            }
        }
    }
    FUN_0024e6a0(DAT_002fbf00);
    FUN_0024e6a0(DAT_002fbf04);
    FUN_0001cfa4(pairs, 0, count - 1);
    FUN_0024e6a0(DAT_002fbf38);
    for (int i = 0; i < count; i++)
        FUN_0024e6a0(DAT_002fbf44, pairs[i * 2 + 1]);
    FUN_0024e6a0(DAT_002fbf4c);
    FUN_0024e6a0(DAT_002fbf50, count);
    FUN_0024e6a0(DAT_002fbf00);
    Npc *r;
    do {
        DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
        r = chosen[(int)((DAT_00310fc8 >> 16) & 0x7fff) % count];
        if (!want)
            break;
    } while (want == r->id);
    FUN_0024e6a0(DAT_002fbf64, r->id, r->sub);
    FUN_0024e6a0(DAT_002fbf88);
    FUN_0024e6a0(DAT_002fbf00);
    return r;
}
