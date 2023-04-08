#pragma region "General Libraries"
    #include <iostream>
    #include <vector>
#pragma endregion

#pragma region "External Libraries"
    #include ".\libraries\external\rapidjson\document.h"
    #include ".\libraries\external\rapidjson\rapidjson.h"
#pragma endregion

#pragma region "Custom Made Libraries"
    #include ".\libraries\3D_Objects\headers\Pack.h"
    //#include ".\libraries\3D_Objects\headers\PalletGroup.h"
    //#include ".\libraries\3D_Objects\headers\SinglePallet.h"
    //#include ".\libraries\Geometry\headers\2DPlane.h"
#pragma endregion

#pragma region "Utilities"
    #include ".\libraries\Utility\src\inputmanager.cpp"
#pragma endregion

using namespace std;

int main(){

    vector<Pack> pallettizzabili;
    vector<Pack> non_pallettizzabili;

    cout<<"TEST INIZIALE"<<endl;

    inputmanager(pallettizzabili, non_pallettizzabili);

    cout<<"TEST FINALE"<<endl;

    cout<<pallettizzabili.size()<<endl;
    
    cout<<pallettizzabili[0].get_Dims()->x<<" "<<pallettizzabili[0].get_Dims()->y<<" "<<pallettizzabili[0].get_Dims()->z<<endl;

    return 0;
}