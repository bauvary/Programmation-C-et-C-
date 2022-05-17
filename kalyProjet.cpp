#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

/************* Declaration des fonctions : prototype *******************/

float loi_proba(int );

void calcul_alpha(float* ) ;

/***********************************************************************/

    /* Mon numéro d'étudiant est : 11817049 */
    const float a = 7 ;
    const float b = 10 ;
    const float c = 4 ;
    const float d = 9 ; 
    /****************************************/


#define alphaMin -10
#define alphaMax 10

/*********************************************************************/

int main(void)
{

    float alpha{1};
    cout << " premiere valeur de alpha est " << alpha << endl ;
    
    int x; // x : variable aléatoire compris entre -10 et 10
    auto P_x{0.0} ; // P_x : Probabilité de la variable aléatoire x
    cout << "Donner un nombre entier compris entre -10 et 10 " ;
    cin >> x ;

    if ( (x < alphaMin) || (x > alphaMax ) )
    {
        cout << "Erreur, donner un nombre entier compris ente -10 et 10 : " << endl ;
    }

    P_x = loi_proba(x);
    cout << " P(x) =  " << P_x << endl;
    
    calcul_alpha(&alpha);
    cout << "alpha = " << alpha << endl ;

    return 0;
}

/******************************** DEVELOPPEMENT DES FONCTIONS DECLAREES EN HAUT *********************************/


/*********************** La fonction loi_proba revoie la proba P(x) pour x dans [-10 , 10] **********************/

float loi_proba(int x )
{   
    return (  exp(-((x-c)*(x-c))/(d*d) ) + exp(-((x-a)*(x-a))/(b*b)) ) ;
}

/******** La fonction calcul alpha calcul la valeur de alpgh pour la proba P(x)=1 pour x dans [-10 , 10] ********/


void calcul_alpha(float* alpha) 
{
    auto summer{0.0};
    for (int x = alphaMin; x < alphaMax + 1 ; x++)
    {
        summer = summer + loi_proba(x);
    }
    *alpha =  1.0/summer ;
}