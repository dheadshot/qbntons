# Tone1 Library
This is the library that the NoteStruct array slots into.

The library is a modified version of an old Arduino "Tone" library originally written by Brett Hagman.  As such, this section is not covered by the MIT licence and is instead the GPLv3 licence, with some public-domain additions of my own.

## How to use the library
The library uses the `PlayControl` structure to manage playing the notes, an array of `NoteStruct` structures to store the notes and the `Tone1` object to play each note.  You should set up your `PlayControl` structure with a reference to the start of the `NoteStruct` array and a reference to your `Tone1` object.

Use the functions and the `PlayControl` structure in `playext.h` to control the playing of the notes.  To start playing at the beginning, first call `void ResetPlaying(PlayControl *NoteCont)`, then set the `playing` member of your `PlayControl` structure to `true`.  You will need to keep calling `void PlayCheck(PlayControl *NoteCont)`, so it may be worth putting it in a timed interrupt, otherwise just stick it in your loop function.  To stop playing at any point, call `void StopPlaying(PlayControl *NoteCont)` and to continue set the `playing` member of your `PlayControl` structure to `true`.  Be sure your `NoteStruct` structure array ends with a `{0,0}`.
