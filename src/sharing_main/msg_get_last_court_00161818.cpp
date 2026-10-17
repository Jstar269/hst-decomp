/* HSTMATCH module=hstp_trans_main.prx start=0x00161818 end=0x00161898 symbol=FUN_00161818 lang=c++ */
/* Clone of src/eboot/msg_get_last_court_00155248.cpp (hstclone.py tag c35): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Handler {
    int pad0;
    int pad4;
    int id;
};

extern unsigned char DAT_003e9630;     /* debug-log enable flag */
extern char DAT_00383fa8[];            /* "GetLastCourt %d reg %d" */
extern "C" int FUN_0023cd54();
extern "C" int *FUN_00157e10(int key, int id);
extern "C" void FUN_00158b2c(int *msg);
extern "C" void FUN_0015bb68(const char *fmt, ...);

extern "C" int FUN_00161818(Handler *self, int *msg)
{
    int key = *msg;
    int value = FUN_0023cd54();
    *FUN_00157e10(key, self->id) = value;
    if (DAT_003e9630) {
        FUN_00158b2c(msg);
        FUN_0015bb68(DAT_00383fa8, value, self->id);
    }
    return 0;
}
