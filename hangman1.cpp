/* C++ Language 

HANGMAN GAME by Neciu Dan

*/


#include "graphics2.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <windows.h>


using namespace std;
#include "concol.h"
string Alf="ABCDEFGHIJKLMNOPQRSTUVWXYZ";// Global Variable;



//Function that centers the output
void PlaceCursor(const int x, const int y) 

    {
	 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD PlaceCursorHere;
    PlaceCursorHere.X = x;
    PlaceCursorHere.Y = y;
	 
    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
    return;
	}
//Function that shows All the letters and removes users input
void Alfabet(char value)
{
    
    PlaceCursor(20,20);
    for(int u=0;u<26;u++)
     {
     if(value==Alf[u])
     Alf[u]=' ';
     setcolor(blue,black);
     cout<<" "<<Alf[u];
     }
     return ;
     }
//Function that returns a random number	
int random_function()
{
                       
    srand((unsigned)time(0));
    int random_integer;
    
    random_integer = (rand()%10)+1;
    return random_integer;
}
//Main Program 
int main(){
    SetConsoleTitle("HANGMAN by Neciu Dan");
    concol b=concol(backcolor());
//Variables:
    int tries=6;
    string random_word, underline,definition;
    string words[11];
    string definitions[11];
    int lenght;
    bool cont=true;
    char value;   
    char d='_';
    int i;
// The words string
    words[0]="HELICOPTER";
    words[1]="AEROPLANE";
    words[2]="ELEPHANT";
    words[3]="SNOWBALL";
    words[4]="COMPUTER";
    words[5]="TELEVIZION";
    words[6]="MICROWAVE";
    words[7]="FOOD";
    words[8]="JOKE";
    words[9]="TELEPHONE";
    words[10]="MOUSE";
    
//The definitions string
    definitions[0]="Look up in the sky! Is it a Bird? Is it a plane? ";
    definitions[1]="The safest way to travel";
    definitions[2]="This animal can't jump";
    definitions[3]="You fight with it in the winter";
    definitions[4]="This program was build on a ?";
    definitions[5]="You watch it for pleasure";
    definitions[6]="Nobody uses the OVEN anymore";
    definitions[7]="Yum,Yum,Yum";
    definitions[8]="HA!HA!Ha!";
    definitions[9]="RING!RING";
    definitions[10]="Click?Click? SQEAQ!SQEAQ";
    
    i=random_function();
    random_word=words[i];
    definition=definitions[i];
    lenght=random_word.size();
    
//Hides the Word and outputs the Hidden word and the Alphabet
    underline=random_word;
    for(int j=0;j<=lenght-1;j++)
    underline[j]=d;
    Alfabet(value);
    PlaceCursor(25, 6);
    for(int m=0;m<=lenght-1;m++)
    cout<<underline[m]<<" ";
    cout<<endl<<endl<<endl;
     
    do
    {
                           int c=0;
                           int g=0;
                           PlaceCursor(35, 3);
                           setcolor(red,black);
    cout<<"HINT: "<<definition;
    
                           PlaceCursor(25, 10);
    cout<<"Find the WORD and Avoid the NOOSE !"<<endl;
    cin>>value;
    value = toupper(value);//Changes to Uppercase;
    
    system("cls");//Clears the screen;
    Alfabet(value);
    for(int n=0;n<=lenght-1;n++)
    {
            if(value==random_word[n])
                                    {
                                     underline[n]=value;
                                     c++;
                                     }
            
    }
               if(c==0)
               {
               tries=tries-1;
               PlaceCursor(1, 1);
               cout<<"Wrong! You have : "<<tries<<" tries left"<<endl<<endl;
               }
               
               PlaceCursor(25, 6);
               for(int m=0;m<=lenght-1;m++)
               
    cout<<underline[m]<<" ";
    cout<<endl<<endl<<endl;
    
                for(int p=0;p<=lenght-1;p++)
                if(d==underline[p])
                g++;
                if(g==0)
                
                { PlaceCursor(25, 10); cout<<"Congrats! You found the word : "<<random_word<<endl;
                cont=false;
                }
                
                if(tries==0)
                            {
                            PlaceCursor(25,10);
                            cout<<"GAME OVER! The word was : "<<random_word<<endl;
                            cont=false;
                            }
                            }
    while(cont==true);




    getch();
    return 0;
}
