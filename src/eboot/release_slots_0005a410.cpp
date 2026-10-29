/* HSTMATCH module=EBOOT.BIN start=0x0005a410 end=0x0005a500 symbol=FUN_0005a410 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); exact match verified; names and types await human review. */
extern "C" char DAT_0030703c[];
extern "C" void *DAT_00331364;
extern "C" unsigned int DAT_00331368;
extern "C" unsigned int DAT_0033136c;
extern "C" void FUN_00000a00(void *self);

struct Tag {};

extern "C" void FUN_0005afb4(void **pool, int *slot, Tag tag);

struct Cmd2
{
    char pad[0x50];
    int f50;
    char pad2[0x10];
    int slots[2];
};

inline void Push(int &slot)
{
    if (DAT_00331368 < DAT_0033136c) {
        DAT_00331368 = DAT_00331368 + 1;
        ((void **)DAT_00331364)[DAT_00331368 - 1] = (void *)slot;
    } else {
        FUN_0005afb4(&DAT_00331364, &slot, Tag());
    }
    slot = 0;
}

/* Deleting destructor: moves both slot values into the global pool and frees self when mode is positive. */
extern "C" Cmd2 *FUN_0005a410(Cmd2 *self, short mode)
{
    if (self) {
        *(void **)self = DAT_0030703c;
        if (self->f50) {
            for (unsigned i = 0; i < 2; i++) {
                if (self->slots[i])
                    Push(self->slots[i]);
            }
        }
        if (mode > 0)
            FUN_00000a00(self);
    }
    return self;
}
