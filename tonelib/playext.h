#ifndef __PLAYEXT_H__
#define __PLAYEXT_H__

#include "Tone1.h"

typedef struct _NoteStruct {
  uint16_t frequency;
  uint32_t duration;
} NoteStruct;

typedef struct _PlayControl {
  NoteStruct *notearref;
  Tone1 *toneref;
  bool playing;
  uint16_t playpos;
} PlayControl;

void StopPlaying(PlayControl *NoteCont);
void ResetPlaying(PlayControl *NoteCont);
void PlayCheck(PlayControl *NoteCont);  //Call this repeatedly!

#endif
