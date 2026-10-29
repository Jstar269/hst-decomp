/* HSTMATCH module=EBOOT.BIN start=0x0010ba20 end=0x0010bc70 symbol=FUN_0010ba20 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: the two sound-mask objects are volatile (unused second word kept in memory) and the inline helper takes a plain struct pointer. */
#include "hst/types.h"
#include "hst/mode_list.h"

/* Pad button masks of the two cursor directions (orient 1: up/down, otherwise left/right). */
#define BUTTON_UP 0x10
#define BUTTON_RIGHT 0x20
#define BUTTON_DOWN 0x40
#define BUTTON_LEFT 0x80
#define KEY_REPEAT_WINDOW 2
#define KEY_REPEAT_LIMIT 9

/* Button mask pair for one direction; both words are always written. */
struct Snd {
    int mask;               /* 0x00 */
    int alt;                /* 0x04 */
};

extern void *DAT_002cfc8c;  /* pad state */
extern void FUN_0001e23c(void *p, int a, int b);
extern int FUN_0001ea64(void *p, void *key, int mask, int n, int m);

/* True while the direction's button is held (with key repeat tracked in `key`). */
static inline int Play(void *p, int *key, struct Snd *snd)
{
    return FUN_0001ea64(p, key, snd->mask, KEY_REPEAT_WINDOW, KEY_REPEAT_LIMIT);
}

/* Step `cursor` back or forward on a pad press (wrapping when `wrap` is set); returns 1 when it moved. */
int FUN_0010ba20(ModeList *self, int *cursor, int count, int wrap)
{
    ModeItem *item;
    int idx;
    int mode;
    int result = 0;
    volatile struct Snd down, up;

    mode = self->mode;
    idx = self->first;
    switch (mode) {
    case 1:
        item = self->items[idx];
        break;
    case 2:
        item = *(ModeItem **)((char *)self->items + (idx + 2) * 4);
        break;
    case 0:
    default:
        item = *(ModeItem **)((char *)self->items + (idx + 1) * 4);
        break;
    }
    if ((item->flags & MODE_ITEM_LOCKED) != 0)
        return 0;
    if (self->orient == 1) {
        down.mask = BUTTON_UP;
        down.alt = BUTTON_UP << 12;
        up.mask = BUTTON_DOWN;
        up.alt = BUTTON_DOWN << 12;
    } else {
        down.mask = BUTTON_LEFT;
        down.alt = BUTTON_LEFT << 12;
        up.mask = BUTTON_RIGHT;
        up.alt = BUTTON_RIGHT << 12;
    }
    if (Play(DAT_002cfc8c, &self->keys[4], (struct Snd *)&down) != 0) {
        if (wrap != 0) {
            *cursor = (*cursor - 1 + count) % count;
            result = 1;
        } else {
            if (*cursor > 0) {
                *cursor = *cursor - 1;
                result = 1;
            }
        }
        if (*cursor == 0) {
            FUN_0001e23c(DAT_002cfc8c, BUTTON_LEFT, 1);
            FUN_0001e23c(DAT_002cfc8c, BUTTON_LEFT, 1);
        }
    } else if (Play(DAT_002cfc8c, &self->keys[6], (struct Snd *)&up) != 0) {
        if (wrap != 0) {
            *cursor = (*cursor + 1) % count;
            result = 1;
        } else {
            if (*cursor < count - 1) {
                *cursor = *cursor + 1;
                result = 1;
            }
        }
        if (*cursor == count - 1) {
            FUN_0001e23c(DAT_002cfc8c, BUTTON_RIGHT, 1);
            FUN_0001e23c(DAT_002cfc8c, BUTTON_RIGHT, 1);
        }
    }
    return result;
}
