#include <iostream>


bool isSubStr(char* s1, char* s2)
{
	if (s1 == nullptr || s2 == nullptr)
		return false;
	if (s2[0] == '\0')
		return true;
	if (s2[0] == '\0')
		return false;
	int i = 0;

    for (int i = 0; s1[i] != '\0'; ++i) {
        int k = 0;
        while (s1[k + i] != '\0' && s2[k] != '\0' && s2[k] == s1[k + i])
            k++;
        if (s2[k] == '\0')
            return true;
    }
}
