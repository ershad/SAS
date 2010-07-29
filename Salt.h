/*
 *      Salt.h
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

/*******************************************************************************
   Declaring predifined header files ...
*******************************************************************************/
#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>
#include <ctime>    // For time() - Check for existence in borland includes
#include <cstdlib>  // For srand() and rand - Check for existence in includes
//#include <conio.h>

// using namespace std;
// Cations
#define AMMONIUM 1
#define LEAD 2
#define COPPER 3
#define ALUMINIUM 4
#define MANGANESE 5
#define ZINC 6
#define BARIUM 7
#define CALCIUM 8
#define MAGNESIUM 9

//Anions
#define CARBONATE 1
#define SULPHIDE 2
#define SULPHATE 3
#define NITRATE 4
#define CHLORIDE 5
#define BROMIDE 6
#define IODIDE 7
#define ACETATE 8

//Reagensts
#define dHCl 1 // Dilute HCl
#define dH2SO4 2
#define cH2SO4 3
#define cH2SO4_NH4OH 4 // Add H2SO4 and then introduce NH4OH to test tube
#define cH2SO4_papper 5
#define bariumchloride_insol_dHCL 6
#define dHCl_lime 7

#define bariumchloride 8
#define leadnitrate 9 /* add lead nitrate **/
#define sodiumnitroprusside 10

/*
#define HNO3_AgNO3_sol_NH4OH 11
#define cH2SO4_MnO2 12
#define HNO3_AgNO3_psol_NH4OH 13
#define H2SO4_MnO2_spaper 14
#define HNO3_AgNO3_insol_NH4OH 15*/

#define HNO3_AgNO3 11
#define cH2SO4_MnO2 12
#define H2SO4_MnO2_spaper 13
#define neutralferricchloride 14
#define acetate_special_test 15
#define leadacetate 16
#define diphenylamine 17
#define NaOH_aluminium 18

#define sodiumcarbonate 19
#define dHCl_H2S 20
#define NH4CL_NH4OH 21
#define NH4CL_NH4OH_H2S 22
#define NH4CL_NH4OH_NH42CO3 23
#define NH4CL_NH4OH_Na2HPO4 24

#define NaOH_fumes_cHCl 25
#define potassium_iodide_sol_water 26
#define aceticacid_potassiumchromate 27
#define NH4OH_dropbydrop 28
#define aceticacid_potassiumferrocyanide 29
#define NaOH 30

#define NH4OH_ammoniumoxalate 31
#define mangeson_NaOH 32
#define nessler 33

#define matchstick 85
#define brownring 84
#define permaganic 86

#define xx 7
#define yy 12


class Salt
{
public:
       //int S;						// Salt Number ( combining both Anion & Cation )
	   char *name;				// Name of the salt
   	   int A;						// Anion number
	   int C;	
       char lasttest[30];					//Cation number

	// Priliminary tests..
	int CheckColour();
	int HeatStrongly();
	int FlameTest();
	int AshTest();
	int DoTest(int test);
	void record(int c, int a, char *n)
	{
         //S = s;
          C = c;
          A = a;
          name = n;
    }
    void display()
    {
         cout <<"Anion No:"<<A<<" Cation No:"<<C<<" Name :"<<name;
    }
    Salt()
    {
          strcpy(lasttest," ------------------------------------ ");
          strcpy(lasttest,"No such tests have been done");
    }



	//Analysis of anions & cations
	int TestSalt(int reagent);

}; 


int Salt::DoTest(int test)
{
    switch(test)
    {
    case 0: break;
    case 80: CheckColour(); strcpy(lasttest,"Check Colour");break;
    case 81: HeatStrongly();strcpy(lasttest,"Heat Strongly");break;
    case 82: FlameTest();strcpy(lasttest,"Flame Test");break;
    case 83: AshTest();strcpy(lasttest,"Ash Test");break;
    case 84: TestSalt(84);strcpy(lasttest,"Brown Ring Test");break;
    case 85: TestSalt(85);strcpy(lasttest,"Match Stick Test");break;
    case 86: TestSalt(86);strcpy(lasttest,"Permaganic Acid Test");break;
    }
}
    
int Salt::CheckColour()
{
    
	switch (C) // Checking only C becuase, Cu and Mn are cations
	{
		case COPPER :
			cout << " Colour of the salt is Blue ! "; break;
		case MANGANESE :
			cout << " Colour of the salt is Pink ! "; break;
		default:
			cout << " Colour of the salt is White !"; break;
	}
	return 0;
}

int Salt::HeatStrongly()
{
	int flag = 0;
	switch (A)
	{
	case CARBONATE :
		cout << " A colourless gas which turned lime water milky is evolved!";flag=1;break;
	case SULPHIDE :
		cout << " A colourless gad with the smell of burnt sulphur!";flag=1;break;
	case IODIDE :
		cout << " Violet vapours are observed!";flag=1;break;
	}

	if ( C == AMMONIUM)
	{
         
		cout << "Smell of Ammonia is observed!";
		flag = 1;
	}

	if ( flag ==0) // I hope this statement is equal to 'if ( flag == 0 )'
	{
		cout << " Nothing of speciality ! ";
	}

	return 0;
}

int Salt::FlameTest()
{
	switch(C) // Flame test are used to find cations only
	{
	case COPPER :
		cout << " Bluish flame colour is observed! "; break;
	case BARIUM :
		cout << " Green flame colour is observed! "; break;
	case CALCIUM :
		cout << " Brick red flame colour is observed!"; break;
	default :
		cout << " Nothing of speciality! "; break;
	}

	return 0;
}

int Salt::AshTest()
{
	switch (C)
	{
	case ALUMINIUM :
		cout << " Blue tinted ash is formed!";break;
	case ZINC : 
		cout << " Green tinted ash is formed!";break;
	case MAGNESIUM :
		cout << " Pink tinted ash if formed!";break;
	default :
		cout << " Nothing of speciality! ";break;
	}
	return 0;
}
int Salt::TestSalt(int reagent)
{
	switch (reagent)
	{
		/******* Analysis of Anion **********/

    case 0:break;
	case dHCl :
		if ( A == CARBONATE )
		{
			cout << " Vigorous or brisk effervescence with evolution ";
			gotoxy (xx,yy);cout << "of a colurless gas is observed!";
		}
		else if (A == SULPHIDE )
		{
			cout << " Colourless gas and smell of rotten eggs are observed!";
		}
		/*   ----------------- Lead - Cation ----------------*/
		else if ( C == LEAD )
		{
			cout << " A white precipitate is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;

	case dH2SO4 :
		if ( A == ACETATE )
		{
			cout << "Vinegar like smell is observed!";
		}
		else
			cout << " No chracteristic observation!";
		break;

	case cH2SO4_NH4OH : // Add H2SO4 and then introduce NH4OH to test tube
		if ( A == CHLORIDE )
		{
			cout << " Colourless gas evolved which gave dense white fumes!";
		}
		else
			cout << " No chracteristic observation!";
		break;

	case cH2SO4 :
		if ( A == BROMIDE )
		{
			cout << " Reddish brown vapours evolved and solution turns brown";
		}
		else if ( A == IODIDE )
		{
			cout << " Violet vapours and black shining crystals on the cooler ";
			gotoxy (xx,yy);cout<< "sides of the test tube!";
		}
		else
			cout << " No chracteristic observation!";
		break;

	case cH2SO4_papper : // Paper ball or Copper tunings is added to solution with cH2SO4
		if ( A == NITRATE )
		{
			cout << " Reddish brown gas is evolved!";
		}
		else
			cout << " No chracteristic observation!";
		break;

	case bariumchloride_insol_dHCL :
		if ( A == SULPHATE )
		{
			cout << " A white precipitate (insoluble in dil. HCL) is observed!";
		}
		else
			cout << " No chracteristic observation!";
		break;

		/******* /Analysis of Anion **********/


		/******* Confirmatory tests of Anions **********/

		/*   ----------------- Carbonate ----------------*/
	case dHCl_lime :
		if ( A == CARBONATE )
		{
			cout << " Lime water turns milky!";
		}
		else
			cout << " No chracteristic observation!";
		break;

	case bariumchloride :
		if ( A == CARBONATE )
		{
			cout << " A white precipitate is obtained!";
		}
		else
			cout << " No chracteristic observation!";
		break;

		/*   ----------------- /Carbonate ----------------*/

		/*   ----------------- Sulphide ----------------*/
	case leadnitrate :
		if ( A == SULPHIDE )
		{
			cout << " A black precipitate is obtained!";
		}
		else
			cout << " No chracteristic observation!";
		break;



case leadacetate :
		if ( A == SULPHIDE )
		{
			cout << " A black precipitate is obtained!";
		}
		else if ( A == SULPHATE )
		{
			cout << " A white precipitate! (soluble in ammonium acetate)";
		}
		else
			cout << " No characteristic observation!";
		break;




	case sodiumnitroprusside :
		if ( A == SULPHIDE )
		{
			cout << " A violet Colouration is observed!";
		}
		else
			cout << " No chracteristic observation!";
		break;
		/*   ----------------- /Sulphide ----------------*/

/*   ----------------- Chloride ----------------*/

	case HNO3_AgNO3 :
		if ( A == CHLORIDE )
		{
			cout << " White courdy precipitate! (soluble in excess of Ammonium hydroxide)";
			gotoxy (xx,yy);cout<< "is observed! ";
		}

/*   ----------------- Bromide ----------------*/
		else if ( A == BROMIDE )
		{
			cout << " Pale yellow precipitate! (partially soluble in excess of Ammonium";
            gotoxy (xx,yy);cout<<"hydroxide)";
		}
/*   ----------------- Iodide ----------------*/
		else if ( A == IODIDE )
		{
			cout << "Yellow precipitate! (insoluble in excess of Ammonium hydroxide)";
		}
		else
			cout << " No characteristic observation!";
		break;

	case cH2SO4_MnO2 :
		if ( A == CHLORIDE )
		{
			cout << " A greenish yellow gas with pungent smell is observed!";
		}
		else if ( A == IODIDE ) // IODIDE
		{
			cout << " Deep violet vapours are are evolved which condensed to black shining";
			gotoxy (xx,yy);cout<< "crystals on the cooler sides of the test tube!";
		}
		else
			cout << " No characteristic observation!";
		break;
		/*   ----------------- /Chloride ----------------*/


	case H2SO4_MnO2_spaper :             // ..which turned starch paper yellow when showed in the mouth of the test tube
		if ( A == BROMIDE )
		{
			cout << "R eddish vapours are observed!";
		}
		else
			cout << " No characteristic observation!";
		break;
		/*   ----------------- /Bromide ----------------*/


	/*case H2SO4_MnO2 :
		if ( A == IODIDE )
		{
			cout << " Deep violet vapours are are evolved which condensed to black shining"
				 << " crystals on the cooler sides of the test tube!";
		}
		else
			cout << " No characteristic observation!";
		break; */
		/*   ----------------- /Iodide ----------------*/

		/*   ----------------- Acetate ----------------*/
	case neutralferricchloride :
		if ( A == ACETATE )
		{
			cout << " A deep red colouration is obtained!";
		}
		else
			cout << " No characteristic observation!";
		break;

	case acetate_special_test :       // Pg :- 104, 6 - b
		if ( A == ACETATE )
		{
			cout << " Pleasant fruity smell!";
		}
		else
			cout << " No characteristic observation!";
		break;
		/*   ----------------- /Acetate ----------------*/

		/*   ----------------- Nitrate ----------------*/
	case brownring :
		if ( A == NITRATE )
		{
			cout << " A brown ring is formed at the junction of the acid and aqueous solution!";
		}
		else
			cout << " No characteristic observation!";
		break;

	case diphenylamine :
		if ( A == NITRATE )
		{
			cout << " A deep blue coluration is obtained!";
		}
		else
			cout << " No characteristic observation!";
		break;
	case NaOH_aluminium :
		if ( A == NITRATE )
		{
			cout << " Smell of ammonia giving dense white fumes with a glass rod dipped ";
            gotoxy (xx,yy);cout<<"in conc.HCl!";
		}
		else
			cout << " No characteristic observation!";
		break;
		/*   ----------------- /Nitrate ----------------*/

		/*   ----------------- Sulphate ----------------*/


	case matchstick :
		if ( A == SULPHATE )
		{
			cout << " Violet streak is produced!";
		}
		else
			cout << " No characteristic observation!";
		break;

		/*   ----------------- /Sulphate ----------------*/

		/*   **----------------- Analysis of cations ----------------**    */

		/*   ----------------- Ammonium ----------------*/
	case sodiumcarbonate :
		if ( C == AMMONIUM )
		{
			cout << " No precipitate is formed!";
		}
		else
			cout << " A precipitate is formed!";
		break;

		/*   ----------------- Copper ----------------*/
	case dHCl_H2S :
		if ( C == COPPER )
		{
			cout << " A black precipitate is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;

		/*   ----------------- Aluminium ----------------*/
	case NH4CL_NH4OH :
		if ( C == ALUMINIUM )
		{
			cout << " A white gelatinous precipitate is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;

	/*   ----------------- Zinc or Manganese----------------*/
	case NH4CL_NH4OH_H2S :
		if ( C == ZINC )
		{
			cout << " A white precipitate is formed!";
		}
		else if ( C == MANGANESE )
		{
			cout << " A flesh or pink precipitate is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;

		/*   ----------------- Barium or Calcium ----------------*/
	case NH4CL_NH4OH_NH42CO3 :
		if ( C == BARIUM )
		{
			cout << " A white precipitate is formed!";
		}
		else if ( C == CALCIUM )
		{
			cout << " A white precipitate is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;

		/*   ----------------- Magnesium ----------------*/
	case NH4CL_NH4OH_Na2HPO4 :
		if ( C == MAGNESIUM )
		{
			cout << " A white crystalline precipitate is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;
		/* ---- /Preliminary Experiments ---------- */
		
		/* ---- Zero group ---------- */
	case NaOH_fumes_cHCl :
		if ( C == AMMONIUM )
		{
			cout << " Colourless gas with the smell of ammonia producing";
			gotoxy (xx,yy);cout<< "dense white fumes with conc.HCl is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;
		
		/* ---- First group ---------- */
	case potassium_iodide_sol_water :
		if ( C == LEAD )
		{
			cout << " Yellow precipitate in hot water but reappears as golden spangle";
			gotoxy (xx,yy);cout<< " on cooling is obtained!";
		}
		else
			cout << " No characteristic observation!";
		break;
	case aceticacid_potassiumchromate :
		if ( C == LEAD )
		{
			cout << " Yellow precipitate is obtained!";
		}
		else if ( C == BARIUM )
		{
			cout << " Yellow precipitate is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;
		
		/* ------- Second group ------- */
		
	case NH4OH_dropbydrop :
		if ( C == COPPER )
		{
			cout << " A blue precipitate soluble in excess if Ammonium Hydroxide is obtained!";
		}
		else
			cout << " No characteristic observation!";
		break;
		
	case aceticacid_potassiumferrocyanide :
		if ( C == COPPER )
		{
			cout << " Chocolate brown precipitate is obtained!";
		}
		else
			cout << " No characteristic observation!";
		break;
		
		/* ------- Third group ------- */
	case NaOH :
		if ( C == ALUMINIUM )
		{
			cout << " A wihte gelatinous precipitate soluble in excess of NaOH is formed!";
		}
		else if ( C == ZINC )
		{
			cout << " White precipitate soluble in excess of NaOH is formed!";
		}
		else if ( C == MANGANESE )
		{
			cout << " White precipitate changing to brown is observed!";
		}
		else
			cout << " No characteristic observation!";
		break;
		
	case permaganic :
		if ( C ==  MANGANESE )
		{
			cout << " The suprenatent liquid got pink colour!";
		}
		else
			cout << " No characteristic observation!";
		break;
				
		/* ------- Group Five ------- */
	case NH4OH_ammoniumoxalate :
		if ( C == CALCIUM )
		{
			cout << " A white precipitate is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;
		
		/* ------- Group Six ------- */
	case mangeson_NaOH :
		if ( C == MAGNESIUM )
		{
			cout << " A blue precipitate is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;
		
	case nessler:
         if ( C == AMMONIUM )
		{
			cout << " A brown precipitate is formed!";
		}
		else
			cout << " No characteristic observation!";
		break;
         
		
   }
   return 0;
}
