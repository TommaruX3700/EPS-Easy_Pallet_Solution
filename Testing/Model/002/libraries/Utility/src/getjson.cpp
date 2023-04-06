#include <vector>
#include "../../3D_Objects/headers/Pack.h"
#include "../../external/rapidjson/document.h"
#include "../../external/rapidjson/rapidjson.h"


using namespace std;



void getJson(int i, Pack pacco, rapidjson::Document& document, vector<Pack>& pacchi, vector<Pack>& pacchiNP){
    float x, y, z, peso;
    int n_collo;
    bool ruotabile;

    if(document[i]["BASE_MAGGIORE"].GetType()==6){
        x = document[i]["BASE_MAGGIORE"].GetDouble();
    } else {
        x = stod(document[i]["BASE_MAGGIORE"].GetString());
    }

    if(document[i]["BASE_MINORE"].GetType()==6){
        y = document[i]["BASE_MINORE"].GetDouble();
    } else {
        y = stod(document[i]["BASE_MINORE"].GetString());
    }

    if(document[i]["ALTEZZA"].GetType()==6){
        z = document[i]["ALTEZZA"].GetDouble();
    } else {
        z = stod(document[i]["ALTEZZA"].GetString());
    }

    if(document[i]["PESO_LORDO"].GetType()==6){
        peso = document[i]["PESO_LORDO"].GetDouble();
    } else {
        peso = stod(document[i]["PESO_LORDO"].GetString());
    }

    n_collo = (document[i]["NUMERO_COLLO"].GetInt());

    if(document[i]["FLAG_RUOTABILE"].GetString()==""){
        ruotabile=true;
    } else {
        ruotabile=false;
    }

    pacco=Pack(x, y, z, peso, n_collo, ruotabile);

    if(document[i]["FLAG_PALETTIZZABILE"]!="N"){
        pacchi.push_back(pacco);
    } else {
        pacchiNP.push_back(pacco);
    }
}
