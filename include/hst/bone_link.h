/* Bone-pair sub-object of the model-set owner: a cleared block and two bone names. */
#ifndef HST_BONE_LINK_H
#define HST_BONE_LINK_H

#include "hst/types.h"

#define BONE_LINK_CLEAR_WORDS 8 /* words cleared by the constructor before the names */

typedef struct BoneLink {
  u32 unk00[BONE_LINK_CLEAR_WORDS]; /* 0x00 */
  const char *nameA;                /* 0x20 first bone name */
  const char *nameB;                /* 0x24 second bone name */
} BoneLink;

#endif
