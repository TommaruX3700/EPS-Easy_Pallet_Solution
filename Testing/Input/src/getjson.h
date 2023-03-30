#ifndef GETJSON_H
#define GETJSON_H

#include "pacco.h"
#include <vector>
#include "../libraries/rapidjson/document.h"
#include "../libraries/rapidjson/rapidjson.h"
using namespace std;



void getJson(int i, Pacco pacco, rapidjson::Document& document, vector<Pacco>& pacchi, vector<Pacco>& pacchiNP, rapidjson::Document& pallettizzabili, rapidjson::Document& non_pallettizzabili){

    if(document[i]["BASE_MAGGIORE"].GetType()==6){
        pacco.x = document[i]["BASE_MAGGIORE"].GetDouble();
    } else {
        pacco.x = stod(document[i]["BASE_MAGGIORE"].GetString());
    }

    if(document[i]["BASE_MINORE"].GetType()==6){
        pacco.y = document[i]["BASE_MINORE"].GetDouble();
    } else {
        pacco.y = stod(document[i]["BASE_MINORE"].GetString());
    }

    if(document[i]["ALTEZZA"].GetType()==6){
        pacco.z = document[i]["ALTEZZA"].GetDouble();
    } else {
        pacco.z = stod(document[i]["ALTEZZA"].GetString());
    }

    if(document[i]["PESO_LORDO"].GetType()==6){
        pacco.peso = document[i]["PESO_LORDO"].GetDouble();
    } else {
        pacco.peso = stod(document[i]["PESO_LORDO"].GetString());
    }

    pacco.n_collo = document[i]["NUMERO_COLLO"].GetInt();

    if(document[i]["FLAG_RUOTABILE"].GetString()==""){
        pacco.ruotabile = true;
    } else {
        pacco.ruotabile = false;
    }


    if(document[i]["FLAG_PALETTIZZABILE"]!="N"){
        pacchi.push_back(pacco);
        rapidjson::Value pacco_json(rapidjson::kObjectType);
        pacco_json.AddMember("NUMERO_COLLO", pacco.n_collo, pallettizzabili.GetAllocator());
        pacco_json.AddMember("x", pacco.x, pallettizzabili.GetAllocator());
        pacco_json.AddMember("y", pacco.y, pallettizzabili.GetAllocator());
        pacco_json.AddMember("z", pacco.z, pallettizzabili.GetAllocator());
        pallettizzabili.PushBack(pacco_json, pallettizzabili.GetAllocator());
    } else {
        pacchiNP.push_back(pacco);
        rapidjson::Value pacco_json(rapidjson::kObjectType);
        pacco_json.AddMember("NUMERO_COLLO", pacco.n_collo, non_pallettizzabili.GetAllocator());
        pacco_json.AddMember("x", pacco.x, non_pallettizzabili.GetAllocator());
        pacco_json.AddMember("y", pacco.y, non_pallettizzabili.GetAllocator());
        pacco_json.AddMember("z", pacco.z, non_pallettizzabili.GetAllocator());
        non_pallettizzabili.PushBack(pacco_json, non_pallettizzabili.GetAllocator());
    }

}

#endif