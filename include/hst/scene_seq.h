/* Scene sequence record: the pending sequence id, the previous id and the change-pending flag. */
#ifndef HST_SCENE_SEQ_H
#define HST_SCENE_SEQ_H

typedef struct SceneSeq {
  char pad0[0x9c0];
  int next;                         /* 0x9c0 requested sequence id */
  int prev;                         /* 0x9c4 id that was current before the request */
  unsigned char change;             /* 0x9c8 set while a change is pending */
} SceneSeq;

#endif
