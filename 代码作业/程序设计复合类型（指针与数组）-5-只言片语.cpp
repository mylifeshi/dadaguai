#include <iostream>
#define MAX_STR_LENGTH 100
using namespace std;

void print_merged(const char(*str)[MAX_STR_LENGTH])
{
    /****************** TODO ******************/
    const char* p1 =str[0];
    const char* p2 =str[1];
    bool f =true;
    while(*p1!='\0'||*p2!='\0'){
        if(*p1!='\0'){
            while(*p1==' ')p1++;
            const char* start =p1;
            while(*p1!=' '&&*p1!='\0')p1++;
            if(start!=p1){
                if(!f)cout<<" ";
                f=false;
                for(const char*q=start;q<p1;++q)cout<<*q;
            }
        }
        if(*p2!='\0'){
            while(*p2==' ')p2++;
            const char* start = p2;
            while(*p2!=' '&&*p2!='\0')p2++;
            if(start!=p2){
                if(!f)cout<<" ";
                f=false;
                for(const char*q=start;q<p2;++q)cout<<*q;
            }
        }
    }
    /**************** TODO-END ****************/
}

int main()
{
    char str[2][MAX_STR_LENGTH] = {};

    cin.getline(str[0], MAX_STR_LENGTH);
    cin.getline(str[1], MAX_STR_LENGTH);

    print_merged(str);
  
    return 0;
}