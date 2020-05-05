#include "PlayingField.h"
#include<VersionInfo.h>

PlayingField::PlayingField(wistream &is, wostream & os): input(is), output(os)
{
    //Array-Initialisierung
    SpielFeld = new Tile *[4];
    for(int i=0; i<4; i++){
        SpielFeld[i]=new Tile[4];
    }

    richtung=0;//Startwert ohne Richtung

    //Fuer Zufallzahlen
    srand(time(NULL));

    //Zwei Felder muessen am Anfang des Spiels einen Wert haben
    setWerteAnFelder(freiFeldSuche());
    setWerteAnFelder(freiFeldSuche());

    ausgabe();
}

void PlayingField::ausgabe()
{
    for(int i=0;i<4; i++){
        for(int j=0; j<4;j++){
            cout<<SpielFeld[i][j].getWert()<<"\t";
            }
        cout<<endl;
    }
    cout<<"******************************"<<endl;
}

void PlayingField::start()
{
    while(1){
        move();
    }
}

void PlayingField::run()
{
    output << L"Welcome to 2048"<<endl;//ohne "L" geht es auch
    output << L"Version: " << VersionInfo::getVersion().toStdWString()
       << L" (" << VersionInfo::getBuildTag().toStdWString() << ")" << endl;
    output << L"Geben Sie 'b' fuer Anfang ein:";
    wstring fuerB;
    getline(input, fuerB);

    if( !input.eof()){
       output << L"\nLeere Eingabe, bitte wiederholen!\n"
             L"Geben Sie 'b' fuer Anfang ein:";
    }


    output << L"\nThank you for your wasted time."<<endl;

}

void PlayingField::setAlleFelderBesetzt()
{
    for(int i=0;i<4;i++){
        for(int j=0; j<4;j++){
            SpielFeld[i][j].setFrei(false);
        }
    }
}

void PlayingField::setEinFeldFrei()
{
    int xZufall=rand()%4;//Gueltige Werte (0..3)
    int yZufall=rand()%4;//Gueltige Werte (0..3)
    SpielFeld[xZufall][yZufall].setFrei(true);

//    for(int i=0;i<4; i++){
//        for(int j=0; j<4;j++){
//            cout<<SpielFeld[i][j].getFrei()<<"\t";
//            }
//        cout<<endl;
//    }
//    cout<<"******************************"<<endl;

}

unsigned int PlayingField::zufallZahl()
{
    //Um 10% Wahrscheinlichkeit zu bekommen
    unsigned int zufallZahlTemp=rand()%10;

    if(zufallZahlTemp){//Falls Werte(1..9) Wahrscheinlichkeit 90%
       return 2;
    }else {            //Falls Wert(0) Wahrscheinlichkeit 10%
       return 4;
    }
}

int * PlayingField::freiFeldSuche()
{
    static int koordinaten[2];//Fuer Rueckgabewerte
    const int unset =-1;

    //Hilfsarray fuer Berechnung besetzter Felder
    int arrayHilfe[4][4];
    //Alle Elemente mit "1" markieren
    for(int i=0;i<4; i++){
        for(int j=0; j<4;j++){
            arrayHilfe[i][j]=1;
            }
    }

    //Berechnung der Koordinaten der freien Felder
    while (1) {
        int xZufall=rand()%4;//Gueltige Werte (0..3)
        int yZufall=rand()%4;//Gueltige Werte (0..3)

        //Wenn das Feld frei ist, seine Koordinaten muessen zurueckgegeben werden
        if(SpielFeld[xZufall][yZufall].getFrei()){
            koordinaten[0]=xZufall;
            koordinaten[1]=yZufall;
            return koordinaten;       
         }

        //wenn nicht frei
        else{
            arrayHilfe[xZufall][yZufall]=0;//Mit "0" markieren
            int summ=0;//Wenn alle Felder besetzt sind, summ wird unveraendert
            for(int i=0;i<4; i++){
                for(int j=0; j<4;j++){
                    summ+=arrayHilfe[i][j];//Anzahl freier Felder
                    }
            }
            if(!summ){//Falls es  kein freies Feld gibt
                koordinaten[0]=unset;
                koordinaten[1]=unset;
                return koordinaten;
            }
        }
     }
}

void PlayingField::setWerteAnFelder(int *arr)
{
    SpielFeld[arr[0]][arr[1]].setWert(zufallZahl());
    SpielFeld[arr[0]][arr[1]].setFrei(false);//Nach Zuweisung des Werts, ist das Feld nicht mehr frei
}

void PlayingField::gameOver()
{
    cout<<"Game Over"<<endl;
    exit(0);
}

void PlayingField::move(){

    onKeyboardPush();

    int cnt=0;
    int cnt_2=0;//benutzt falls 2 besitzte Felder in Zeile oder Spalte
    int startPosition;
    int endPosition;
    int aenderung;
    Tile help, help_2, help_3, help_4;

    if(richtung==1 || richtung==3){
        startPosition=0;
        endPosition=3;
        aenderung=1;
    }else if(richtung==2 || richtung==4){
        startPosition=3;
        endPosition=0;
        aenderung=-1;
    }


    // /////////////////////////////////////////////////////////////////////////
    //Right/////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////////

    if(richtung==1){
        for(int i=startPosition; i<=endPosition; i+=aenderung){

            //Zaehlen besetzte Felder in Zeile
            for(int j=0; j<4; j++){
                if(!SpielFeld[i][j].getFrei()){
                    cnt++;
                }
            }

            //Falls 1 besetztes Feld/////////////////////////////////////////////
            if(cnt==1){
                for(int j=startPosition; j<endPosition; j+=aenderung){
                    if(!SpielFeld[i][j].getFrei()){
                        SpielFeld[i][endPosition]=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                    }
                }

            //Falls 2 besetzte Felder/////////////////////////////////////////////
            } else if(cnt==2){
                for(int j=startPosition; j<=endPosition; j+=aenderung){

                    //Falls erstes besetztes Feld in Zeile/Spalte
                    if((!SpielFeld[i][j].getFrei()) && cnt_2==0){
                        help=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls zweites besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==1){
                        help_2=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                    }
                 }
                        //Falls die Werte gleich sind
                        if(help_2.getWert()==help.getWert()){
                            SpielFeld[i][endPosition]=help_2;
                            SpielFeld[i][endPosition].setWert(help_2.getWert()*2);
                        }
                        //Fals die Werte nicht gleich sind
                        else{
                            SpielFeld[i][endPosition]=help_2;
                            SpielFeld[i][endPosition-aenderung]=help;
                        }

          //Falls 3 besetzte Felder///////////////////////////////////////////////
            }else if(cnt==3){

                for(int j=endPosition; j>=startPosition; j-=aenderung){

                    //Falls erstes besetztes Feld in Zeile/Spalte
                    if((!SpielFeld[i][j].getFrei()) && cnt_2==0){
                        help=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls zweites besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==1){
                        help_2=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls drittes besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==2){
                        help_3=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        }
                    }

                //Falls die Werte 1 und 2 Felder gleich sind
                if(help.getWert()==help_2.getWert()){
                    SpielFeld[i][endPosition]=help_2;
                    SpielFeld[i][endPosition].setWert(help_2.getWert()*2);
                    SpielFeld[i][endPosition-aenderung]=help_3;
                }

                //Fals die Werte 1 und 2 Felder nicht gleich sind
                else{
                    SpielFeld[i][endPosition]=help;

                    //Fals die Werte 2 und 3 Felder gleich sind
                    if(help_2.getWert()==help_3.getWert()){
                        SpielFeld[i][endPosition-aenderung]=help_2;
                        SpielFeld[i][endPosition-aenderung].setWert(help_2.getWert()*2);

                    //Fals die Werte 2 und 3 Felder nicht gleich sind
                    }else{
                        SpielFeld[i][endPosition-aenderung]=help_2;
                        SpielFeld[i][endPosition-2*aenderung]=help_3;
                    }
                }

             //Falls 4 besetzte Felder///////////////////////////////////////////////
             }else if (cnt==4){

                //Ausfuelung der Hilfsobjekte
                help=SpielFeld[i][endPosition];
                help_2=SpielFeld[i][endPosition-aenderung];
                help_3=SpielFeld[i][endPosition-2*aenderung];
                help_4=SpielFeld[i][endPosition-3*aenderung];

                //Reinigung
                for(int k=0; k<=endPosition; k++){
                    SpielFeld[i][k].setFrei(true);
                    SpielFeld[i][k].setWert(0);
                }

                //1==2
                if(help.getWert()==help_2.getWert()){
                    SpielFeld[i][endPosition]=help;
                    SpielFeld[i][endPosition].setWert(help.getWert()*2);

                    //3==4
                    if(help_3.getWert()==help_4.getWert()){
                         SpielFeld[i][endPosition-aenderung].setWert(help_3.getWert()*2);
                         SpielFeld[i][endPosition-aenderung].setFrei(false);
                    //3!=4
                    }else{
                        SpielFeld[i][endPosition-aenderung]=help_3;
                        SpielFeld[i][endPosition-2*aenderung]=help_4;
                    }
                //1!=2
                }else{
                    SpielFeld[i][endPosition]=help;

                    //2==3
                    if(help_2.getWert()==help_3.getWert()){
                         SpielFeld[i][endPosition-aenderung]=help_2;
                         SpielFeld[i][endPosition-aenderung].setWert(help_2.getWert()*2);
                         SpielFeld[i][endPosition-2*aenderung]=help_4;

                    //2!=3
                    }else{
                        SpielFeld[i][endPosition-aenderung]=help_2;

                        //3==4
                        if(help_3.getWert()==help_4.getWert()){
                            SpielFeld[i][endPosition-2*aenderung]=help_3;
                            SpielFeld[i][endPosition-2*aenderung].setWert(help_3.getWert()*2);

                        //3!=4
                        }else{
                            SpielFeld[i][endPosition-2*aenderung]=help_3;
                            SpielFeld[i][endPosition-3*aenderung]=help_4;
                        }
                    }
                }

            }
            //Reinigung
            cnt_2=0;
            cnt=0;
        }
    }


    // ///////////////////////////////////////////////////////////////////////
    //Left////////////////////////////////////////////////////////////////////
    // ///////////////////////////////////////////////////////////////////////

    if(richtung==2){
        for(int i=startPosition; i>=endPosition; i+=aenderung){

            //Zaehlen besetzte Felder in Zeile
            for(int j=0; j<4; j++){
                if(!SpielFeld[i][j].getFrei()){
                    cnt++;
                }
            }

            //Falls 1 besetztes Feld/////////////////////////////////////////////
            if(cnt==1){
                for(int j=startPosition; j>endPosition; j+=aenderung){
                    if(!SpielFeld[i][j].getFrei()){
                        SpielFeld[i][endPosition]=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                    }
                }
            }

            //Falls 2 besetzte Felder/////////////////////////////////////////////
            else if(cnt==2){
                for(int j=startPosition; j>=endPosition; j+=aenderung){

                    //Falls erstes besetztes Feld in Zeile/Spalte
                    if((!SpielFeld[i][j].getFrei()) && cnt_2==0){
                        help=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls zweites besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==1){
                        help_2=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                    }
                }
                        //Falls die Werte gleich sind
                        if(help_2.getWert()==help.getWert()){
                            SpielFeld[i][endPosition]=help_2;
                            SpielFeld[i][endPosition].setWert(help_2.getWert()*2);
                        }

                        //Fals die Werte nicht gleich sind
                        else{
                            SpielFeld[i][endPosition]=help_2;
                            SpielFeld[i][endPosition-aenderung]=help;
                        }

          //Falls 3 besetzte Felder///////////////////////////////////////////////
            }else if(cnt==3){
                for(int j=endPosition; j<=startPosition; j-=aenderung){

                    //Falls erstes besetztes Feld in Zeile/Spalte
                    if((!SpielFeld[i][j].getFrei()) && cnt_2==0){
                        help=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls zweites besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==1){
                        help_2=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls drittes besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==2){
                        help_3=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        }
                    }

                //Falls die Werte 1 und 2 Felder gleich sind
                if(help.getWert()==help_2.getWert()){
                    SpielFeld[i][endPosition]=help_2;
                    SpielFeld[i][endPosition].setWert(help_2.getWert()*2);
                    SpielFeld[i][endPosition-aenderung]=help_3;
                }

                //Fals die Werte 1 und 2 Felder nicht gleich sind
                else{
                    SpielFeld[i][endPosition]=help;

                    //Fals die Werte 2 und 3 Felder gleich sind
                    if(help_2.getWert()==help_3.getWert()){
                        SpielFeld[i][endPosition-aenderung]=help_2;
                        SpielFeld[i][endPosition-aenderung].setWert(help_2.getWert()*2);

                    //Fals die Werte 2 und 3 Felder nicht gleich sind
                    }else{
                        SpielFeld[i][endPosition-aenderung]=help_2;
                        SpielFeld[i][endPosition-2*aenderung]=help_3;
                    }
                }

             //Falls 4 besetzte Felder///////////////////////////////////////////////
             }else if (cnt==4){

                //Ausfuelung der Hilfsobjekte
                help=SpielFeld[i][endPosition];
                help_2=SpielFeld[i][endPosition-aenderung];
                help_3=SpielFeld[i][endPosition-2*aenderung];
                help_4=SpielFeld[i][endPosition-3*aenderung];

                //Reinigung
                for(int k=0; k<4; k++){
                    SpielFeld[i][k].setFrei(true);
                    SpielFeld[i][k].setWert(0);
                }

                //1==2
                if(help.getWert()==help_2.getWert()){
                    SpielFeld[i][endPosition]=help;
                    SpielFeld[i][endPosition].setWert(help.getWert()*2);

                    //3==4
                    if(help_3.getWert()==help_4.getWert()){
                         SpielFeld[i][endPosition-aenderung].setWert(help_3.getWert()*2);
                         SpielFeld[i][endPosition-aenderung].setFrei(false);
                    //3!=4
                    }else{
                        SpielFeld[i][endPosition-aenderung]=help_3;
                        SpielFeld[i][endPosition-2*aenderung]=help_4;
                    }
                //1!=2
                }else{
                    SpielFeld[i][endPosition]=help;

                    //2==3
                    if(help_2.getWert()==help_3.getWert()){
                         SpielFeld[i][endPosition-aenderung]=help_2;
                         SpielFeld[i][endPosition-aenderung].setWert(help_2.getWert()*2);
                         SpielFeld[i][endPosition-2*aenderung]=help_4;

                    //2!=3
                    }else{
                        SpielFeld[i][endPosition-aenderung]=help_2;

                        //3==4
                        if(help_3.getWert()==help_4.getWert()){
                            SpielFeld[i][endPosition-2*aenderung]=help_3;
                            SpielFeld[i][endPosition-2*aenderung].setWert(help_3.getWert()*2);

                        //3!=4
                        }else{
                            SpielFeld[i][endPosition-2*aenderung]=help_3;
                            SpielFeld[i][endPosition-3*aenderung]=help_4;
                        }
                    }
                }

            }
            //Reinigung
            cnt_2=0;
            cnt=0;
        }
    }


    // /////////////////////////////////////////////////////////////////////////
    //Down//////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////////

    if(richtung==3){
        for(int j=startPosition; j<=endPosition; j+=aenderung){

            //Zaehlen besetzte Felder in Spalte
            for(int i=0; i<4; i++){
                if(!SpielFeld[i][j].getFrei()){
                    cnt++;
                }
            }

            //Falls 1 besetztes Feld/////////////////////////////////////////////
            if(cnt==1){
                for(int i=startPosition; i<endPosition; i+=aenderung){
                    if(!SpielFeld[i][j].getFrei()){
                        SpielFeld[endPosition][j]=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                    }
                }

            //Falls 2 besetzte Felder/////////////////////////////////////////////
            } else if(cnt==2){
                for(int i=startPosition; i<=endPosition; i+=aenderung){

                    //Falls erstes besetztes Feld in Zeile/Spalte
                    if((!SpielFeld[i][j].getFrei()) && cnt_2==0){
                        help=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls zweites besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==1){
                        help_2=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                    }
                 }
                        //Falls die Werte gleich sind
                        if(help_2.getWert()==help.getWert()){
                            SpielFeld[endPosition][j]=help_2;
                            SpielFeld[endPosition][j].setWert(help_2.getWert()*2);
                        }
                        //Fals die Werte nicht gleich sind
                        else{
                            SpielFeld[endPosition][j]=help_2;
                            SpielFeld[endPosition-aenderung][j]=help;
                        }

          //Falls 3 besetzte Felder///////////////////////////////////////////////
            }else if(cnt==3){

                for(int i=endPosition; i>=startPosition; i-=aenderung){

                    //Falls erstes besetztes Feld in Zeile/Spalte
                    if((!SpielFeld[i][j].getFrei()) && cnt_2==0){
                        help=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls zweites besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==1){
                        help_2=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls drittes besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==2){
                        help_3=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        }
                    }

                //Falls die Werte 1 und 2 Felder gleich sind
                if(help.getWert()==help_2.getWert()){
                    SpielFeld[endPosition][j]=help_2;
                    SpielFeld[endPosition][j].setWert(help_2.getWert()*2);
                    SpielFeld[endPosition-aenderung][j]=help_3;
                }

                //Fals die Werte 1 und 2 Felder nicht gleich sind
                else{
                    SpielFeld[endPosition][j]=help;

                    //Fals die Werte 2 und 3 Felder gleich sind
                    if(help_2.getWert()==help_3.getWert()){
                        SpielFeld[endPosition-aenderung][j]=help_2;
                        SpielFeld[endPosition-aenderung][j].setWert(help_2.getWert()*2);

                    //Fals die Werte 2 und 3 Felder nicht gleich sind
                    }else{
                        SpielFeld[endPosition-aenderung][j]=help_2;
                        SpielFeld[endPosition-2*aenderung][j]=help_3;
                    }
                }

             //Falls 4 besetzte Felder///////////////////////////////////////////////
             }else if (cnt==4){

                //Ausfuelung der Hilfsobjekte
                help=SpielFeld[endPosition][j];
                help_2=SpielFeld[endPosition-aenderung][j];
                help_3=SpielFeld[endPosition-2*aenderung][j];
                help_4=SpielFeld[endPosition-3*aenderung][j];

                //Reinigung
                for(int k=0; k<=endPosition; k++){
                    SpielFeld[k][j].setFrei(true);
                    SpielFeld[k][j].setWert(0);
                }

                //1==2
                if(help.getWert()==help_2.getWert()){
                    SpielFeld[endPosition][j]=help;
                    SpielFeld[endPosition][j].setWert(help.getWert()*2);

                    //3==4
                    if(help_3.getWert()==help_4.getWert()){
                         SpielFeld[endPosition-aenderung][j].setWert(help_3.getWert()*2);
                         SpielFeld[endPosition-aenderung][j].setFrei(false);
                    //3!=4
                    }else{
                        SpielFeld[endPosition-aenderung][j]=help_3;
                        SpielFeld[endPosition-2*aenderung][j]=help_4;
                    }
                //1!=2
                }else{
                    SpielFeld[endPosition][j]=help;

                    //2==3
                    if(help_2.getWert()==help_3.getWert()){
                         SpielFeld[endPosition-aenderung][j]=help_2;
                         SpielFeld[endPosition-aenderung][j].setWert(help_2.getWert()*2);
                         SpielFeld[endPosition-2*aenderung][j]=help_4;

                    //2!=3
                    }else{
                        SpielFeld[endPosition-aenderung][j]=help_2;

                        //3==4
                        if(help_3.getWert()==help_4.getWert()){
                            SpielFeld[endPosition-2*aenderung][j]=help_3;
                            SpielFeld[endPosition-2*aenderung][j].setWert(help_3.getWert()*2);

                        //3!=4
                        }else{
                            SpielFeld[endPosition-2*aenderung][j]=help_3;
                            SpielFeld[endPosition-3*aenderung][j]=help_4;
                        }
                    }
                }

            }
            //Reinigung
            cnt_2=0;
            cnt=0;
        }
    }


    // ///////////////////////////////////////////////////////////////////////
    //Up//////////////////////////////////////////////////////////////////////
    // ///////////////////////////////////////////////////////////////////////

    if(richtung==4){
        for(int j=startPosition; j>=endPosition; j+=aenderung){

            //Zaehlen besetzte Felder in Spalte
            for(int i=0; i<4; i++){
                if(!SpielFeld[i][j].getFrei()){
                    cnt++;
                }
            }

            //Falls 1 besetztes Feld/////////////////////////////////////////////
            if(cnt==1){
                for(int i=startPosition; i>endPosition; i+=aenderung){
                    if(!SpielFeld[i][j].getFrei()){
                        SpielFeld[endPosition][j]=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                    }
                }
            }

            //Falls 2 besetzte Felder/////////////////////////////////////////////
            else if(cnt==2){
                for(int i=startPosition; i>=endPosition; i+=aenderung){

                    //Falls erstes besetztes Feld in Zeile/Spalte
                    if((!SpielFeld[i][j].getFrei()) && cnt_2==0){
                        help=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls zweites besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==1){
                        help_2=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                    }
                }
                        //Falls die Werte gleich sind
                        if(help_2.getWert()==help.getWert()){
                            SpielFeld[endPosition][j]=help_2;
                            SpielFeld[endPosition][j].setWert(help_2.getWert()*2);
                        }

                        //Fals die Werte nicht gleich sind
                        else{
                            SpielFeld[endPosition][j]=help_2;
                            SpielFeld[endPosition-aenderung][j]=help;
                        }

          //Falls 3 besetzte Felder///////////////////////////////////////////////
            }else if(cnt==3){
                for(int i=endPosition; i<=startPosition; i-=aenderung){

                    //Falls erstes besetztes Feld in Zeile/Spalte
                    if((!SpielFeld[i][j].getFrei()) && cnt_2==0){
                        help=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls zweites besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==1){
                        help_2=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        cnt_2++;
                    }

                    //Falls drittes besetztes Feld in Zeile/Spalte
                    if(((!SpielFeld[i][j].getFrei())) && cnt_2==2){
                        help_3=SpielFeld[i][j];
                        SpielFeld[i][j].setFrei(true);
                        SpielFeld[i][j].setWert(0);
                        }
                    }

                //Falls die Werte 1 und 2 Felder gleich sind
                if(help.getWert()==help_2.getWert()){
                    SpielFeld[endPosition][j]=help_2;
                    SpielFeld[endPosition][j].setWert(help_2.getWert()*2);
                    SpielFeld[endPosition-aenderung][j]=help_3;
                }

                //Fals die Werte 1 und 2 Felder nicht gleich sind
                else{
                    SpielFeld[endPosition][j]=help;

                    //Fals die Werte 2 und 3 Felder gleich sind
                    if(help_2.getWert()==help_3.getWert()){
                        SpielFeld[endPosition-aenderung][j]=help_2;
                        SpielFeld[endPosition-aenderung][j].setWert(help_2.getWert()*2);
                    }

                    //Fals die Werte 2 und 3 Felder nicht gleich sind
                    else{
                        SpielFeld[endPosition-aenderung][j]=help_2;
                        SpielFeld[endPosition-2*aenderung][j]=help_3;
                    }
                }
             }

            //Falls 4 besetzte Felder///////////////////////////////////////////////
            else if (cnt==4){

                //Ausfuelung der Hilfsobjekte
                help=SpielFeld[endPosition][j];
                help_2=SpielFeld[endPosition-aenderung][j];
                help_3=SpielFeld[endPosition-2*aenderung][j];
                help_4=SpielFeld[endPosition-3*aenderung][j];

                //Reinigung
                for(int k=0; k<4; k++){
                    SpielFeld[k][j].setFrei(true);
                    SpielFeld[k][j].setWert(0);
                }

                //1==2
                if(help.getWert()==help_2.getWert()){
                    SpielFeld[endPosition][j]=help;
                    SpielFeld[endPosition][j].setWert(help.getWert()*2);

                    //3==4
                    if(help_3.getWert()==help_4.getWert()){
                         SpielFeld[endPosition-aenderung][j].setWert(help_3.getWert()*2);
                         SpielFeld[endPosition-aenderung][j].setFrei(false);
                    }

                    //3!=4
                    else{
                        SpielFeld[endPosition-aenderung][j]=help_3;
                        SpielFeld[endPosition-2*aenderung][j]=help_4;
                    }

                //1!=2
                }else{
                    SpielFeld[endPosition][j]=help;

                    //2==3
                    if(help_2.getWert()==help_3.getWert()){
                         SpielFeld[endPosition-aenderung][j]=help_2;
                         SpielFeld[endPosition-aenderung][j].setWert(help_2.getWert()*2);
                         SpielFeld[endPosition-2*aenderung][j]=help_4;
                    }

                    //2!=3
                    else{
                        SpielFeld[endPosition-aenderung][j]=help_2;

                        //3==4
                        if(help_3.getWert()==help_4.getWert()){
                            SpielFeld[endPosition-2*aenderung][j]=help_3;
                            SpielFeld[endPosition-2*aenderung][j].setWert(help_3.getWert()*2);
                        }

                        //3!=4
                        else{
                            SpielFeld[endPosition-2*aenderung][j]=help_3;
                            SpielFeld[endPosition-3*aenderung][j]=help_4;
                        }
                    }
                }

            }
            //Reinigung
            cnt_2=0;
            cnt=0;
        }
    }

    //Reinigung
    help.setFrei(true);
    help.setWert(0);
    help_2.setFrei(true);
    help_2.setWert(0);
    help_3.setFrei(true);
    help_3.setWert(0);
    help_4.setFrei(true);
    help_4.setWert(0);

    winPruefung();
    obFreifeldGibt();
    setWerteAnFelder(freiFeldSuche());
    ausgabe();
}

int PlayingField::onKeyboardPush(){
    char eingabe;

    while(true){
        cout << "Geben sie die Richtung ein (w-up, s-down, a-left, b-right)"<<endl;
        cin>>eingabe;

        switch(eingabe) {// ждёт нажатия на клаву без Enter после этого
            case 'w': cout << "Up" << endl; richtung=4; return 0;//up
            case 's': cout << "Down" << endl; richtung=3; return 0;//down
            case 'a': cout << "left" << endl; richtung=2; return 0;//links
            case 'd': cout << "Right"<< endl; richtung=1; return 0;//rechts
            case 'n': gameOver(); break;
            case 'q': gameOver(); break;
        default: break;
        }

       /* if(kbhit()) {// слушатель нажатия на клаву
            switch(getch()) {// ждёт нажатия на клаву без Enter после этого
                case 72: cout << "Up" << endl; richtung=4; return 0;//up
                case 80: cout << "Down" << endl; richtung=3; return 0;//down
                case 75: cout << "left" << endl; richtung=2; return 0;//links
                case 77: cout << "Right"<< endl; richtung=1; return 0;//rechts
                case 'n': gameOver(); break;
                case 'q': gameOver(); break;
            }
        }*/
    }
}

void PlayingField::obFreifeldGibt()
{
    //Uebepruefung, ob es noch ein freies Feld gibt
    int anzahlFreiFelder=16;

    for(int i=0;i<4; i++){
        for(int j=0; j<4;j++){
            if(!SpielFeld[i][j].getFrei()){
                anzahlFreiFelder--;
            }
        }
    }

    //Es gibt kein freies Feld
    if(!anzahlFreiFelder){
        gameOver();
    }
}

void PlayingField::winPruefung()
{
    for(int i=0;i<4; i++){
        for(int j=0; j<4;j++){
            if(SpielFeld[i][j].getWert()>=2048){
                cout<<"WIN!!!!"<<endl;
                exit(0);
            }
        }
    }
}
