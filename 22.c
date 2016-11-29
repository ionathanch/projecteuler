/*
   Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

   For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

   What is the total of all the name scores in the file?
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// returns true if str1 comes before str2
// or if str1 == str2
bool string_compare (char* str1, char* str2) {
    int index = 0;
    while (str1[index] != '\0' && str2[index] != '\0') {
        if (str1[index] < str2[index])
            return true;
        else if (str1[index] > str2[index])
            return false;
        else
            index++;
    }
    return true;
}

// returns the sum of the value of the chars
// where a = 1, b = 2, etc. 
int name_value (char* name) {
    int value = 0;
    int index = 0;
    while (name[index] != '\0') {
        value += name[index++] - 64;
    }
    return value;
}

void insert (char** string_array, char* string, int index) {
    if (string == NULL) {
        string_array[index] = NULL;
        return;
    }

    char* temp = string_array[index];
    string_array[index++] = string;
    return insert (string_array, temp, index);
}

void sort_strings (char** in, char** out) {
    int in_index = 0;
    while (in[in_index] != NULL) {
        char* in_string = in[in_index++];
        int out_index = 0;
        while (out[out_index] != NULL) {
            char* out_string = out[out_index];
            printf("%s, %s\n", in_string, out_string);
            if (string_compare(in_string, out_string))
                insert (out, in_string, out_index);
            else 
                out_index++;
        }
    }
}

int main (int argc, char* argv[]) {
    char* in[6];
    in[6] = NULL;
    char* out[6];
    out[0] = NULL;

    for (int i = 1; i < argc; i++) {
        in[i - 1] = argv[i];
    }

    for (int i = 0; i < 6; i++) {
        printf("%s\n", in[i]);
    }

    sort_strings(in, out);

    for (int i = 0; i < 5; i++) {
        printf("%s\n", out[i]);
    }
}
