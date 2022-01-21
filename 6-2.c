/*
    Рекурсивно удалить предпоследнее слово в строке(не используя новую строку).
*/
#include <stdlib.h>
#include <stdio.h>
void delete(char* str, int start, int end) {
	if (str[end] != '\0') {
		str[start] = str[end];
		delete(str, ++start, ++end);
	}
}
int main(void) {
    char* string = (char*)calloc(1, sizeof(char));
    if (!string) return 1;
    int strLen = 0;
    while ((string[strLen] = getchar()) != '\n') {
        string = (char*)realloc(string, ++strLen + 1);
    }
    string[strLen] = '\0';
    puts(string);
    int wordStart = 0; int wordEnd = 0; int i = 0;
    while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			wordStart = wordEnd;
			wordEnd = i;
		}
		i++;
	}
    delete(string, wordStart, wordEnd);
    string = (char*)realloc(string, strLen - wordEnd + wordStart + 1);
	string[strLen - wordEnd + wordStart] = '\0';
    puts(string);
    return 0;
}