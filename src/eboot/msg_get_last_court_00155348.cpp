/* HSTMATCH module=EBOOT.BIN start=0x00155348 end=0x001553c8 symbol=FUN_00155348 lang=c++ data=0x002dcac0 */
/* Clone of src/eboot/msg_get_last_court_00155248.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dcac0-0x002dcad6) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Handler {
    int pad0;
    int pad4;
    int id;
};

extern unsigned char DAT_003402f0;     /* debug-log enable flag */
extern "C" int FUN_0022cc54();
extern "C" int *FUN_0014c384(int key, int id);
extern "C" void FUN_0014d044(int *msg);
extern "C" void FUN_0014fd94(const char *fmt, ...);

extern "C" int FUN_00155348(Handler *self, int *msg)
{
    int key = *msg;
    int value = FUN_0022cc54();
    *FUN_0014c384(key, self->id) = value;
    if (DAT_003402f0) {
        FUN_0014d044(msg);
        FUN_0014fd94("GetPocket %d(reg:%d)\n", value, self->id);
    }
    return 0;
}
