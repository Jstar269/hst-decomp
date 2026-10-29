/* Install flow object: a part handle, a pane pointer and the mode word that the install screen switches. */
#ifndef HST_INSTALL_FLOW_H
#define HST_INSTALL_FLOW_H

enum {
  INSTALL_MODE_IDLE = 0,       /* nothing to do */
  INSTALL_MODE_RUN = 1         /* page is being driven */
};

/* The part the flow drives each frame; only its flag byte is named. */
typedef struct InstallPart {
  char pad00[0x24];
  unsigned char active;        /* 0x24 non-zero while the part is in use */
} InstallPart;

/* Pane object; only the word the mode switch writes is named. */
typedef struct InstallPane {
  char pad00[0x30];
  int unk30;                   /* 0x30 */
} InstallPane;

typedef struct InstallFlow {
  const void *vtable;          /* 0x00 */
  char pad04[0x3c - 4];
  InstallPart *part;           /* 0x3c */
  char pad40[0x70 - 0x40];
  InstallPane *pane;           /* 0x70 */
  char pad74[0x7c - 0x74];
  int mode;                    /* 0x7c */
} InstallFlow;

#endif
