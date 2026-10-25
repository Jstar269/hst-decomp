/* HSTMATCH module=EBOOT.BIN start=0x0029d2b8 end=0x0029d72c symbol=FUN_0029d2b8 lang=c++ */
extern "C" {
extern void *DAT_00311000;
extern char DAT_002cb714[];
extern char DAT_002cb6dc[];
extern char DAT_002cb6a4[];
extern char DAT_002cb68c[];
int FUN_0010a900(void *, void *, int);
int FUN_0010a7cc(void *, int *);
void FUN_00060224(void *, int);
void FUN_0001b880(void);
void FUN_0029a584(const char *, ...);
int FUN_002b7790(const char *, int, int);
long long FUN_002b77a0(int, long long, int);
int FUN_002b7720(int, void *, int);
int FUN_002b7738(int);
void FUN_002b7958(int);
int FUN_002b7cf8(void);
}

struct Saver {
    char pad0[4];
    int busy;
    int state;
    char pad1[0x14 - 0xc];
    void *dir;
    void *name;
    void *buf;
    int size;

    void Idle() {}
    void SetState(int s)
    {
        state = s;
        switch (state) {
        case 0:
            Idle();
            break;
        case 3:
            busy = 0;
            break;
        case 4: {
            FUN_00060224(DAT_00311000, 1);
            FUN_0001b880();
            FUN_0029a584(DAT_002cb714, DAT_002cb6dc);
            int fd;
            while ((fd = FUN_002b7790(DAT_002cb6a4, 1, 0)) < 0)
                FUN_0001b880();
            while ((size = FUN_002b77a0(fd, 0, 2)) < 0)
                FUN_0001b880();
            while (FUN_002b77a0(fd, 0, 0) < 0)
                FUN_0001b880();
            while ((FUN_002b7cf8() & 0x20) == 0) {
                FUN_0029a584(DAT_002cb68c);
                FUN_002b7958(1000000);
            }
            for (;;) {
                int n = size;
                if (FUN_002b7720(fd, buf, n) == n)
                    break;
                FUN_002b7958(1000000);
            }
            while (FUN_002b7738(fd) < 0)
                FUN_002b7958(1000000);
            FUN_00060224(DAT_00311000, 0);
            break;
        }
        }
    }
};

extern "C" int FUN_0029d2b8(Saver *self)
{
    int count = 0;
    int r = FUN_0010a7cc(self->dir, &count);
    if (count > 0)
        self->SetState(6);
    else if (r < 0 || count < 0)
        self->SetState(9);
    return r;
}
// NEAR: 283/285 words, 238 differ (a 2-word shift after the switch header).
// Same SetState inline as 0x29ce64: retail keeps `beqz v1,end; nop; b end; nop` plus an unreachable
// case-3 body; ours folds to beqzl with the epilogue's first insn. Switch/if-chain/empty-inline/return forms tried.
// near miss from lane ol2 (unreviewed)
