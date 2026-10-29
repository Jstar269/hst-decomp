/* Ad-hoc file-transfer context (the MatchState that NetCtx.match points at while a file is sent) and its constants. */
#ifndef HST_NET_XFER_H
#define HST_NET_XFER_H

#include "hst/net_adhoc.h"

#define XFER_RECV_SIZE 0x7400       /* bytes read from the file per request */
#define XFER_SEND_SIZE 0x7000       /* bytes handed to the link per send */
#define XFER_TOTAL_UNKNOWN 0x7fffffff /* total size not yet read from the stream header */

/* NetCtx.mode values handled by the net state dispatcher. */
enum {
  NET_MODE_IDLE = 0,
  NET_MODE_BUNDLE_RESET = 3,
  NET_MODE_BUNDLE_READ = 4,
  NET_MODE_XFER_START = 8,      /* leave the session, then set up the transfer */
  NET_MODE_XFER_STOP = 9,       /* leave the session and finish */
  NET_MODE_XFER_RUN = 11
};

/* XferState.phase */
enum { XFER_WAIT_PEER = 0, XFER_SENDING = 1, XFER_FINISHED = 2 };

/* NetCtx result code after a transfer */
enum { XFER_RESULT_OK = 1, XFER_RESULT_FAILED = 2 };

typedef struct XferState {
  unsigned char ready;       /* 0x00 ad-hoc session is up */
  char pad1[3];
  int phase;                 /* 0x04 XFER_* */
  RefObj *link;              /* 0x08 connection object the data is sent through */
  int fd;                    /* 0x0c open file descriptor, -1 when closed */
  int sent;                  /* 0x10 bytes sent so far */
  unsigned char canSend;     /* 0x14 link accepted the last chunk */
  unsigned char firstSend;   /* 0x15 no chunk sent yet */
  unsigned char done;        /* 0x16 whole file sent */
  unsigned char failed;      /* 0x17 */
  unsigned char aborted;     /* 0x18 */
  char pad19[3];
  RefObj *ring;              /* 0x1c ring buffer between file reads and sends */
  char recvBuf[XFER_RECV_SIZE]; /* 0x20 */
  int recvLen;               /* 0x7420 bytes in recvBuf */
  char sendBuf[XFER_SEND_SIZE]; /* 0x7424 */
  int chunk;                 /* 0xe424 bytes taken from the ring for the next send */
  char spillBuf[XFER_RECV_SIZE]; /* 0xe428 data the ring could not take yet */
  char *spillPtr;            /* 0x15828 next unwritten byte of spillBuf */
  int spillLeft;             /* 0x1582c bytes still to push into the ring */
  int total;                 /* 0x15830 file size, XFER_TOTAL_UNKNOWN until read */
  int idle;                  /* 0x15834 frames spent with nothing left to send */
  int error;                 /* 0x15838 link error code */
} XferState;

#endif
