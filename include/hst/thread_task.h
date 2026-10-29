/* Task object that owns a kernel thread: a stored position, the thread handle and the key used to create it. */
#ifndef HST_THREAD_TASK_H
#define HST_THREAD_TASK_H

typedef struct ThreadTask {
    char pad0[4];
    int unk4;       /* 0x04 */
    float pos[3];   /* 0x08: copied from the caller's vector */
    int thread;     /* 0x14: thread handle, -1 once deleted */
    int key;        /* 0x18: first argument of the thread-create call */
} ThreadTask;

#endif
