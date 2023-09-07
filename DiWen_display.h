#ifndef _DiWen_display_h
#define _DiWen_display_h

void myDisplayFace(Uart_type *uart_use, unsigned char face);
void myDisplayPicture(Uart_type *uart_use, bit Attribute, uint x, uint y, uchar Picture);
void myDisplayIcon(Uart_type *uart_use, uint x, uint y, uchar Lib_ID, uchar mode, uint Icon_ID);
void myDisplayString(Uart_type *uart_use, uint x, uint y, uchar Lib_ID, uchar mode,
                     uchar Dots, uint Fcolor, uint Bcolor, char *Strings, ...) reentrant;
void myDiWinBuzz(Uart_type *uart_use, uchar length);

#endif

// extern unsigned int code PictureData[][5];