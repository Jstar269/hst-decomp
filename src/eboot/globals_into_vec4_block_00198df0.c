/* HSTMATCH module=EBOOT.BIN start=0x00198df0 end=0x00198eb4 symbol=FUN_00198df0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/vec.h"

#define BLOCK_INTS 4 /* int words after the three vectors */

/* Block of three vectors followed by four ints. */
typedef struct DefaultBlock {
    Float4 a;               /* 0x00 */
    Float4 b;               /* 0x10 */
    Float4 c;               /* 0x20 */
    int i[BLOCK_INTS];      /* 0x30 */
} DefaultBlock;

extern Float4 DAT_002e185c;
extern Float4 DAT_002e186c;
extern Float4 DAT_002e187c;
extern int DAT_002e188c;
extern int DAT_002e1890;
extern int DAT_002e1894;
extern int DAT_002e1898;

/* Fills the block from the default-value globals. */
void FUN_00198df0(DefaultBlock *block)
{
    block->a = DAT_002e185c;
    block->b = DAT_002e186c;
    block->c = DAT_002e187c;
    block->i[0] = DAT_002e188c;
    block->i[1] = DAT_002e1890;
    block->i[2] = DAT_002e1894;
    block->i[3] = DAT_002e1898;
}
