/* HSTMATCH module=EBOOT.BIN start=0x00055eac end=0x00056098 symbol=FUN_00055eac lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); exact match verified; names and types await human review. Steering trick: the error path is a goto fail. */
extern "C" char DAT_002d0f08[];
extern "C" char DAT_002d0f14[];
extern "C" char DAT_00311170[];

struct Clip
{
    int handle;
    int count;
    float span;
    void *frames;
};

extern "C" void FUN_000560a0(Clip *self);
extern "C" void *FUN_00056098(void *element, int arg);
extern "C" int FUN_0004cad0(void *src, int a1, int a2, int a3);
extern "C" void FUN_00049194();
extern "C" int FUN_0002ff6c(int handle);
extern "C" void FUN_000491cc();
extern "C" void FUN_0004f010(char *msg, int code, char *file, int line, char *fn);
extern "C" int FUN_000301ac(int handle);
extern "C" float FUN_00030fd4(int handle);
extern "C" void *FUN_00000a90(int size);
extern "C" void *FUN_000008d8(void *mem, void *(*init)(void *, int), int a2, int size, int count);
extern "C" void FUN_00030948(float time, int handle, void *buf, int flags);
extern "C" void FUN_00031130(void *buf, void *dst, short *idx);

extern "C" int FUN_00055eac(Clip *self, void *src, int play)
{
    short idx[514];
    unsigned char buf[24588];
    int i;
    int j;
    int n;
    void *mem;
    float f;

    FUN_000560a0(self);
    self->handle = FUN_0004cad0(src, 0, 0x10, 1);
    if (self->handle != 0) {
        FUN_00049194();
        i = FUN_0002ff6c(self->handle);
        FUN_000491cc();
        if (i != 0) {
            FUN_0004f010(DAT_00311170, i, DAT_002d0f08, 0x40, DAT_002d0f14);
            goto fail;
        }
        {
            self->count = FUN_000301ac(self->handle);
            f = FUN_00030fd4(self->handle);
            self->span = f * 30.0f;
            self->span = (float)(int)(self->span + 0.5f);
            if (play != 0) {
                n = self->count * ((int)self->span + 1);
                mem = FUN_00000a90(n * 0x40 + 0x10);
                self->frames = FUN_000008d8(mem, FUN_00056098, 0, 0x40, n);
                idx[0] = (short)self->count;
                for (j = 0; j < self->count; j++)
                    idx[j + 1] = (short)j;
                for (i = 0; i <= (int)self->span; i++) {
                    FUN_00030948((float)i * 0.033333335f, self->handle, buf, 0x222);
                    FUN_00031130(buf, (char *)self->frames + i * self->count * 0x40, idx);
                }
            }
        }
        return 1;
    }
    fail:
    FUN_000560a0(self);
    return 0;
}
