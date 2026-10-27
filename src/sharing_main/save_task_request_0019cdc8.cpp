/* HSTMATCH module=hstp_trans_main.prx start=0x0019cdc8 end=0x0019cf34 symbol=FUN_0019cdc8 lang=c++ rodata=0x002d2c54 helpers=FUN_00199570@0x00199570-0x0019959c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* SaveTask request (strings at DAT_002d2d44 / DAT_002d2d10 / DAT_002d2ce0 name SaveTask::Request): logs the request; while the task is busy the request is queued (FUN_0019d1fc push_back takes it by reference, so the parameter lives in its stack home) and a warning logged, otherwise it is stored and dispatched to FUN_0019959c through the 11-entry jump table (rodata=), unknown values logged. The empty variadic log stub FUN_00199570 is a same-file static helper placed by helpers= (task stays in a2 across it). Request 4 copies an 8-byte value as one `unsigned long long` (lw, lw, sw, sw; an int pair copies lw/sw interleaved). */
struct Save { char pad[0x788]; unsigned long long stamp; };
struct Deque { int w[8]; };   /* request queue, push_back = FUN_0019d1fc */
struct Task {
    char pad0[8];
    int busy;
    char pad0c[4];
    Save *save;
    char pad14[0xb0 - 0x14];
    int request;
    Deque pending;
};
struct Owner { char pad[0x3c]; Task *task; };
struct Mgr { char pad[0x18]; unsigned long long stamp; };

extern Mgr *DAT_003ea8e8;
extern unsigned char DAT_003ba329;

extern "C" {
extern char DAT_002d2d44[];
extern char DAT_002d2d10[];
extern char DAT_002d2ce0[];
static void FUN_00199570(...) { }
void FUN_0019959c(Task *, int);
void FUN_0019d1fc(Deque *, const int &);
}

extern "C" void FUN_0019cdc8(Owner *self, int req)
{
    Task *task = self->task;
    FUN_00199570(DAT_002d2d44, req);
    if (task->busy != 0) {
        FUN_0019d1fc(&task->pending, req);
        FUN_00199570(DAT_002d2d10, req);
    } else {
        task->request = req;
        switch (req) {
        case 0:
        case 1:
        case 2:
            FUN_0019959c(task, 1);
            break;
        case 3:
            FUN_0019959c(task, 2);
            break;
        case 4:
            DAT_003ba329 = 0;
            task->save->stamp = DAT_003ea8e8->stamp;
            FUN_0019959c(task, 13);
            break;
        case 5:
            FUN_0019959c(task, 14);
            break;
        case 6:
            FUN_0019959c(task, 17);
            break;
        case 7:
            FUN_0019959c(task, 18);
            break;
        case 8:
            FUN_0019959c(task, 19);
            break;
        case 9:
            FUN_0019959c(task, 28);
            break;
        case 10:
            FUN_0019959c(task, 29);
            break;
        default:
            FUN_00199570(DAT_002d2ce0, req);
            break;
        }
    }
}
