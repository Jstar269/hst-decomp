/* HSTMATCH module=EBOOT.BIN start=0x0011a2ac end=0x0011a4ac symbol=FUN_0011a2ac lang=c++ rodata=0x2c12c0 */
struct Cfg {
    char pad[0x50];
    int f50;
    char pad1[0x98 - 0x54];
    int f98;
    int f9c;
};
struct Cell {
    char pad[0x234];
    int f234;
};
struct Game {
    char pad[0x3c];
    int f3c;
    char pad1[0x88 - 0x40];
    Cell *f88;
};
struct Rec {
    int kind;
    int amount;
    float tag;
};
struct Obj {
    char pad0[0xf4];
    int tot[4];
    int cnt[2][33];
    char pad1[0x264 - 0x104 - 264];
    unsigned char flag[12];
    int amt[2][11];
    char pad3[0x2cc - 0x270 - 88];
    int f2cc;
    int f2d0;
    char pad4[0x2dd - 0x2d4];
    unsigned char active;
    char pad5[0x2e0 - 0x2de];
    int list[1];
};
extern Cfg *DAT_00338b44;
extern Game *DAT_003386b0;
extern int DAT_002d9c80;
extern "C" void FUN_0011caa0(void *, Rec *);

template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }

extern "C" void FUN_0011a2ac(float tag, Obj *o, int kind)
{
    if (o->active == 0) {
        return;
    }
    int cur = o->f2cc;
    int lim = DAT_00338b44->f98;
    int has = DAT_00338b44->f9c != 0;
    int same = 0;
    if (lim < 0) {
        lim = DAT_00338b44->f50;
    }
    switch (kind) {
    case 0:
    case 1:
    case 2:
    case 3:
        same = o->f2d0 == has;
        if (same && cur != lim) {
            return;
        }
        break;
    case 4:
    case 5:
    case 6:
        same = o->f2d0 == has;
        break;
    case 7:
        same = cur == lim;
        break;
    case 8:
    case 9:
    case 10:
        if (DAT_003386b0->f3c == 7) {
            lim = DAT_003386b0->f88->f234;
        }
        same = cur == lim;
        o->flag[kind] = DAT_003386b0->f3c != 7;
        break;
    default:
        same = 0;
    }
    int amount = o->amt[!same][kind];
    if (amount != 0) {
        Rec r;
        r.kind = kind;
        r.amount = amount;
        r.tag = tag;
        FUN_0011caa0(&o->list, &r);
        if (o->flag[kind] != 0) {
            o->flag[kind] = 0;
            int sum = o->tot[cur] + amount;
            o->tot[cur] = Max(sum, DAT_002d9c80);
            o->cnt[same ^ 1][kind] += 1;
        }
    }
}
// lane sn6: 122/128 words (six short), 91 differ. Semantics are complete: per-kind "is current" test through a jump table at 0x2c12c0 (kinds 0-3: f2d0 == has && cur != lim early return; 4-6: f2d0 == has;
// 7: cur == lim; 8-10: lim replaced by cell->f234 when the game state is 7, flag byte at 0x264+kind set when the state is not 7; kinds > 10: same = 0), amt = o->amt[!same][kind] (0x270 + !same*0x2c +
// kind*4), event record {kind, amt, float tag} passed by reference to FUN_0011caa0(o + 0x2e0, &r), then tot[cur] = max(tot[cur] + amt, DAT_002d9c80) (inline Max by const ref: the sum goes to sp+32) and
// cnt[!same][kind] += 1 (0x104 + !same*0x84 + kind*4), flag cleared first.
// Open: register colours. Retail keeps `same` in s1 across the FUN_0011caa0 call and RECOMPUTES `sltu v1,zero,s1; xori v1,1; andi 0xff` for the second index (kind=s2, obj=s3, amt=s4, kind*4=s5);
// ours either CSEs !same into a saved register (the `!same` twice form) or keeps `same` in s5 (`same ^ 1` second use). All 24 declaration orders of cur/lim/has/same give the same code; bool vs int `same`
// and `!same` vs `same ^ 1` combinations (5 forms) tried.
// near miss from lane sn6 (unreviewed)
