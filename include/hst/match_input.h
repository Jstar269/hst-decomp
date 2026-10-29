/* Per-frame input/decision object: the fields the match input update reads and writes. */
#ifndef HST_MATCH_INPUT_H
#define HST_MATCH_INPUT_H

typedef struct MatchInput {
  char pad00[0x58];
  int unk58;                    /* 0x58 copied into a global after the helper clears unk79 */
  char pad5c[0x79 - 0x5c];
  unsigned char unk79;          /* 0x79 */
  unsigned char unk7a;          /* 0x7a */
  unsigned char unk7b;          /* 0x7b checked together with the mode */
  unsigned char unk7c;          /* 0x7c */
  int unk80;                    /* 0x80 chosen value, -1 when none */
  char pad84[0x8c - 0x84];
  unsigned char unk8c;          /* 0x8c */
  char pad8d[0x94 - 0x8d];
  unsigned char unk94;          /* 0x94 */
  unsigned char unk95;          /* 0x95 */
} MatchInput;

#endif
