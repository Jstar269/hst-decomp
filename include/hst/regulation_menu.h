/* Regulation menu object: its layout, the pane table, the unit list widget and nine animators. */
#ifndef HST_REGULATION_MENU_H
#define HST_REGULATION_MENU_H

#include "hst/types.h"
#include "hst/animator.h"
#include "hst/result_screen.h"

/* Number of panes in the table built from the layout. */
#define REGULATION_PANE_COUNT 10

/* Number of units in the unit list. */
#define REGULATION_UNIT_COUNT 0x4e

/* Number of animators at the end of the object. */
#define REGULATION_ANIM_COUNT 9

typedef struct RegulationMenu {
    char pad00[4];
    void *layout;                           /* 0x04 owned layout, deleted through its virtual destructor */
    void *panes[REGULATION_PANE_COUNT];     /* 0x08 */
    char list30[0x53c];                     /* 0x30 unit list widget */
    void *unk56c;                           /* 0x56c pointer inside the unit list widget */
    char pad570[0xc4];
    void *unk634;                           /* 0x634 pointer inside the unit list widget */
    char pad638[0x10];
    char widget648[0x9c];                   /* 0x648 */
    char widget6e4[0x24];                   /* 0x6e4 */
    ResultObj *obj708;                      /* 0x708 widget handle that is tweaked right after creation */
    char pad70c[0xc];
    Animator anims[REGULATION_ANIM_COUNT];  /* 0x718 */
} RegulationMenu;

#endif
