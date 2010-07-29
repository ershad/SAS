/*
 *      sas.cpp
 *      
 *      Copyright 2010 Ershad K <ershad92@gmail.com>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

/********************************************************************************
   Declaring predifined header files ...
*******************************************************************************/
#include "Salt.h"

const int SALT_MAX = 100;
int i;
int n = 1; // This is the core!!
Salt s[SALT_MAX];
char lasttest[20];
unsigned long int key,lkey,ilkey;


/*******************************************************************************
   Declaring user difined header files ...
*******************************************************************************/
//#include "Salt.h"
#include "AddReagent.h"
#include "Splash.h"
#include "Rand.h"
//#include "Tests.h"
#include "StartUp.h"

/**************************** Namespace ***************************************/
//using namespace std;     // This is not needed in borland compiler



/*******************************************************************************
   Function prototypes....
*******************************************************************************/
void header();
void smain();
int Tests();
void keyring();
int start();
void answer();
void about();

//static Salt s[10];


/*******************************************************************************
   Global variables....
*******************************************************************************/



/*******************************************************************************
   Class User - Deals with sas.dat [binary] file - user confs and data
*******************************************************************************/
/*   For future use...
struct UserInfo
{
      int done[SALT_MAX];
      //char name[30];

}User;
      int NewSalt(); // Not defined 
      void GetData(); // Get the user name and additional informations // Not defined 
      void WriteData(int saltnum); // Not defined 
*/

/**** Here starts the defintion of the above mentioned functions *****/


/*******************************************************************************
  Main function - 
  This function starts the program showing the splash and check for nessesory 
  setting and copies to local / global variables..
*******************************************************************************/
int main()
{
    	i = Rand();	
	
//	salt[0].display();
//getchar();
    
    
    /** start from here**/
   
   /* ras:
    cout << Rand();
    getch();
    goto ras;*/
    
    
	clrscr();
	Splash();
	header();
	
	//AddReagent(); // this is to check addreagents inventory
	char ch,opt[10];
	int j = 1,num;

	ch = getch(); 
	cout << ch;

	getchar();
	return 0;
}



void header()
{
     /*************************************************************************
     
     The following part implements a new and easy-to-use salt-scripting language.
     The script can be used to attain the follwing tasks :
         1. Add a new salt
         2. Remove a salt
         3. Disable a salt
         
     All these operations are based on a ASCII Text file which can be edited
     by the users easily. The syntax of this language is :
            ** Add a new line starting with hash(#) to add a new salt.
                   Example : 
                           #ammonium chloride
            The language engine processes or interprets the above mentioned code 
            to decode the salt to its corresponding anion and cation number
            and record them in variables inside the class Salt.
            
            I would like to call this scripting language as 'SAScode'. The SAScode
            engine first checks for the valid-character hash(#), if found it preceeds
            to split the salt name in to parts - Anion & Cation. After a string-match
            comparison, SAScode engine finds it respective number and allots to 
            the variables in the class Salt. 
                           
            ** Delete the entire line including hash(#) to remove a salt
            
            ** Change hash(#) to Dollar($) to disable a salt
            
            For all the questions and doubts regarding SAScode and SAScode engine, 
            please contact its author,
            
                                       Ershad K
                                       ershad92@gmail.com
                                       IRC Nick : ershad , freenode.net    
     
     // SAScode Engine starts here..
    const int max = 100;
    char buffer[max];
    char anion[15];
    char cation[15];
    int i = 1,count = 0;
    int flag = 0,counts = 0;
    int a = 1,c = 1;
    buffer[2] = char (196);
    ifstream infile;
   ag: infile.open ("salts.txt");
    while (infile)
  {
	infile.getline(buffer,max);

	if ( buffer[0] == '#' )
	{
	   for ( i = 1,count = 0; buffer[i] != ' '; i++,count++)
	    {
		   cation[count] = buffer[i];
	    }
	    cation [count] = '\0';

       for ( ++i, count = 0; buffer[i] != ';'; i++,count++)
       {
       	anion[count] = buffer[i];
       }
       anion[count] = '\0';

       cout << cation <<":"<<anion<<"\n";

//$ Available cations :       
//$   ammonium , lead , copper
//$   aluminium , manganese , zinc
//$   barium , calcium , magnesium

//$ Available anions :
//$   carbonate , sulphide , sulphate
//$   nitrate , chloride , bromide
//$   iodide , acetate 


       if ( strcmpi (cation,"ammonium") == 0 ) c = 1;
       if ( strcmpi (cation,"lead") == 0 ) c = 2;
       if ( strcmpi (cation,"copper") == 0 ) c = 3;
       if ( strcmpi (cation,"aluminium") == 0 ) c = 4;
       if ( strcmpi (cation,"manganese") == 0 ) c = 5;
       if ( strcmpi (cation,"zinc") == 0 ) c = 6;
       if ( strcmpi (cation,"barium") == 0 ) c = 7;
       if ( strcmpi (cation,"calcium") == 0 ) c = 8;
       if ( strcmpi (cation,"magnesium") == 0 ) c = 9;

       if ( strcmpi (anion,"carbonate") == 0 ) a = 1;
       if ( strcmpi (cation,"sulphide") == 0 ) a = 2;
       if ( strcmpi (cation,"sulphate") == 0 ) a = 3;
       if ( strcmpi (cation,"nitrate") == 0 ) a = 4;
       if ( strcmpi (cation,"chloride") == 0 ) a = 5;
       if ( strcmpi (cation,"bromide") == 0 ) a = 6;
       if ( strcmpi (cation,"iodide") == 0 ) a = 7;
       if ( strcmpi (cation,"acetate") == 0 ) a = 8;
       
       s[counts++].record(c,a," "); 

  	 }

  }

    infile.close();

    if (buffer[2]==char(196))
    {
     ofstream outfile("salts.txt");
     char txt[] = "$ Edit this file to add or remove salts\n$ Please use small letters\n$ Make sure the spelling is right, using wrong spellings result in errors\n$ Delete the entire line including hash(#) to remove a salt\n"    ;
     char line1[]= "$ Change hash(#) to Dollar($) to disable a salt\n";
     char line2[]= "$ Format to add a new salt is :\n"                   ;
     char line3[]= "$            #<cation><space><anion><semi colon>\n"   ;
     char line4[]= "$     Example :-       #ammonium carbonate;\n"         ;
     char line5[]= "\n"                                                     ;
     char line6[]= "$ Available cations :\n"                                 ;
     char line7[]= "$   ammonium , lead , copper\n"                           ;
     char line8[]= "$   aluminium , manganese , zinc\n"                        ;
     char line9[]= "$   barium , calcium , magnesium\n"                         ;
     char line10[]= "\n"                                                        ;
     char line11[]= "$ Available anions :\n"                                     ;
     char line12[]= "$   carbonate , sulphide , sulphate\n"                      ;
     char line13[]= "$   nitrate , chloride , bromide\n"           ;
     char line14[]= "$   iodide , acetate\n"                        ;
     char line15[]= "\n"                                             ;
     char line16[]= "$ ---------   List of salts starts here ---------\n";
     char line17[]= "\n"                                                  ;
     char line18[]= "#ammonium carbonate;\n"                               ;
     char line19[]= "#ammonium nitrate;\n"                                  ;
     char line20[]= "#ammonium chloride;\n"                                  ;
     char line21[]= "#ammonium acetate;\n"                                    ;
     char line22[]= "#barium chloride;\n"             ;

     outfile << txt << line1 << line2 << line3 << line4 << line5 << line6 << line7   ;
     outfile << line8 << line9 << line10 << line11 << line12 << line13 << line14 << line15 << line16;
   outfile <<  line17 << line18 << line19 << line20 << line21 << line22;
   //  outfile << "\n\n Written using the program ";
     outfile.close();
     goto ag;
    } */
    
    /*
   Cations
#define AMMONIUM 1
#define LEAD 2
#define COPPER 3
#define ALUMINIUM 4
#define MANGANESE 5
#define ZINC 6
#define BARIUM 7
#define CALCIUM 8
#define MAGNESIUM 9


#define CARBONATE 1
#define SULPHIDE 2
#define SULPHATE 3
#define NITRATE 4
#define CHLORIDE 5
#define BROMIDE 6
#define IODIDE 7
#define ACETATE 8
*/
   
    s[1].record(1,1,""); //Ammonium carbonate 
    s[2].record(2,5,""); //Lead carbonate
    s[3].record(6,3,""); //Zinc Sulphate
    s[4].record(7,5,""); //Barium Chloride
    s[5].record(8,1,""); //Calcium Carbonate
    s[6].record(4,5,""); //Aluminium Chloride
    s[7].record(8,7,""); //Calcium Iodide
    s[8].record(6,4,""); //Zinc Nitrate
    s[9].record(3,3,""); //Copper Sulphate
    s[10].record(2,8,""); //Lead Acetate
   // s[11].record(4,8,""); //Aluminium Acetate
    
    
    
    srand(time(0));
    n = (rand() % 10) ;  
   // n = 5;
     
     char ch;
     char input[5];
     int r = 0,t = 0;
     int numflag = 0;
     
     startagain:
                
     /* n must be given a random number */
     
     
     
     redo:
     system ("cls");
     
     
     cout << "\n  Salt Analysis Simulator v 1.0";
     //cout <<"\t\t\t\t\t Salt No - ";
     cout << "\n  -----------------------------\n";
     
     for (i = 0; i < 80; i++ ) {cout << char(196);} 
     cout << " Add reagents <a>     Tests <t>     Answer <k>     About <h>     Exit <e>\n";
     for (i = 0; i < 80; i++ ) {cout << char(196);}
     
     /*
     gotoxy (7,11);
     for (i = 0; t < 30; i++ ) cout <<" ";
     gotoxy (6,10);
     for (i = 0; t < 30; i++ ) cout <<" ";*/
     
     
     cout <<"\n\n Observation : ";
     
     gotoxy (6,11);
     s[n].TestSalt(r);
     gotoxy (7,20);
     s[n].DoTest(t);
     gotoxy (1,16);
     cout << "--------------------------------------------------------------------------------";
     cout <<"\n Last Test Result (" << s[n].lasttest << "): ";
     

     //r = 0;
     
     
     //i = rand();
    // cout <<endl << i << endl << RAND_MAX;
     
	 gotoxy (1,24);
     cout <<" Add reagents directly (code)  <space> ";
     ch = getch(); 
     switch(ch)
     {
               case 'a': r = AddReagent(); break;
               case 'A': r = AddReagent(); break;
               case 'k': answer();break;
               case 'K': answer();break;
               case 'H': about();break;
               case 'h': about();break;
               case 'e':exit(0);
               case 'E':exit(0);
               case 't': t = Tests();break;
               case 'T': t = Tests();break;
               case ' ': 
                          gotoxy (1,24);
                          cout <<"                                                 ";
                          gotoxy (1,24);
                          cout <<" Add reagents directly (code) >> ";
                          cin >>input;
                          for (int x = 0; input[x] != '\0'; x++ )
                          {
                              switch(input[x])
                              {
                                              case '1': numflag = 0;break;
                                              case '2': numflag = 0;break;
                                              case '3': numflag = 0;break;
                                              case '4': numflag = 0;break;
                                              case '5': numflag = 0;break;
                                              case '6': numflag = 0;break;
                                              case '7': numflag = 0;break;
                                              case '8': numflag = 0;break;
                                              case '9': numflag = 0;break;
                                              case '0': numflag = 0;break;
                                              default: numflag = 1;break;
                              }
                          }
                          if (numflag == 0)
                          r = atoi(input);
                          else
                          break;
               
     }
     
      //getchar();
     
     goto redo;
     
               
//     getch();
           
}
/* randtest() is intended for randon-number-duplication check. It produced an 
accuray result approximately equal to 99% !! */

/*
void randtest()
{
	unsigned long int i, x[500000];
	int j, count =0;
	
	for (j = 0;j <= 50000; j++){
		
		x[j] = i;
		
		i = rand();
	
	}
	cout << endl << x[--j] << endl;
	cout << "\n finished generating.. started comparing";
	
		
	for (  j = 0; j <= 50000; j++ )
	{
		for (i = 0; i <= 50000; i++)
		{
			if ((x[j] == x[i]) && ( i != j) )
			{
				cout <<"\n SAME !! " << x[j];
				count++;
			}
		}
	}			
	cout << "\n\n Count = "<< count;;
	cout << "\n";
}
*/

void answer()
{
     clrscr();
     char AnsAnion[10];
     char AnsCation[10];
     cout << n;
     
     cout << "\n  Salt Analysis Simulator v 1.0";

     cout << "\n  -----------------------------\n";
     
     for (i = 0; i < 80; i++ ) {cout << char(196);} 
     cout << " \t\t\t\t Answer\n";
     for (i = 0; i < 80; i++ ) {cout << char(196);}
     
     if (s[n].C == 1) strcpy (AnsCation, "Ammonium");
     if (s[n].C == 2) strcpy (AnsCation, "Lead");
     if (s[n].C == 3) strcpy (AnsCation, "Copper");
     if (s[n].C == 4) strcpy (AnsCation, "Aluminum");
     if (s[n].C == 5) strcpy (AnsCation, "Manganese");
     if (s[n].C == 6) strcpy (AnsCation, "Zinc");
     if (s[n].C == 7) strcpy (AnsCation, "Barium");
     if (s[n].C == 8) strcpy (AnsCation, "Calcium");
     if (s[n].C == 9) strcpy (AnsCation, "Magnesium");

     if (s[n].A == 1) strcpy (AnsAnion, "Carbonate");
     if (s[n].A == 2) strcpy (AnsAnion, "Sulphide");
     if (s[n].A == 3) strcpy (AnsAnion, "Sulphate");
     if (s[n].A == 4) strcpy (AnsAnion, "Nitrate");
     if (s[n].A == 5) strcpy (AnsAnion, "Chloride");
     if (s[n].A == 6) strcpy (AnsAnion, "Bromide");
     if (s[n].A == 7) strcpy (AnsAnion, "Iodide");
     if (s[n].A == 8) strcpy (AnsAnion, "Acetate");
     
     cout << "\n\n\n\n\n";
     cout << "\t\t\t Cation = "<< AnsCation ;
     cout << "\n\n";
     cout << "\t\t\t Aation = "<< AnsAnion ;
     
     cout << "\n\n\n\n\n\n\n\n";

for (i = 0; i < 80; i++ ) {cout << char(196);} 
cout << "                                        Press any key to continue..\n";
for (i = 0; i < 80; i++ ) {cout << char(196);}

     getch();
 }
 
 void about()
{
      clrscr();
     
     cout << "\n  Salt Analysis Simulator v 1.0";

     cout << "\n  -----------------------------\n";
     
     for (i = 0; i < 80; i++ ) {cout << char(196);} 
     cout << " \t\t\t\t About\n";
     for (i = 0; i < 80; i++ ) {cout << char(196);}
     
     cout << "\n\n";
     cout <<"\n\t\t\t Developed by,\n";
     cout <<"\n\t\t\t\tErshad K\n";
     cout <<"\n\t\t\t\t+2 Computer Science Student\n";
     cout <<"\n\t\t\t\tBEMHSS, Palakkad, Kerala\n";
     cout <<"\n\t\t\t\tMail: ershad92@gmail.com\n";
     
     cout << "\n";
     
for (i = 0; i < 80; i++ ) {cout << char(196);} 
cout << "                                        Press any key to continue..\n";
for (i = 0; i < 80; i++ ) {cout << char(196);}
     getch();
 }
 

int Tests()
{
     int st = 100; // Selected Reagent
     char ch;
     int linec = 80,y = 8,pagenum=1,i;
     showlist:           
              
   system ("cls"); //clrscr();
     cout << "\n  Salt Analysis Simulator v 1.0";
     cout <<"\t\t\t\t\t Salt No - ";
     cout << "\n  -----------------------------\n";
	for (i = 0; i < 80; i++ ) {cout << char(196);} 
    cout << " Tests    | Cancel <Esc>    Help <h> |";
	cout <<endl;
	for (i = 0; i < 80; i++ ) {cout << char(196);}

	cout << " No \t Test \t\t\t\t\t\t\t ";
	cout << endl; for (i = 0; i < linec; i++ ) {cout << "_";}
	cout << "\n 1 \t Check colour                                                     ";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 2 \t Heat Strongly                                                     ";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 3 \t Flame Test                                                       ";
    cout << "\n--------------------------------------------------------------------------------";
    cout << " 4 \t Ash Test                                                         ";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 5 \t Brown Ring Test                                                  ";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 6 \t Match Stick Test                                                 ";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 7 \t Permanganic Acid Test                                             ";
    cout << "\n--------------------------------------------------------------------------------";
    gotoxy (0,10);
  cout << " Enter test number >>> ";
  ch = getch();
  
  switch (ch)
  {
         case '1': st = 80; break;
         case '2': st = 81; break;
         case '3': st = 82; break;
         case '4': st = 83; break;
         case '5': st = 84; ;break;
         case '6': st = 85; break;
         case '7': st = 86; break;
         case 27:return 0; // 123 - test!! Esc
         default:break; // 123
 }
 if (st == 100)
 goto showlist;
 else
 return st;
}

/*******************************************************************************
The following function is to implement an anti-piracy protection and was left
incompleted due to the developer's Free software ethics. [ I would like to 
release this program under GPL Version 3, which would be did soon :) ]

For the anti-piracy protection logic which 'would have' implemented here,
please contact the author at his mail ID, ershad92@gmail.com

The duty of the follwing function is to generate a 8 digit unique number :)
********************************************************************************/

void keyring() 
{
    int i,r,j;
    
    unsigned long int  a,b,c,d,e,f,g,h;
    again:
    srand(time(0));
    
    i = rand();
    for ( j = 0; j < 4; j++)
    {
        key = key * i;
        i = rand();
    }    
    while ( key > 99999999 )
    {
         key = key / 10;
    }
    
    while ( key < 10000000 )
    {
          key = key * 7;
    }
    
    cout << "\n randome key = "<< key;
    //cout << "\n Rand max = " << RAND_MAX;
    /* r = (rand() % 10) ;
    cout << "  " << r;*/
    
    
     /*** keygen to unlock ***/
     
    
    a = ((key * 3 ) / 1 );
   // cout << "\n\n a = " << a;
    
    b = ((a * key ) / 13 ) * 7;
    //cout << "  b = " << b;
    
    c = ((a*b)/key )+ (1*b) + 123;
   // cout << "  c = " << c;
    
    d = (key /a) * b;
  //  cout << "  d = " << d;
    
    e = (key /a) * c + d;
    //cout << "  e = " << e;
    
    g = ((a+b+c)/3)+e+(f/7);
    h = ((((g*13)*5)/7)/3);
    
    f = ((key - 13) * b ) + c * (a-e) + (g-a);
   // cout << "  f = " << f;
    
    lkey = ((f * e ) - (a * b) ) * (c + d);
  //  cout << "\n\n lkey = " << lkey;
    
    while ( lkey > 99999999 )
    {
         lkey = lkey / 10;
    }
    
    while ( key < 10000000 )
    {
          lkey = lkey * 7;
    }
    
    //cout << "\n\n>> Unlock key : " << lkey;

    goto again;
 
}

