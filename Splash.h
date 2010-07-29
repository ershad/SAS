/*
 *      Splash.h
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

void Splash()
{
	cout << "\n\n  Welcome to\n\n";
	gotoxy (5,5);
int x = 6, y = 8,i;
gotoxy (x,y++);

cout<< " ____        _ _        _                _           _";gotoxy (x,y++);
cout<<"/ ___|  __ _| | |_     / \\   _ __   __ _| |_   _ ___(_)___";gotoxy (x,y++);
cout<<"\\___ \\ / _` | | __|   / _ \\ | '_ \\ / _` | | | | / __| / __|";gotoxy (x,y++);
cout<<" ___) | (_| | | |_   / ___ \\| | | | (_| | | |_| \\__ \\ \\__ \\";gotoxy (x,y++);
cout<<"|____/ \\__,_|_|\\__| /_/   \\_\\_| |_|\\__,_|_|\\__, |___/_|___/";gotoxy (x,y++);
cout<<"                                           |___/";gotoxy (x,y++);
cout<<" ____  _                 _       _";gotoxy (x,y++);
cout<<"/ ___|(_)_ __ ___  _   _| | __ _| |_ ___  _ __";gotoxy (x,y++);
cout<<"\\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|";gotoxy (x,y++);
cout<<" ___) | | | | | | | |_| | | (_| | || (_) | |";gotoxy (x,y++);
cout<<"|____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|  V 1.0\n" ;;gotoxy (x,y++);

cout << "\n\n\n";

for (i = 0; i < 80; i++ ) {cout << char(196);} 
cout << "                                        Press any key to continue..\n";
for (i = 0; i < 80; i++ ) {cout << char(196);}


	//gotoxy (5,2);
  getch();
}
