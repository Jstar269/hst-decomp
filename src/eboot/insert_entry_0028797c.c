/* HSTMATCH module=EBOOT.BIN start=0x0028797c end=0x002879e0 symbol=FUN_0028797c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: callee-analyzed 24-byte record layout, branch polarity, stack frame alignment; readability pass; exact match verified; names and types await human review. */
#include "hst/request_queue.h"

extern char DAT_0034179c[];

extern int FUN_001b2af0(void *p);
extern void FUN_00289544(void *buf, void *queue, void *pos, void *rec);

enum { REQ_TYPE_4C = 0x4c }; /* request kind, named by its hex value */

/* With a count of 0 or less store the result of the global's query at +0x4c; otherwise queue a request. */
void FUN_0028797c(RequestOwner *self, int value, int count)
{
    RequestRec rec;
    void *result;
    void *sentinel;

    if (count <= 0) {
        self->unk4c = FUN_001b2af0(&DAT_0034179c);
    } else {
        rec.type = REQ_TYPE_4C;
        rec.count = count;
        rec.arg8 = value;
        sentinel = &self->queue.sentinel;
        FUN_00289544(&result, &self->queue, &sentinel, &rec);
    }
}
