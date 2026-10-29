/* HSTMATCH module=EBOOT.BIN start=0x00294564 end=0x00294684 symbol=FUN_00294564 lang=c99 */
/* Hand-written reconstruction (external matching lane). Notes: Ghidra's `buf = 0;` in the null arm of
   the 0x14-byte allocation does NOT exist in retail - dropping it is what removes the extra block
   (retail happily falls through to `*(int *)(buf + 0x10) = 0` with a null buf). Both allocation
   guards are written with the non-null arm first (`if (job != 0)`) so the null case is the
   out-of-line block, and the null arm stores the pointer variable itself (`self->job = job;`)
   rather than a literal 0, which is what puts `sw s0,60(s1)` in the beqzl delay slot.
   Readability pass; exact match verified; names and types await human review. */
#include "hst/install_job.h"

extern int DAT_00309e48;
extern char DAT_002cac84[];
extern int *DAT_0034a850;  /* the live manager object */
extern int FUN_0001f06c();
extern int FUN_00000bcc(int);
extern void FUN_00294684(char *);
extern int FUN_000ff4fc(int, int);
extern int FUN_00010184(int, int);
extern void FUN_000114c0(int, int, int);

enum { READER_BUFFER_SIZE = 0x40000 };

/* Manager object: only the install job pointer is used here. */
typedef struct InstallManager {
    int vtable;          /* 0x00 */
    char pad04[0x38];    /* 0x04 */
    InstallJob *job;     /* 0x3c */
} InstallManager;

/* Constructor: allocates and initialises the install job and its work buffer. */
InstallManager *FUN_00294564(InstallManager *self)
{
    InstallJob *job;
    int buf;
    int work;

    FUN_0001f06c();
    self->vtable = (int)&DAT_00309e48;
    self->job = 0;
    DAT_0034a850 = (int *)self;
    job = (InstallJob *)FUN_00000bcc(INSTALL_JOB_SIZE);
    if (job != 0) {
        job->state = 0;
        job->unk04 = 0;
        job->unk08 = 0;
        job->unk0c = 0;
        job->unk10 = INSTALL_UNSET;
        job->unk14 = INSTALL_UNSET;
        job->unk18 = 0;
        job->unk1c = 0;
        job->unk20 = 0;
        job->unk21 = 0;
        job->thread = INSTALL_NONE;
        job->timer = 0;
        job->fd = INSTALL_NONE;
        job->async = 0;
        job->unk331 = 1;
        job->unk334 = 0;
        job->unk7738 = 0;
        job->unkeb3c = 0;
        job->unkeb40 = 0;
        FUN_00294684(DAT_002cac84);
        buf = FUN_00000bcc(0x14);
        if (buf != 0) {
            buf = FUN_000ff4fc(buf, READER_BUFFER_SIZE);
            job->unk334 = buf;
        } else {
            job->unk334 = buf;
        }
        *(int *)(buf + 0x10) = 0;
        *(int *)(buf + 0xc) = 0;
        work = FUN_00010184(0x40, INSTALL_WORK_SIZE);
        job->unk04 = work;
        FUN_000114c0(work, 0, INSTALL_WORK_SIZE);
        self->job = job;
    } else {
        self->job = job;
    }
    return self;
}
