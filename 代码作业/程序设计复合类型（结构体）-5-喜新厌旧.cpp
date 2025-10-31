#include<iostream>
#include<string>
using namespace std;
string key;
int n,tc;
struct book{
    string name,author;
    int page;
    int last_read_time;
};
int main(){
    const int MAX_B = 10;  
    book shelf[MAX_B+1];     
    while(1){
        tc++;
        cin>>key;
        if(key=="quit")break;
        if(key=="put"){
            string name,author;
            int page;
            cin>>name>>author>>page;
            if(n <= 9){
                n++;
                shelf[n].name=name;
                shelf[n].author=author;
                shelf[n].page=page;
                shelf[n].last_read_time=tc;
            }
            else{
                int k=1;
                for(int i=2;i<=10;i++)if(shelf[i].last_read_time<shelf[k].last_read_time)k=i;
                    shelf[k].name=name;
                    shelf[k].author=author;
                    shelf[k].page=page;
                    shelf[k].last_read_time=tc;
            }
        }
        if(key=="read"){
            string name;
            cin>>name;
            for(int i=1;i<=n;i++){
                if(shelf[i].name==name){
                    shelf[i].last_read_time=tc;
                }
            }
        }
 //       cout<<n<<" "<<tc<<endl;
    }
    int cs[10];
    for(int i=1;i<=n;i++)cs[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-1;j++){
            if(shelf[cs[j]].page>shelf[cs[j+1]].page){
                int t=cs[j];
                cs[j]=cs[j+1];
                cs[j+1]=t;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<shelf[cs[i]].name<<" "<<shelf[cs[i]].author<<" "<<shelf[cs[i]].page<<endl;
    return 0;
}