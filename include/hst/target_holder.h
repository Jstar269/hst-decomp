/* Object that owns a 0x20-byte target record and mirrors four floats into it. */
#ifndef HST_TARGET_HOLDER_H
#define HST_TARGET_HOLDER_H

#define TARGET_REC_SIZE 0x20 /* bytes allocated for the record */

typedef struct TargetRec {
  char pad[0x10];
  float unk10;       /* 0x10 */
  float unk14;       /* 0x14 */
  float unk18;       /* 0x18 */
  float unk1c;       /* 0x1c */
} TargetRec;         /* size 0x20 */

typedef struct TargetHolder {
  char pad[0x564];
  TargetRec *rec;    /* 0x564 owned record, recreated on reset */
  unsigned char unk568; /* 0x568 set to 1 by the reset */
  char pad569[7];
  float unk570;      /* 0x570 mirrored into rec->unk10 */
  float unk574;      /* 0x574 */
  float unk578;      /* 0x578 */
  float unk57c;      /* 0x57c */
  float unk580;      /* 0x580 cleared by the reset, added to unk574 for rec->unk14 */
} TargetHolder;

#endif
