/* Resource set of one scene item: its model, collision model, break model and motion. */
#ifndef HST_SCENE_RES_H
#define HST_SCENE_RES_H

#include "hst/types.h"

/* Loaded model object; the data pointer is null when the file failed to load. */
typedef struct SceneModel {
  char pad00[8];
  void *data;                /* 0x08 */
} SceneModel;

typedef struct SceneResSet {
  SceneModel *model;         /* 0x00 item model (.i3r) */
  SceneModel *collision;     /* 0x04 collision model (_col.i3r) */
  SceneModel *breakModel;    /* 0x08 break model (_Break.i3r), may be absent */
  void *motion;              /* 0x0c motion (.i3m) */
} SceneResSet;

#endif
