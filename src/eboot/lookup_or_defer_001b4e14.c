/* HSTMATCH module=EBOOT.BIN start=0x001b4e14 end=0x001b4edc symbol=FUN_001b4e14 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_0034179c[];

extern int FUN_001b1f7c(char *tbl, int v);
extern int FUN_001b2bb8(char *tbl, int v);
extern void FUN_001b9608(int *out, void *owner, int *pos, void *request);

/* Request record handed to FUN_001b9608. */
typedef struct Request {
    int id;
    int amount;
    int *out;
    int *handle;
} Request;

/* Position pair: the address of the owner's field at +4, then the callee's output slot. */
typedef struct PosPair {
    int pos;
    int result;
} PosPair;

/* With amount <= 0 and no live handle: look `id` up directly, store it through `out` (when given) and return it. Otherwise queue a request through FUN_001b9608 and return -1. */
int FUN_001b4e14(void *owner, int id, int amount, int *out, int *handle)
{
    int v;

    if (amount <= 0) {
        if (handle != 0) {
            if (FUN_001b1f7c(DAT_0034179c, *handle) != 0)
                goto queue;
        }
        v = FUN_001b2bb8(DAT_0034179c, id);
        if (out != 0)
            *out = v;
        return v;
    }
queue:
    {
        Request req;
        PosPair pp;

        pp.pos = (int)owner + 4;
        req.id = id;
        req.amount = amount;
        req.out = out;
        req.handle = handle;
        FUN_001b9608(&pp.result, owner, &pp.pos, &req);
    }
    return -1;
}
