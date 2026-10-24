/* HSTMATCH module=EBOOT.BIN start=0x0029675c end=0x00296918 symbol=FUN_0029675c lang=c99 */

typedef unsigned char undefined1;

struct Io_29675c {
    char pad0[0x32c];
    int fd;                        /* 0x32c */
    undefined1 f330;               /* 0x330 */
    char pad1[3];
    int f334;                      /* 0x334 */
    unsigned char buf[0x7400];     /* 0x338 */
    int f7738;                     /* 0x7738 */
    unsigned char buf2[0x7400];    /* 0x773c */
    unsigned char *cur;            /* 0xeb3c */
    int f_eb40;                    /* 0xeb40 */
};

extern char DAT_002cad1c[];
extern char DAT_002cacf4[];
extern int FUN_002b77a8(int fd, int *status);
extern int FUN_002b7748(int fd, void *buf, int size);
extern void FUN_002b7958(int ms);
extern int FUN_000ff5b0(int f334, void *dst);
extern void FUN_00011090(void *dst, void *src, int n);
extern void FUN_00294684(char *fmt, ...);

void FUN_0029675c(struct Io_29675c *p)
{
    int r;
    int st[2];

    if (p->f_eb40 > 0) {
        r = FUN_000ff5b0(p->f334, p->cur);
        p->f_eb40 = p->f_eb40 - r;
        p->cur = p->cur + r;
        if (p->f_eb40 == 0) {
            r = FUN_002b7748(p->fd, p->buf, 0x7400);
            if (r != 0)
                FUN_00294684(DAT_002cacf4, r);
            p->f330 = 1;
        }
    } else {
        r = FUN_002b77a8(p->fd, st);
        if (r == 0) {
            p->f330 = 0;
            if (st[0] < 0) {
                FUN_00294684(DAT_002cad1c, st[0]);
                FUN_002b7958(100);
                r = FUN_002b7748(p->fd, p->buf, 0x7400);
                if (r != 0)
                    FUN_00294684(DAT_002cacf4, r);
                p->f330 = 1;
            } else {
                p->f7738 = st[0];
                r = FUN_000ff5b0(p->f334, p->buf);
                if (r < p->f7738) {
                    p->f_eb40 = p->f7738 - r;
                    p->cur = p->buf2;
                    FUN_00011090(p->buf2, p->buf + r, p->f_eb40);
                } else {
                    r = FUN_002b7748(p->fd, p->buf, 0x7400);
                    if (r != 0)
                        FUN_00294684(DAT_002cacf4, r);
                    p->f330 = 1;
                }
            }
        }
    }
}

// 110/111 words, 64 differ (all from a one-word shift after the first block).
// Matches: struct layout (fd@0x32c, f330@0x330, f334@0x334, 0x7400-byte buffer@0x338, f7738@0x7738,
// second 0x7400 buffer@0x773c, cur@0xeb3c, f_eb40@0xeb40 - note 0x338+0x7400 = 0x7738 exactly, and the
// >0x7fff fields come out as retail's `lui v0,0x1; addu v0,s0,v0; lw -5312(v0)` as plain struct fields),
// every call and every branch.
// Two things that were needed:
// - the arms: retail's first test is `blez a2` onto the OUT-OF-LINE poll arm, i.e. the source reads
//   `if (p->f_eb40 > 0) { continue the transfer } else { poll }` - writing the poll arm first emits
//   `bgtz` with the arms the other way round.
// - the read-async error print takes the return value as a second argument: `move a1,v0; beqzl a1`
//   only appears once the call is `FUN_00294684(DAT_002cacf4, r)` (Ghidra's variadic prototype had
//   dropped it). That was worth 3 words and 13 diffs.
// Remaining (allocator only): retail keeps the status value and the first f_eb40 read in a2, so the
// poll-error print needs `move a1,a2`; ours puts them in a1/v0 and needs no move (one word shorter).
// Tried: scalar `int status;` instead of `int st[2]`, `int n = p->f_eb40` before the first test,
// `int n = st[0]` (hoists the load above the sb and turns bgezl into bgez), no-variable call forms.
// near miss from lane fm7 (unreviewed)
