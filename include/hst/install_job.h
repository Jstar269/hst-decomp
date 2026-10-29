/* Layout of the install job object (allocated by its constructor, driven by SetState). */
#ifndef HST_INSTALL_JOB_H
#define HST_INSTALL_JOB_H

enum {
  INSTALL_JOB_SIZE = 0xeb48,        /* allocation size of the object */
  INSTALL_NAME_SIZE = 0x180,        /* bytes in each text buffer */
  INSTALL_WORK_SIZE = 0x200000,     /* work buffer allocated by the constructor */
  INSTALL_NONE = -1,                /* "no thread / no file" handle value */
  INSTALL_UNSET = 0x7fffffff        /* limit fields before they are known */
};

typedef struct InstallJob {
  int state;                          /* 0x00 */
  int unk04;                          /* 0x04, work buffer */
  int unk08;                          /* 0x08 */
  int unk0c;                          /* 0x0c */
  int unk10;                          /* 0x10 */
  int unk14;                          /* 0x14 */
  int unk18;                          /* 0x18 */
  int unk1c;                          /* 0x1c */
  unsigned char unk20;                /* 0x20 */
  unsigned char unk21;                /* 0x21 */
  char pad22[2];
  int thread;                         /* 0x24 */
  char name[INSTALL_NAME_SIZE];       /* 0x28 */
  char msg[INSTALL_NAME_SIZE];        /* 0x1a8 */
  int timer;                          /* 0x328 */
  int fd;                             /* 0x32c */
  unsigned char async;                /* 0x330 */
  unsigned char unk331;               /* 0x331 */
  char pad332[2];
  int unk334;                         /* 0x334 */
  char pad338[0x7738 - 0x338];
  int unk7738;                        /* 0x7738 */
  char pad773c[0xeb3c - 0x773c];
  int unkeb3c;                        /* 0xeb3c */
  int unkeb40;                        /* 0xeb40 */
  int lang;                           /* 0xeb44 */
} InstallJob;

#endif
