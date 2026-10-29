/* Ad-hoc PTP link object (worker thread, semaphore, shared cells and two byte queues) and its queue type. */
#ifndef HST_PTP_LINK_H
#define HST_PTP_LINK_H

#define PTP_QUEUE_CAPACITY 0x10000 /* byte capacity both queues are created with */

/* Byte queue (20 bytes); the number of queued bytes is tail - head. */
#ifdef __cplusplus
struct PtpQueue {
  virtual ~PtpQueue();
  int unk4;
  int unk8;
  int head;  /* 0x0c */
  int tail;  /* 0x10 */
};
#else
typedef struct PtpQueue {
  const void *vtable;  /* 0x00 */
  int unk4;
  int unk8;
  int head;  /* 0x0c */
  int tail;  /* 0x10 */
} PtpQueue;
#endif

typedef struct PtpLink {
  const void *vtable;       /* 0x00 */
  int thread_id;            /* 0x04 worker thread, -1 when none */
  int sema_id;              /* 0x08 semaphore, -1 when none */
  short *shared_short;      /* 0x0c cell shared with the worker thread */
  char *stop_flag; /* 0x10 cell shared with the worker thread; set before the thread is stopped */
  PtpQueue *write_queue;    /* 0x14 data is appended here */
  PtpQueue *read_queue;     /* 0x18 data is taken from here */
} PtpLink;

#endif
