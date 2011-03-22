typedef struct{
    int prefix; // prefix for byte > 255
    int character; // the last byte of the string
} DictElement;

void dictionaryArrayAdd(int prefix, int character, int value);
int dictionaryArrayPrefix(int value);
int dictionaryArrayCharacter(int value);

DictElement dictionaryArray[4095];

// add prefix + character to the dictionary
void dictionaryArrayAdd(int prefix, int character, int value) {
    dictionaryArray[value].prefix = prefix;
    dictionaryArray[value].character = character;
}

int dictionaryArrayPrefix(int value) {
    return dictionaryArray[value].prefix;
}

int dictionaryArrayCharacter(int value) {
    return dictionaryArray[value].character;
}
