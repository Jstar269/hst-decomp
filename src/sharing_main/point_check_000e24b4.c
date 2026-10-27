/* HSTMATCH module=hstp_trans_main.prx start=0x000e24b4 end=0x000e25dc symbol=FUN_000e24b4 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/point_check_000de2c8.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
typedef struct Slot { char pad[0x144]; unsigned f144; } Slot;
typedef struct Game { char pad[0x70]; Slot *slots[2]; } Game;
typedef struct Match {
    char pad0[0x50];
    int f50;
    char pad1[0xcc - 0x54];
    int fcc;
    int score[2];
} Match;
extern Game *DAT_003e19f0;
extern unsigned char DAT_003eaaf3;
extern int FUN_000e30f8(Match *);

int FUN_000e24b4(Match *m, int arg)
{
    unsigned cur = DAT_003e19f0->slots[m->f50]->f144;
    if (arg < 0 || (unsigned)arg == cur) {
        if (FUN_000e30f8(m) != 0) {
            int r = 1;
            int n = m->score[cur] + 1;
            if (n < 9) {
                int b = n > 6;
                if (b) b = n - m->score[cur ^ 1] > 1;
                if (!b) r = 0;
            }
            return r;
        } else {
            int r = 0;
            int n = m->score[cur] + 1;
            if (!(n < m->fcc)) {
                int ok = n - m->score[cur ^ 1] > 1;
                if (!ok) ok = DAT_003eaaf3 == 1;
                if (ok) r = 1;
            }
            return r;
        }
    }
    return 0;
}
