/* HSTMATCH module=EBOOT.BIN start=0x001905b8 end=0x00190724 symbol=FUN_001905b8 lang=c++ rodata=0x002c2754 helpers=FUN_0018cd90@0x0018cd90-0x0018cdbc */
/* Clone of src/sharing_main/save_task_request_0019cdc8.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* SaveTask request (strings at DAT_002c2844 / DAT_002c2810 / DAT_002c27e0 name SaveTask::Request): logs the request; while the task is busy the request is queued (FUN_001909ec push_back takes it by reference, so the parameter lives in its stack home) and a warning logged, otherwise it is stored and dispatched to FUN_0018cdbc through the 11-entry jump table (rodata=), unknown values logged. The empty variadic log stub FUN_0018cd90 is a same-file static helper placed by helpers= (task stays in a2 across it). Request 4 copies an 8-byte value as one `unsigned long long` (lw, lw, sw, sw; an int pair copies lw/sw interleaved). */
struct Save { char pad[0x788]; unsigned long long stamp; };
struct Deque { int w[8]; };   /* request queue, push_back = FUN_001909ec */
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

extern Mgr *DAT_003415a8;
extern unsigned char DAT_00311029;

extern "C" {
extern char DAT_002c2844[];
extern char DAT_002c2810[];
extern char DAT_002c27e0[];
static void FUN_0018cd90(...) { }
void FUN_0018cdbc(Task *, int);
void FUN_001909ec(Deque *, const int &);
}

extern "C" void FUN_001905b8(Owner *self, int req)
{
    Task *task = self->task;
    FUN_0018cd90(DAT_002c2844, req);
    if (task->busy != 0) {
        FUN_001909ec(&task->pending, req);
        FUN_0018cd90(DAT_002c2810, req);
    } else {
        task->request = req;
        switch (req) {
        case 0:
        case 1:
        case 2:
            FUN_0018cdbc(task, 1);
            break;
        case 3:
            FUN_0018cdbc(task, 2);
            break;
        case 4:
            DAT_00311029 = 0;
            task->save->stamp = DAT_003415a8->stamp;
            FUN_0018cdbc(task, 13);
            break;
        case 5:
            FUN_0018cdbc(task, 14);
            break;
        case 6:
            FUN_0018cdbc(task, 17);
            break;
        case 7:
            FUN_0018cdbc(task, 18);
            break;
        case 8:
            FUN_0018cdbc(task, 19);
            break;
        case 9:
            FUN_0018cdbc(task, 28);
            break;
        case 10:
            FUN_0018cdbc(task, 29);
            break;
        default:
            FUN_0018cd90(DAT_002c27e0, req);
            break;
        }
    }
}
