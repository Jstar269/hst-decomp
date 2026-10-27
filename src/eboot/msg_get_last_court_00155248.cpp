/* HSTMATCH module=EBOOT.BIN start=0x00155248 end=0x001552c8 symbol=FUN_00155248 lang=c++ data=0x002dca88 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dca88-0x002dcaa1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Handler {
    int pad0;
    int pad4;
    int id;
};

extern unsigned char DAT_003402f0;     /* debug-log enable flag */
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
        FUN_0014fd94("GetLastCourt %d(reg:%d)\n", value, self->id);
    }
    return 0;
}
