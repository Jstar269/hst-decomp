/* HSTMATCH module=EBOOT.BIN start=0x00155248 end=0x001552c8 symbol=FUN_00155248 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Handler {
    int pad0;
    int pad4;
    int id;
};

extern unsigned char DAT_003402f0;     /* debug-log enable flag */
extern char DAT_002dca88[];            /* "GetLastCourt %d reg %d" */
extern "C" int FUN_0022cbd4();
extern "C" int *FUN_0014c384(int key, int id);
extern "C" void FUN_0014d044(int *msg);
extern "C" void FUN_0014fd94(const char *fmt, ...);

extern "C" int FUN_00155248(Handler *self, int *msg)
{
    int key = *msg;
    int value = FUN_0022cbd4();
    *FUN_0014c384(key, self->id) = value;
    if (DAT_003402f0) {
        FUN_0014d044(msg);
        FUN_0014fd94(DAT_002dca88, value, self->id);
    }
    return 0;
}
