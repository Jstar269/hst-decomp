/* HSTMATCH module=EBOOT.BIN start=0x000c038c end=0x000c0634 symbol=FUN_000c038c lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/ptp_link.h"

struct MacAddr {
    unsigned char addr[6];
};

/* Argument block handed to the worker thread (0x28 bytes). */
struct ThreadArg {
    unsigned char byte_arg;
    char pad[3];
    short *shared_short;
    char *stop_flag;
    int sema_id;
    MacAddr mac_a;
    MacAddr mac_b;
    int word_arg;
    PtpQueue *write_queue;
    PtpQueue *read_queue;
};

enum {
    ALLOC_SHARED_SHORT = 2,   /* sizes of the cells shared with the worker */
    ALLOC_STOP_FLAG = 1,
    ALLOC_QUEUE = 20,         /* size of one PtpQueue */
    THREAD_PRIORITY = 0x28,
    THREAD_STACK_SIZE = 0x2000
};

extern "C" {
extern char DAT_002d58bc[];
extern char DAT_002d58cc[];
extern char DAT_002d58f8[];
extern char DAT_002d5908[];
extern char DAT_002d5934[];
extern char DAT_002d5960[];
extern char DAT_002d5874[];

void* FUN_00000bcc(unsigned int);
void FUN_00000a00(void*);
PtpQueue* FUN_000ff4fc(void*, int);
void FUN_000c02ac(const char*, int);
int FUN_002b7890(const char*, int, int, int, int);
int FUN_002b7920(const char*, void*, int, int, int, int);
int FUN_002b78d8(int, int, void*);
int FUN_002b79a8(int);
int FUN_002b78e8(int);
void FUN_000bfb94(int, void*);

int FUN_000c038c(PtpLink *self, unsigned char byte_arg, int word_arg, const MacAddr *mac_a, const MacAddr *mac_b);
}

/* Creates the link's shared cells, queues, semaphore and worker thread; tears everything down again on failure. */
int FUN_000c038c(PtpLink *self, unsigned char byte_arg, int word_arg, const MacAddr *mac_a, const MacAddr *mac_b) {
    ThreadArg arg;

    arg.byte_arg = byte_arg;
    arg.mac_a = *mac_a;
    if (mac_b != 0) {
        arg.mac_b = *mac_b;
    }

    short *shared_short = (short*)FUN_00000bcc(ALLOC_SHARED_SHORT);
    if (shared_short != 0) {
        *shared_short = 0;
    }
    self->shared_short = shared_short;
    arg.shared_short = shared_short;

    char *stop_flag = (char*)FUN_00000bcc(ALLOC_STOP_FLAG);
    if (stop_flag != 0) {
        *stop_flag = 0;
    }
    self->stop_flag = stop_flag;
    arg.stop_flag = stop_flag;

    PtpQueue *write_queue = (PtpQueue*)FUN_00000bcc(ALLOC_QUEUE);
    if (write_queue != 0) {
        write_queue = FUN_000ff4fc(write_queue, PTP_QUEUE_CAPACITY);
    }
    self->write_queue = write_queue;
    arg.write_queue = write_queue;

    PtpQueue *read_queue = (PtpQueue*)FUN_00000bcc(ALLOC_QUEUE);
    if (read_queue != 0) {
        read_queue = FUN_000ff4fc(read_queue, PTP_QUEUE_CAPACITY);
    }
    self->read_queue = read_queue;
    arg.read_queue = read_queue;

    arg.word_arg = word_arg;

    int sema = FUN_002b7890(DAT_002d58bc, 0, 1, 1, 0);
    if (sema < 1) {
        FUN_000c02ac(DAT_002d58cc, sema);
    } else {
        self->sema_id = sema;
        arg.sema_id = sema;
        int thid = FUN_002b7920(DAT_002d58f8, (void*)FUN_000bfb94, THREAD_PRIORITY, THREAD_STACK_SIZE, 0, 0);
        if (thid < 1) {
            FUN_000c02ac(DAT_002d5908, thid);
        } else {
            self->thread_id = thid;
            int res = FUN_002b78d8(thid, sizeof(ThreadArg), &arg);
            if (res != 0) {
                FUN_000c02ac(DAT_002d5934, res);
            } else {
                return 1;
            }
        }
    }

    if (self->thread_id > 0) {
        int err = FUN_002b79a8(self->thread_id);
        if (err != 0) {
            FUN_000c02ac(DAT_002d5960, err);
        }
        self->thread_id = -1;
    }
    if (self->sema_id > 0) {
        int err = FUN_002b78e8(self->sema_id);
        if (err != 0) {
            FUN_000c02ac(DAT_002d5874, err);
        }
        self->sema_id = -1;
    }
    if (self->read_queue != 0) {
        delete self->read_queue;
        self->read_queue = 0;
    }
    if (self->write_queue != 0) {
        delete self->write_queue;
        self->write_queue = 0;
    }
    if (self->stop_flag != 0) {
        FUN_00000a00(self->stop_flag);
        self->stop_flag = 0;
    }
    if (self->shared_short != 0) {
        FUN_00000a00(self->shared_short);
        self->shared_short = 0;
    }
    return 0;
}
