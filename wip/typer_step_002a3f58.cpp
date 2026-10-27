/* HSTMATCH module=EBOOT.BIN start=0x002a3f58 end=0x002a41ac symbol=FUN_002a3f58 lang=c++ */
struct Game {
    char pad[0x86bd0];
    int speed;
};

struct Opts {
    char pad[0x8b];
    signed char f0 : 2;
    signed char f1 : 2;
    signed char f2 : 4;
};

struct Typer {
    const char *src;
    char text[256];
    int pos;
    int count;
    unsigned char done;
};

extern "C" {
extern Game *DAT_003415a8;
extern Opts *DAT_002cfc8c;
extern int DAT_0034179c;
void *FUN_00011090(void *dst, const void *src, int n);
int FUN_001b1c44(int *, int);
}

static inline bool IsCtrl(char ch)
{
    unsigned char c = ch;
    bool r = false;
    if (c != 0 && c < 16) r = true;
    return r;
}

static inline int CtrlWidth(char ch)
{
    unsigned char c = ch;
    bool ok = c != 0;
    if (ok) ok = c < 16;
    if (!ok) return 0;
    if (ch == 8) return 3;
    return 2;
}

static inline bool IsCharStart(char c)
{
    bool r = true;
    if ((c & 0x80) && (c & 0xc0) != 0xc0) r = false;
    return r;
}

extern "C" void FUN_002a3f58(Typer *t)
{
    if (t->src == 0) return;
    float steps;
    switch (DAT_003415a8->speed) {
    case 0: steps = 1.0f; break;
    default:
    case 1: steps = 2.0f; break;
    case 2: steps = 3.0f; break;
    }
    if (t->count < 4) {
        int n = 0;
        while (steps-- > 0.0f) {
            const char *s = t->src + t->pos;
            n = 0;
            while ((bool)s[n] && IsCtrl(s[n])) {
                n += CtrlWidth(s[n]);
            }
            while (s[n] != 0) {
                n++;
                if (IsCharStart(s[n])) break;
            }
            FUN_00011090(t->text + t->pos, s, n);
            t->pos += n;
            t->text[t->pos] = 0;
        }
        if (n < 1) t->count++;
        else FUN_001b1c44(&DAT_0034179c, 20);
    }
    if (3 < t->count && (DAT_002cfc8c->f1 != 0) ^ 1) {
        FUN_001b1c44(&DAT_0034179c, 19);
        t->done = 1;
    }
}
// near miss, lane wf20261026-e01-01 (unreviewed): 148/149 words, ~12 instructions differ, all in the second (UTF-8 continuation) loop.
// Solved here: speed switch `case 0: / default: case 1: / case 2:` (shared 2.0f body), `(bool)s[n]` loop-1 test (retail sltu;xori;bnez),
// CtrlWidth `bool ok = c != 0; if (ok) ok = c < 16;` (retail beqz a3 to the join), `if (n < 1) count++; else F(..,20)`, `3 < t->count`,
// `(f1 != 0) ^ 1` for the bitfield test.
// Open: retail RELOADS s[n] for loop 2's back-edge test (`lb v1,0(v1)` after IsCharStart) and lays `if (start) break;` out as
// `beqzl t0,reload; b copy`; ours CSEs the IsCharStart load (bnezl a3) and seb's the entry test. Tried: while/do/if-do/continue forms,
// IsCharStart(char/unsigned/signed/int/const char&/const char*), `(bool)`/`*(s+n)`/`(int)` loop-2 tests, end-test helpers (A-F in try/lane-work/w2a3f58/gen5.py).
// near miss from lane wf20261026-e01-01 (unreviewed)
