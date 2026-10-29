/* Localised text bank returned by FUN_0018c9f4(bank id): groups of strings looked up by (group, index). */
#ifndef HST_TEXT_BANK_LOOKUP_H
#define HST_TEXT_BANK_LOOKUP_H

#ifdef __cplusplus
extern "C" {
#endif
/* Strings returned instead of text when the bank is not loaded / the group is out of range / the index is. */
extern char DAT_002c0e20[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e18[];
#ifdef __cplusplus
}
#endif

/* Bank ids and groups used by the dialog-message sources. */
enum { TEXT_BANK_MESSAGES = 0x11, TEXT_GROUP_ADHOC = 14 };

typedef struct TextHeader {
  int pad0;
  int pad4;
  int groupCount;               /* 0x08 */
} TextHeader;

typedef struct TextGroup {
  const char **strings;         /* 0x00 */
  int count;                    /* 0x04 number of strings */
  int pad8;
} TextGroup;                    /* size 0x0c */

typedef struct TextBank {
  int pad0;
  int loaded;                   /* 0x04 zero until the bank is loaded */
  TextHeader *header;           /* 0x08 */
  TextGroup *groups;            /* 0x0c */
} TextBank;

/* Same lookup as the out-of-line FUN_0018f1ac. */
static inline const char *TextGet(TextBank *bank, int group, int index)
{
  if (bank->loaded == 0)
    return DAT_002c0e20;
  if (group < 0 || group >= bank->header->groupCount)
    return DAT_002c0e1c;
  if (index < 0 || index >= bank->groups[group].count)
    return DAT_002c0e18;
  return bank->groups[group].strings[index];
}

#endif
