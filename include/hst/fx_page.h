/* Page object whose effect sub-object and tint bytes two effect handlers read. */
#ifndef HST_FX_PAGE_H
#define HST_FX_PAGE_H

typedef struct FxPage {
  char pad00[0x928];
  char fx[0x20];            /* 0x928 effect sub-object passed to the effect helpers */
  int fx_arg;               /* 0x948 */
  char pad94c[0x998 - 0x94c];
  unsigned char tint_r;     /* 0x998 */
  char pad999;
  unsigned char tint_g;     /* 0x99a */
  char pad99b;
  unsigned char tint_b;     /* 0x99c */
  char pad99d;
  unsigned char tint_a;     /* 0x99e */
} FxPage;

#endif
