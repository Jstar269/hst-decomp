/* HSTMATCH module=hstp_trans_main.prx start=0x000c3a2c end=0x000c3cd4 symbol=FUN_000c3a2c lang=c++ */
/* Clone of src/eboot/init_adhoc_ptp_000c038c.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
struct MacAddr {
    unsigned char addr[6];
};

struct Queue {
    virtual ~Queue();
};

struct ThreadArg {
    unsigned char param_2;
    char pad[3];
    short *buf1;
    char *buf2;
    int sema_id;
    MacAddr mac1;
    MacAddr mac2;
    int param_3;
    Queue *obj1;
    Queue *obj2;
};

struct Obj {
    int pad0;
    int thread_id;
    int sema_id;
    short *buf1;
    char *buf2;
    Queue *obj1;
    Queue *obj2;
};

extern "C" {
extern char DAT_0037c20c[];
extern char DAT_0037c21c[];
extern char DAT_0037c248[];
extern char DAT_0037c258[];
extern char DAT_0037c284[];
extern char DAT_0037c2b0[];
extern char DAT_0037c1c4[];

void* FUN_00000bcc(unsigned int);
void FUN_00000a00(void*);
Queue* FUN_00104d94(void*, int);
void FUN_000c394c(const char*, int);
int FUN_002c7630(const char*, int, int, int, int);
int FUN_002c76c0(const char*, void*, int, int, int, int);
int FUN_002c7678(int, int, void*);
int FUN_002c7748(int);
int FUN_002c7688(int);
void FUN_000c3234(int, void*);

int FUN_000c3a2c(Obj *self, unsigned char param_2, int param_3, const MacAddr *param_4, const MacAddr *param_5);
}

int FUN_000c3a2c(Obj *self, unsigned char param_2, int param_3, const MacAddr *param_4, const MacAddr *param_5) {
    ThreadArg arg;

    arg.param_2 = param_2;
    arg.mac1 = *param_4;
    if (param_5 != 0) {
        arg.mac2 = *param_5;
    }

    short *buf1 = (short*)FUN_00000bcc(2);
    if (buf1 != 0) {
        *buf1 = 0;
    }
    self->buf1 = buf1;
    arg.buf1 = buf1;

    char *buf2 = (char*)FUN_00000bcc(1);
    if (buf2 != 0) {
        *buf2 = 0;
    }
    self->buf2 = buf2;
    arg.buf2 = buf2;

    Queue *p1 = (Queue*)FUN_00000bcc(20);
    if (p1 != 0) {
        p1 = FUN_00104d94(p1, 0x10000);
    }
    self->obj1 = p1;
    arg.obj1 = p1;

    Queue *p2 = (Queue*)FUN_00000bcc(20);
    if (p2 != 0) {
        p2 = FUN_00104d94(p2, 0x10000);
    }
    self->obj2 = p2;
    arg.obj2 = p2;

    arg.param_3 = param_3;

    int sema = FUN_002c7630(DAT_0037c20c, 0, 1, 1, 0);
    if (sema < 1) {
        FUN_000c394c(DAT_0037c21c, sema);
    } else {
        self->sema_id = sema;
        arg.sema_id = sema;
        int thid = FUN_002c76c0(DAT_0037c248, (void*)FUN_000c3234, 0x28, 0x2000, 0, 0);
        if (thid < 1) {
            FUN_000c394c(DAT_0037c258, thid);
        } else {
            self->thread_id = thid;
            int res = FUN_002c7678(thid, 0x28, &arg);
            if (res != 0) {
                FUN_000c394c(DAT_0037c284, res);
            } else {
                return 1;
            }
        }
    }

    if (self->thread_id > 0) {
        int err = FUN_002c7748(self->thread_id);
        if (err != 0) {
            FUN_000c394c(DAT_0037c2b0, err);
        }
        self->thread_id = -1;
    }
    if (self->sema_id > 0) {
        int err = FUN_002c7688(self->sema_id);
        if (err != 0) {
            FUN_000c394c(DAT_0037c1c4, err);
        }
        self->sema_id = -1;
    }
    if (self->obj2 != 0) {
        delete self->obj2;
        self->obj2 = 0;
    }
    if (self->obj1 != 0) {
        delete self->obj1;
        self->obj1 = 0;
    }
    if (self->buf2 != 0) {
        FUN_00000a00(self->buf2);
        self->buf2 = 0;
    }
    if (self->buf1 != 0) {
        FUN_00000a00(self->buf1);
        self->buf1 = 0;
    }
    return 0;
}
