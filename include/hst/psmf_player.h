/* PSMF player manager object (same object as PlayerService, with the fields the control functions use). */
#ifndef HST_PSMF_PLAYER_H
#define HST_PSMF_PLAYER_H

#include "hst/player_service.h"

/* Request block sent through the player's message pipe (SERVICE_REQUEST_SIZE bytes). */
typedef struct PsmfMsg {
  int type;       /* 0x00 PSMF_MSG_* */
  int arg;        /* 0x04 */
  char data[64];  /* 0x08 */
} PsmfMsg;

enum {
  PSMF_MSG_STOP = 0,   /* stop playback */
  PSMF_MSG_START = 1,  /* start playback of the file named in data */
  PSMF_STATUS_INIT = 1,     /* player status values */
  PSMF_STATUS_STANDBY = 2,
  PSMF_STATUS_PLAYING = 4,
  PSMF_STATUS_FINISHED = 0x200,
  PSMF_WORK_SIZE = 0x88000, /* size of the work buffer cleared before a request */
  PSMF_POLL_DELAY = 1000,   /* delay between status polls */
  PSMF_IDLE_DELAY = 33000   /* delay between message-pipe polls */
};

typedef struct PsmfPlayer {
  char pad00[0x10];
  int video_codec;          /* 0x10 playback parameter block passed to the start call */
  int video_stream_num;     /* 0x14 */
  int audio_codec;          /* 0x18 */
  int audio_stream_num;     /* 0x1c */
  int play_mode;            /* 0x20 */
  int play_speed;           /* 0x24 */
  unsigned char ready;      /* 0x28 set once the player is initialised */
  unsigned char started;    /* 0x29 set once playback was started */
  unsigned char closing;    /* 0x2a set when the manager thread should leave */
  char pad2b;
  unsigned int work_buf;    /* 0x2c address of the PSMF_WORK_SIZE-byte work buffer */
  int unk30;                /* 0x30 */
  ServiceSock a;            /* 0x34 */
  ServiceSock b;            /* 0x50 */
  ServiceSock c;            /* 0x6c */
  int pipe;                 /* 0x88 message pipe handle */
  PsmfMsg msg;              /* 0x8c request block */
  char padd4[0xe8 - 0xd4];
  int unke8;                /* 0xe8 */
  char unkec[4];            /* 0xec */
} PsmfPlayer;

#endif
