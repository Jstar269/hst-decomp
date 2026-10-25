/* HSTMATCH module=EBOOT.BIN start=0x0029ce64 end=0x0029d2b8 symbol=FUN_0029ce64 lang=c++ */
extern "C" {
extern void *DAT_00311000;
extern char DAT_002cb714[];
extern char DAT_002cb6dc[];
extern char DAT_002cb6a4[];
extern char DAT_002cb68c[];
int FUN_0010a900(void *, void *, int);
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
    char pad1[0x18 - 0xc];
    void *name;
    void *buf;
    int size;

    void SetState(int s)
    {
        state = s;
        switch (state) {
        case 0:
            return;
        case 3:
            busy = 0;
            return;
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

extern "C" int FUN_0029ce64(Saver *self)
{
    int n = self->size;
    if (FUN_0010a900(self->name, self->buf, n) < 0)
        self->SetState(9);
    else
        self->SetState(7);
    return 0;
}
// NEAR: 274/277 words, 234 differ (mostly a 3-word shift).
// Left: (1) retail loads size (a2) then name (a0) before the call, ours name last;
// (2) the inlined SetState switch keeps `beqz v1,end; nop; b end; nop` and an unreachable case-3 body
// (`sw zero,4; b end`) in both copies; ours folds them and tail-duplicates `lw ra` into a beqzl slot.
// The loops (open/lseek/lseek64/wait 0x20/read/close) match once the read loop is the mid-exit for(;;) and
// the status wait is `while ((f() & 0x20) == 0)`.
// near miss from lane ol2 (unreviewed)
