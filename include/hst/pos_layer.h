/* Sub-layout of a layout pane: a polymorphic object (virtual slot 1 shows or hides it) with a float position at 0x60. */
#ifndef HST_POS_LAYER_H
#define HST_POS_LAYER_H

#ifdef __cplusplus
struct PosLayer {
  virtual void slot0();
  virtual void set_hidden(int hidden); /* slot 1 */
  char pad04[0x5c];
  float x;                             /* 0x60 */
  float y;                             /* 0x64 */
};
#else
typedef struct PosLayer {
  void *vtable;                        /* 0x00 */
  char pad04[0x5c];
  float x;                             /* 0x60 */
  float y;                             /* 0x64 */
} PosLayer;
#endif

#endif
