/* Object of the 0xf2000 sources: a target value that is graded by its distance from a base value (levels 1, 2, 4). */
#ifndef HST_GRADED_OBJ_H
#define HST_GRADED_OBJ_H

#include "hst/types.h"

#define GRADE_LEVEL_SMALL 1
#define GRADE_LEVEL_MEDIUM 2
#define GRADE_LEVEL_LARGE 4
#define GRADE_DISTANCE_MEDIUM 30   /* distances at or above this give at least the medium level */
#define GRADE_DISTANCE_LARGE 100   /* distances at or above this give the large level */

typedef struct GradedObj {
  char pad00[0x68];
  int unk68;          /* 0x68 passed to the refresh helper with unk78 */
  char pad6c[4];
  int unk70;          /* 0x70 */
  float unk74;        /* 0x74 */
  int unk78;          /* 0x78 base value */
  int target;         /* 0x7c value last requested */
  int level;          /* 0x80 grade of the last change */
  u8 enabled;         /* 0x84 the updates do nothing while this is zero */
} GradedObj;

#endif
