/*
 * References:
 *  [1.] Buffer close, http://marknelson.us/1989/10/01/lzw-data-compression/
 *  [2.] StackOverflow Bug, http://stackoverflow.com/questions/1833437/lzw-decompression-in-c/1833584#1833584
 *  [3.] String+Char+String+Char+String Exception, http://michael.dipperstein.com/lzw/
 *  [4.] Bitwise Operations, http://www.fredosaurus.com/notes-cpp/expressions/bitops.html
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithms.c" // LZW compression

FILE *inputFile;
FILE *outputFile;

int main(int argc, char** argv) { // number of arguments, arguments array
    // do we have correct # of arguments?
    if (argc > 2) {
        if (strcmp(argv[1], "c") == 0) { // compression 
            inputFile = fopen(argv[2], "r"); // read from the input file (HTML)
            outputFile = fopen(strcat(argv[2], ".lzw"), "w+b"); // binary write to output file 
            
            if (outputFile == NULL || inputFile == NULL) {
                printf("Can't open files\n'"); return 0;
            }
            
            compress(inputFile, outputFile);
        } else { // decompression
            inputFile = fopen(argv[2], "rb"); // binary read from the input file

            char temp[20]; int length = strlen(argv[2])-4;
            strncpy(temp, argv[2], length);
            temp[length] = '\0';
            outputFile = fopen(temp, "w"); // write to output file (HTML)
            
            if (outputFile == NULL || inputFile == NULL) {
                printf("Can't open files\n'"); return 0;
            }
            
            decompress(inputFile, outputFile);
        }
        
        fclose(inputFile); fclose(outputFile); // close handles
    } else {
        // usage
        printf("LZW 0.7   (c) 2009 Radek Stepan   03 Dec 2009\n\n");
        printf("Usage:    lzw <command> <input file>\n\n");
        printf("<Commands>\n  c       Compress\n  d       Decompress\n");
    }
    
    return 0;
}
