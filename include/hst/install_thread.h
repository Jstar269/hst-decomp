/* Install helper object that owns a worker thread handle. */
#ifndef HST_INSTALL_THREAD_H
#define HST_INSTALL_THREAD_H

typedef struct InstallThread {
    char pad00[0x28];
    int thread;         /* 0x28: thread handle, negative when not created */
} InstallThread;

#endif
