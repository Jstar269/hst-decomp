/* Match configuration object: a flag byte and a value word read by the shot-power sources. */
#ifndef HST_MATCH_CFG_H
#define HST_MATCH_CFG_H

typedef struct MatchCfg {
  char pad00[0x45];
  unsigned char flag45;   /* 0x45 */
  char pad46[0x90 - 0x46];
  int value90;            /* 0x90 */
} MatchCfg;

#endif
