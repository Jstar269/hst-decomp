/* HSTMATCH module=EBOOT.BIN start=0x00225c40 end=0x00225d40 symbol=FUN_00225c40 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/mode_parts.h"

#define LINK_COUNT 2
#define MODE_PART10_CMD 0xe /* forward the vector to the +0x10 part */
#define MODE_PART18_RESET 0xf /* reset the +0x18 part's links */

typedef struct { float x, y, z, w; } Vec4;
struct ModePart18 {
    char pad00[0x68];
    ModeNode *links[LINK_COUNT]; /* 0x68 */
    char pad70[0xb4 - 0x70];
    float unkb4; /* 0xb4 */
    float unkb8; /* 0xb8 */
};
typedef struct ModePart18 ModePart18;
extern void FUN_00103480(ModePart18 *);
extern void FUN_0021bf24(void *, int, int);
extern void FUN_0021f7e0(void *, int, Vec4);
extern void FUN_00222bb8(ModePart18 *, int, int);

/* Dispatch a mode request to the part that handles it. */
void FUN_00225c40(ModeObj *self, int mode, int arg, Vec4 v)
{
    if (mode == MODE_PART10_CMD) {
        FUN_0021f7e0(self->parts->part10, arg, v);
    } else if (mode == MODE_PART18_RESET) {
        int i = 0;
        ModePart18 *part = self->parts->part18;
        part->unkb4 = -74.0f;
        part->unkb8 = 0.0f;
        do {
            if (part->links[i] != 0 && i == 0) {
                part->links[i]->x = part->unkb4;
                part->links[i]->y = part->unkb8;
            }
            i++;
        } while (i < LINK_COUNT);
        FUN_00103480(part);
        FUN_00222bb8(self->parts->part18, arg, 0);
    } else {
        FUN_0021bf24(self->parts->part0c, mode, arg);
    }
}
