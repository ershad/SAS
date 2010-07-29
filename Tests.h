/*
 *      Tests.h
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

void Tests()
{
    const int matchstick_ =  88;
    const int brownring_ =  87;
    const int permaganic_ =  89;
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

	cout << " No \t Test \t\t\t\t\t\t\t  Code";
	cout << endl; for (i = 0; i < linec; i++ ) {cout << "_";}
	cout << "\n 1 \t Check colour                                                        1  ";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 2 \t Heat Strongly                                                         2  ";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 3 \t Flame Test                                                            3  ";
    cout << "\n--------------------------------------------------------------------------------";
    cout << " 4 \t Ash Test                                                              4  ";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 5 \t Brown Ring Test                                                       5  ";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 6 \t Match Stick Test                                                      6  ";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 7 \t Permanganic acid Test                                                 7  ";
    cout << "\n--------------------------------------------------------------------------------";
    gotoxy (0,10);
  cout << " Enter test number >>> ";
  ch = getch();
  gotoxy (6,10);
  switch (ch)
  {
         case '1': s[n].CheckColour();break;
         case '2': s[n].HeatStrongly();break;
         case '3': s[n].FlameTest();break;
         case '4': s[n].AshTest();break;
         case '5': s[n].TestSalt(brownring_);break;
         case '6': s[n].TestSalt(matchstick_);break;
         case '7': s[n].TestSalt(permaganic_);break;
         case 27:return 0; // 123 - test!! Esc
         default:break; // 123
 }
 if (st != 100)
 return sr;
 else
 goto showlist;
}
