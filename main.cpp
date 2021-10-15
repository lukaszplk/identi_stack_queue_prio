#include<iostream>
#include <queue>
#include <stack>
using namespace std;


int main(){
    stack<int> *stos;
    queue<int> *kolejka;
    priority_queue<int> *prio;
    bool tab[3]; 
    bool flag = false;
    int n = 0, k, l, counter=0;

    tab[0] = true;
    tab[1] = true;
    tab[2] = true;

    cin>>n;
    while(cin){
        stos = new stack<int>;
        kolejka = new queue<int>;
        prio = new priority_queue<int>;
        
        while(n--){
            cin>>k>>l;
            if(k==1){   
                stos->push(l);
                kolejka->push(l);
                prio->push(l);
            }else if(k==2){
                if(stos->empty() || kolejka->empty() || prio->empty()){
                    flag = true;  
                }else{
                    if(!(l==stos->top())){
                        tab[0] = false;    
                    }else{
                        stos->pop();
                    }
                    if(!(l==kolejka->front())){ 
                        tab[1] = false;
                    }else{
                        kolejka->pop();
                    }

                    if(!(l==prio->top())){ 
                        tab[2] = false;
                    }else{ 
                        prio->pop();
                    }
                }  
            }
        }

        for(int i=0;i<3;i++){
            if(tab[i]){
                counter++;
            }
        }
        
        if(counter == 0 || flag){
            cout<<"niemozliwe"<<endl;
        }else if(counter>1){
            cout<<"brak pewnosci"<<endl;
        }else if(tab[0]){
            cout<<"stos"<<endl;
        }else if(tab[1]){
            cout<<"kolejka"<<endl;
        }else if(tab[2]){
            cout<<"kolejka priorytetowa"<<endl;
        }
        
        delete stos, kolejka, prio;

        tab[0] = true;
        tab[1] = true;
        tab[2] = true;

        counter = 0;
        flag = false;
        cin>>n;
    }

    return 0;
}