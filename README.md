# qbntons
Converts notes from the QBasic "PLAY" command to an array of "NoteStruct" notes for the Arduino.

## NoteStruct Array
The "NoteStruct" structure is provided by the Tone1 library.  See the tonelib folder for the files.

## PLAY Command Notes
If you don't have experience with the QBasic "PLAY" command, or if you do but find it easier to compose as you go, you can use my "PLYR.EXE" program - download [here] (http://gopher.floodgap.com/gopher/gw?gopher://qselfgnk.ddns.net:70/9/DBPub/Software/PLYR.EXE).  Obtain information about the PLYR commands by pressing `?` while PLYR is running, or get information about the program itself [here] (http://gopher.floodgap.com/gopher/gw?gopher://qselfgnk.ddns.net:70/1/DBPub/Software/files.lst).  You can run PLYR within DosBox if you don't have a compatible computer (you probably won't! ;-) ).

*UPDATE:* I have now included an archive containing PLYR in the plyr folder of this repository.

## Compilation
Compiles with any version of GCC (including Xcode).  Just run `gcc -c qbntons.c` followed by either `gcc qbntons.o -o qbntons.exe` (for Windows) or `gcc qbntons.o -o qbntons` then `chmod +x qbntons` (for macOS and Linux).

## Execution
Simply run `qbntons TheSongFile.SNG > theoutput.h`.  The output file should be a header file you can include in your Arduino project.

## Example
See the Example folder for a usage example
