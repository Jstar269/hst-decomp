/* Service object owned by the global holder that the PsmfPlayerMaterial player constructs. */
#ifndef HST_PLAYER_SERVICE_H
#define HST_PLAYER_SERVICE_H

/* Embedded sub-object: vtable, then a handle that is -1 when unused. */
typedef struct ServiceSock {
    unsigned int vtable;    /* 0x00 */
    char pad04[16];
    int handle;             /* 0x14 */
    char pad18[4];
} ServiceSock;

typedef struct PlayerService {
    char pad00[0x28];
    unsigned char ready;    /* 0x28: set once the service is running */
    unsigned char unk29;    /* 0x29 */
    unsigned char unk2a;    /* 0x2a */
    char pad2b;
    void *unk2c;            /* 0x2c */
    void *unk30;            /* 0x30 */
    ServiceSock a;          /* 0x34 */
    ServiceSock b;          /* 0x50 */
    ServiceSock c;          /* 0x6c */
    int pipe;               /* 0x88: handle the stop request is sent through */
    int req_cmd;            /* 0x8c: start of the 0x48-byte request block */
    int req_arg;            /* 0x90 */
    unsigned char req_flag; /* 0x94 */
    char pad95[0xdc - 0x95];
    int unkdc;              /* 0xdc */
    int unke0;              /* 0xe0 */
    int unke4;              /* 0xe4 */
    int unke8;              /* 0xe8 */
    char padec[0x1f0 - 0xec];
} PlayerService;

typedef struct ServiceHolder {
    PlayerService *service; /* 0x0 */
} ServiceHolder;

enum { PLAYER_SERVICE_SIZE = 0x1f0, SERVICE_REQUEST_SIZE = 0x48 };

#endif
