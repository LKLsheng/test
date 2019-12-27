#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int RACE_END = 70;

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr );
void moveTortoise( int *const );
void moveHare( int * const );

int main()
{
    int tortoise=1;
    int hare = 1;
    clock_t start,end;
    srand( time( 0 ) );
    start=clock();
    while ( tortoise != RACE_END && hare != RACE_END ) 
   {
      Sleep( 100 );
      system("cls");
	      
      moveTortoise( &tortoise );
      moveHare(&hare);
      printCurrentPositions( &tortoise, &hare );
      
   }
   end=clock();
   
   if(tortoise==70) cout<<"TORTOISE WINS!!!YAY!!!"<<endl;
   else if(hare==70) cout<<"Hare wins. Yuch."<<endl;
   cout<<(end-start)/1000<<" second"<<endl;
}

/*印出烏龜與兔子位置*/
void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr )
{
	for(int i=1;i<=70;i++){
		if(i%10==0)
			cout<<"|";
		else
			cout<<"-";
	}
	cout<<endl;
	cout<<setw(*bunnyPtr)<<"H"<<endl;
	cout<<setw(*snapperPtr)<<"T"<<endl;
}

/*移動烏龜*/
void moveTortoise( int * const turtlePtr )
{
	int r=rand()%10;
	if(r>=0 && r<=4) *turtlePtr+=3;
	else if(r>=5 && r<=6)*turtlePtr-=6;
	else *turtlePtr+=1;
	
	if(*turtlePtr>70) *turtlePtr=70;
	else if(*turtlePtr<1) *turtlePtr=1;
}

/*移動兔子*/
void moveHare( int * const rabbitPtr )
{
	int r=rand()%10;
	if(r>=0 && r<=1) *rabbitPtr+=0;
	else if(r>=2 && r<=3) *rabbitPtr+=9;
	else if(r==4) *rabbitPtr-=12;
	else if(r>=5 && r<=7) *rabbitPtr+=1;
	else *rabbitPtr-=2;
	
	if(*rabbitPtr>70) *rabbitPtr=70;
	else if(*rabbitPtr<1) *rabbitPtr=1;
}
