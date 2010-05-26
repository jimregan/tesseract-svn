/**********************************************************************
 * File:        tessio.h  (Formerly tessread.h)
 * Description: Read/write Tesseract format row files.
 * Author:		Ray Smith
 * Created:		Wed Oct 09 15:02:46 BST 1991
 *
 * (C) Copyright 1991, Hewlett-Packard Ltd.
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 ** http://www.apache.org/licenses/LICENSE-2.0
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 *
 **********************************************************************/

#ifndef           TESSIO_H
#define           TESSIO_H

#include          <stdio.h>
#include          "tessclas.h"
#include          "notdll.h"

TEXTROW *get_tess_row_file(                   //open read & close
                           const char *name,  //file name
                           TPOINT *topright   //corner
                          );
TBLOB *get_tess_blob_file(                   //open read & close
                          const char *name,  //file name
                          TPOINT *topright   //corner
                         );
TEXTROW *readrows(                   //read row file
                  int gphfd,         /*file to read */
                  int count,         /*number expected */
                  TPOINT *imagesize  //size of image
                 );
TWERD *readwords(                   //read some words
                 int gphfd,         /*file to read */
                 int count,         /*number expected */
                 TEXTROW *row,      /*row it comes from */
                 TPOINT *imagesize  /*size of image */
                );
TBLOB *readblobs(                   //read some blobs
                 int gphfd,         /*file to read */
                 int count,         /*number expected */
                 TPOINT *imagesize  /*size of image */
                );
char *readratings(                 //get a string
                  int gphfd,       /*file to read */
                  int ratingspace  /*size to read */
                 );
void readoutlines(                      //read some outlines
                  int gphfd,            /*file to read */
                  TESSLINE **outlines,  /*array of ptrs */
                  int outlinecount      /*no to read */
                 );
int readgph(              //read with testing
            int fd,       /*file to read */
            void *start,  /*buffer to write */
            int size,     /*amount to write */
            int checkeof  /*give error on eof? */
           );
void write_row(              //write  a row
               FILE *name,   //file to write
               TEXTROW *row  /*row to write */
              );
void write_error_row(               //write special row
                     FILE *name,    /*file name */
                     TEXTROW *row,  /*row to write */
                     int wordcount  /*no of words to go */
                    );
void write_error_blob(                 //write special blob
                      FILE *name,      /*file name */
                      TBLOB *blob,     /*blob to write */
                      char *charlist,  /*true chars */
                      int charcount    /*no of true chars */
                     );
void write_error_word(                 //write special word
                      FILE *name,      /*file name */
                      TWERD *word,     /*word to write */
                      char *charlist,  /*true chars */
                      int charcount    /*no of true chars */
                     );
/** 
 * write a blob
 * @param name file to write
 * @param blob blob to write
 */
void writeblob(
               FILE *name,
               TBLOB *blob
              );
/** 
 * serialize
 * @param name file to write to
 * @param blob current blob
 * @param outline current outline
 * @param outlineno current serial no
 */
void serial_outlines(
                     FILE *name,
                     TBLOB *blob,
                     register TESSLINE *outline,
                     int *outlineno
                    );
/** 
 * count loopsize
 * @param vector vectors to count
 */
int countloop(
              register BYTEVEC *vector
             );
/** 
 * get serial no
 * @param outline start of search
 * @param target outline to find
 * @param serial serial no so far
 */
int outlineserial(
                  register TESSLINE *outline,
                  register TESSLINE *target,
                  int serial
                 );
/** 
 * Interface to fwrite 
 * @param name file to write
 * @param start buffer to write
 * @param size amount to write
 */
void writegph(
              FILE *name,
              void *start,
              int size
             );
#endif
