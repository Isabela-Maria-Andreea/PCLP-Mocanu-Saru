#include <stdio.h>



int estePalindrom(int n){
int x;
x=n;
int nr=0;
while(x!=0){
nr=nr*10+x%10;
x/=10;
}
if(nr==n) return 1;

return 0;

}





int main(){

int n;
scanf("%d",&n);
 if(estePalindrom(n)==1) printf("DA");
 else printf("NU");


}


