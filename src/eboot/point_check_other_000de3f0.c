/* HSTMATCH module=EBOOT.BIN start=0x000de3f0 end=0x000de51c symbol=FUN_000de3f0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Slot { char pad[0x144]; unsigned f144; } Slot;
typedef struct Game { char pad[0x70]; Slot *slots[2]; } Game;
typedef struct Match {
    char pad0[0x50];
    int f50;
    char pad1[0xcc - 0x54];
    int fcc;
    int score[2];
} Match;
extern Game *DAT_003386b0;
extern unsigned char DAT_003417bb;
extern int FUN_000def0c(Match *);

int FUN_000de3f0(Match *m, int arg)
{
    unsigned cur = DAT_003386b0->slots[m->f50]->f144 ^ 1;
    if (arg < 0 || (unsigned)arg == cur) {
        if (FUN_000def0c(m) != 0) {
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
                if (!ok) ok = DAT_003417bb == 1;
                if (ok) r = 1;
            }
            return r;
        }
    }
    return 0;
}
