/*
 *      AddReagent.h
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

int AddReagent()
{
     int sr = 100; // Selected Reagent
     char ch;
     int linec = 80,y = 8,pagenum=1,i;
     showlist:
              
              
   system ("cls");
   //clrscr();

     
     
     cout << "\n  Salt Analysis Simulator v 1.0";
     cout <<"\t\t\t\t\t Salt No - ";
     cout << "\n  -----------------------------\n";
	for (i = 0; i < 80; i++ ) {cout << char(196);} 
    cout << " Add reagents    | <-- Previous    Next -->    Cancel <Esc>    Help <h> | Pg: "<<pagenum;
	cout <<endl;
	for (i = 0; i < 80; i++ ) {cout << char(196);}

	cout << " No \t Reagent Name \t\t\t\t\t\t\t  Code";
	cout << endl; for (i = 0; i < linec; i++ ) {cout << "_";}
	
	
	switch(pagenum)
	{
	 
	 case 1:	
	cout << "\n 1 \t Dilute HCl                                                        1  ";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 2 \t Dilute Sulphuric acid                                             2  ";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 3 \t Conc. Sulphuric acid                                              3  ";
    cout << "\n--------------------------------------------------------------------------------";
    cout << " 4 \t Conc. Sulphuric acid(Introduce a rod with Ammonium Hydroxide)     4  ";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 5 \t Conc. Sulphuric acid (add a paper ball after heating)             5  ";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 6 \t Barium chloride (check solubility in Dil. HCl)                    6  ";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 7 \t Dilute HCl (pass the gas evolved through lime water)              7  ";
    cout << "\n--------------------------------------------------------------------------------";
    break;
    
    	 case 2:	
	cout << "\n 1 \t Barium chloride                                                   8";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 2 \t Lead nitrate                                                      9";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 3 \t Sodium nirtoprusside                                              10";
    cout << "\n--------------------------------------------------------------------------------";
    cout << " 4 \t Nitricacid+Silvernitrate(test solubility in Ammoniumhydroxide)    11";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 5 \t Conc. Sulphuric acid + Manganese oxide                            12";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 6 \t Conc. Sulphuric acid + Manganese oxide (put starch paper)         13";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 7 \t Nautral Ferric chloride                                           14";
    cout << "\n--------------------------------------------------------------------------------";
    break;
    
    	 case 3:	
	cout << "\n 1 \t Ethanol + Conc. Sulphuric acid + excess water                     15";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 2 \t Lead acetate                                                      16";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 3 \t Diphenyl amine                                                    17";
    cout << "\n--------------------------------------------------------------------------------";
    cout << " 4 \t Sodium Hrdroxide + aluminium powder (heat)                        18";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 5 \t Sodium carbonate                                                  19";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 6 \t Dil. HCl + Hydrogen sulphide                                      20";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 7 \t Ammonium chloride + Ammonium Hydroxide                            21";
    cout << "\n--------------------------------------------------------------------------------";
    break;
    
       	 case 4:	
	cout << "\n 1 \t Ammonium chloride + Ammonium Hydroxide + Hydrogen Sulphide        22";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 2 \t Ammonium chloride + Ammonium Hydroxide + Ammonium carbonate       23";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 3 \t Ammonium chloride + Ammonium Hydroxide + Ammonium 123             24";
    cout << "\n--------------------------------------------------------------------------------";
    cout << " 4 \t Sodium Hrdroxide (Introduce Conc3 HCl)                            25";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 5 \t Potassium iodide (check solubility in hot water)                  26";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 6 \t Acetic acid + Portassium chromate                                 27";
    cout << "\n--------------------------------------------------------------------------------";	
	cout << " 7 \t Ammonium hydroxide (add drop by drop)                             28";
    cout << "\n--------------------------------------------------------------------------------";
    break;
    
     	 case 5:	
	cout << "\n 1 \t Acetic acid + Potassium ferrocyanide                              29";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 2 \t Sodium Hydroxide (add drop by drop)                               30";
    cout << "\n--------------------------------------------------------------------------------";
	cout << " 3 \t Ammonium Hydroxide + Ammonium oxalate                             31";
    cout << "\n--------------------------------------------------------------------------------";
    cout << " 4 \t Magneson reagent + Sodium Hydroxide                               32";
    cout << "\n--------------------------------------------------------------------------------";
    cout << " 5 \t Nessler's reagent                                                 33";
    cout << "\n--------------------------------------------------------------------------------";
    
    

	cout << "\n";
    cout << "\n";	
	cout << "\n";
    cout << "\n";
    
    break;   
  }  
  gotoxy (0,10);
  cout << " Enter reagent number >>> ";
  ch = getch();
  char r = 77, l = 75;
  
  switch (ch)
  {
         /** Key strokes **/
         
         
         /*
         case 'n': if ((pagenum >= 1) && (pagenum <5))pagenum++ ;break;
         case 'N': if ((pagenum >= 1) && (pagenum <5))pagenum++ ;break;
         case 'B': if (pagenum >= 2)  pagenum = pagenum-- ;break;
         case 'b': if (pagenum >=2 )  pagenum = pagenum-- ;break;*/
         
         /** Reagent selection **/
         case '1':
              switch (pagenum)
              {
                     case 1 : sr = 1;  break;
                     case 2 : sr = 8;  break;
                     case 3 : sr = 15; break;
                     case 4 : sr = 22; break; 
                     case 5 : sr = 29; break;
              }break; 
              
         case '2':
              switch (pagenum)
              {
                     case 1 : sr = 2;  break;
                     case 2 : sr = 9;  break;
                     case 3 : sr = 16; break;
                     case 4 : sr = 23; break; 
                     case 5 : sr = 30; break;
              }break;
         
         case '3':
              switch (pagenum)
              {
                     case 1 : sr = 3;  break;
                     case 2 : sr = 10;  break;
                     case 3 : sr = 17; break;
                     case 4 : sr = 24; break; 
                     case 5 : sr = 31; break;
              }break;
         
          case '4':
              switch (pagenum)
              {
                     case 1 : sr = 4;  break;
                     case 2 : sr = 11;  break;
                     case 3 : sr = 18; break;
                     case 4 : sr = 25; break; 
                     case 5 : sr = 32; break;
              }break;
              
          case '5':
              switch (pagenum)
              {
                     case 1 : sr = 5;  break;
                     case 2 : sr = 12;  break;
                     case 3 : sr = 19; break;
                     case 4 : sr = 26; break; 
                     case 5 : sr = 33;break;
              }break;
              
          case '6':
              switch (pagenum)
              {
                     case 1 : sr = 6;  break;
                     case 2 : sr = 13;  break;
                     case 3 : sr = 20; break;
                     case 4 : sr = 27; break; 
              }break;
              
          case '7':
              switch (pagenum)
              {
                     case 1 : sr = 7;  break;
                     case 2 : sr = 14;  break;
                     case 3 : sr = 21; break;
                     case 4 : sr = 28; break; 
              }break;  
              
              case 27:return 0; // 123 - test!! Esc
          case 0 :
               ch = getch();
               if ( ch == 77 )
               {
                    if ((pagenum >= 1) && (pagenum <5))
                    pagenum++ ;
               }
               
               else if (ch == 75 )
               {
                    if (pagenum >= 2)
                    pagenum = pagenum-- ;
               }                        
               break;
              
               
              
         default:break; // 123
 }
 if (sr != 100)
 return sr;
 else
 goto showlist;
}
