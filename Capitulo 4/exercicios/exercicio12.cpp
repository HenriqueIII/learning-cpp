#include <iostream>

const char * strpbrk(const char *, const char*);

const char * strpbrk(const char *s1, const char *s2){
    char * pt;
    if (s1)
        pt = (char*)s1;

    for (;*pt!='\0';*pt++)
        for (int i=0;s2[i]!='\0';++i)
            if (*pt==s2[i]){
                char * tmp = pt;
                *pt++;
                return tmp;
            }

    return NULL;
}
int main (){
  char str[] = "This is a sample string";
  char key[] = "aeiou";
  std::cout << "Vowels in " << str << ": ";
  const char * pch=strpbrk(str, key);
  while(pch != NULL){
        std::cout << *pch;
        pch=strpbrk(pch+1, key);
  }
  std::cout << std::endl;
  return 0;
}
