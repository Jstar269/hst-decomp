/* HSTMATCH module=EBOOT.BIN start=0x001b8b48 end=0x001b8bfc symbol=FUN_001b8b48 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern int DAT_0034179c;
extern int FUN_001b1f7c(void *table, int id);
extern int FUN_001b2bb8(void *table, int id);
extern void FUN_001b9608(void *out, void *p60, void *p24, void *p32);

/* Arguments handed to the registration helper. */
struct RegisterArgs {
    int id;
    int count;
    void *slot_a;               /* address of the stored handle */
    void *slot_b;
};

/* Stores a freshly created handle in the object, or registers through the helper when count > 0 or the old handle is live. */
void FUN_001b8b48(char *self, int id, int count)
{
    struct RegisterArgs args;
    int result_out;
    void *range_end;

    if (count <= 0 &&
        (self + 100 == 0 ||
         FUN_001b1f7c(&DAT_0034179c, *(int *)(self + 100)) == 0)) {
        int handle = FUN_001b2bb8(&DAT_0034179c, id);
        if (self + 100 != 0) {
            *(int *)(self + 100) = handle;
        }
    } else {
        args.id = id;
        args.count = count;
        args.slot_a = self + 100;
        args.slot_b = self + 100;
        range_end = self + 64;
        FUN_001b9608(&result_out, self + 60, &range_end, &args);
    }
}
