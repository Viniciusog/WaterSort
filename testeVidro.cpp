#include <iostream>
#include "Vidro.h"

using namespace std;

int main(){
    Vidro v1(10);
    Vidro v2(10);
    //v1.push(10);
    v1.passarLiquido(v2);
    int aux;
    cout<<v2.pop(aux)<<endl;
    cout<<aux<<endl;


    return 0;
}