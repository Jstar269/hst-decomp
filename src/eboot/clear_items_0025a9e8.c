/* HSTMATCH module=EBOOT.BIN start=0x0025a9e8 end=0x0025aa90 symbol=FUN_0025a9e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct, delete argument, buffer order, if/else and loop control flow; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/block_deque.h"

extern void FUN_00000a00(void *p);
extern void FUN_0025a678(void *p, void *a, void *b);
extern void FUN_0025a80c(void *buf, void *p, int x);
extern void FUN_0025ab10(void *p);

#define BLOCK_ELEMS 128   /* elements per block */

/* Empty a block deque: destroy all elements, free the surplus blocks and recentre the first-element index. */
void FUN_0025a9e8(BlockDeque *deque)
{
    BlockDequePos begin;
    BlockDequePos end;

    FUN_0025a80c(&end, deque, deque->length);
    FUN_0025a80c(&begin, deque, 0);
    FUN_0025a678(deque, &begin, &end);
    deque->length = 0;
    if ((u32)deque->map.count > 1) {
        while ((u32)deque->map.count > 2) {
            FUN_00000a00(deque->map.blocks[deque->map.head]);
            FUN_0025ab10(deque);
        }
        deque->first = BLOCK_ELEMS / 2;
    } else {
        deque->first = 0;
    }
}
