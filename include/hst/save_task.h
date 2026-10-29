/* Object tied to the save menu singleton: vtable word and one owned object at 0x3c. */
#ifndef HST_SAVE_TASK_H
#define HST_SAVE_TASK_H

typedef struct SaveTask {
    const void *vtable;  /* 0x00 */
    char pad04[0x38];
    void *owned;         /* 0x3c deleted through its virtual destructor */
} SaveTask;

#endif
