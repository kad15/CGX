#ifndef KML_H
#define KML_H
#include <string>
#include <iostream>
#include <string>
#include <fstream>

// using namespace std; supprimé pour éviter la propagation
// du namespace std dans les fichiers qui incluent Kml.h
// avec le risque d'ambiuités sur le nom.
// it's boring to have to add std:: each time though !


/** dnf install jsoncpp.x86_64 jsoncpp-doc.noarch jsoncpp-devel.x86_64
Compilation : g++ -o alice alice.cpp -ljsoncpp
ajouter libjsoncpp dans project > build options > linker setting pour compiler avec g++ -ljsoncpp
*/
#include <json/json.h> // or jsoncpp/json.h , or json/json.h etc. works fine on fedora, on ubuntu maybe not.



/** Produces a kml file from json data*/
class Kml
{

public:
    /**
    usage example :
    #include "Kml.h"
    using namespace std;

    int main()
    {
    string kmlFic = "kml/vizu.kml";
    ofstream flux (kmlFic);
    if(flux) {
        Kml::writeKmlHead(flux);
        Kml::jsonToKmlPoint(flux,"", "data/hospitals.json","files/hospital.png");
        Kml::jsonToKmlPoint(flux,"","data/bases.json","files/heliport.png");
        string color ="ffff0000";
        string width = "1";
        Kml::jsonToKmlFlightPlan(flux, "", \
                                 "data/flightPlan.json", \
                                 "files/patient.png", color, width);
        Kml::writeKmlTail(flux);
        flux.close();
    } else {
        cout << "ERREUR fichier "<<  kmlFic << endl;
    }

    system("zip -r kml/vizu.kmz kml/files/ " + *kmlFic.c_str());

}



    Creates the kml file associated to flux from a json file using png icon in iconFile
    name : string that will be displayed near the point. name = "" to display nothing
    jsonFile : name of the json file on disk. e.g. jsonFile = "data/hospitals.json
    iconFile : name of icon file to display. e.g. iconfile = "files/hospital.png"
     */
    static void jsonToKmlPoint(std::ofstream &flux, const std::string& name, const std::string& jsonFile,const std::string& iconFile);

    /** Write the kml to draw the flight plan i.e. the path from the helicopter, to the patient, to the hospital
    and then to the destination base.  */
    static void jsonToKmlFlightPlan(std::ofstream& flux, \
                             const std::string& jsonFile,const std::string& iconFilePatient, \
                             const std::string& color, const std::string& width);

    /** write the head of the kml */
    static void writeKmlHead(std::ofstream &flux);
    /** write the "tail" of the kml */
    static void writeKmlTail(std::ofstream &flux);

    /** Default constructor */
    Kml();
    /** Default destructor */
    virtual ~Kml();
    /** Write a point of interest (POI)
    at the coordinates given in the string lon,lat,alt.
    The string name is displayed as a caption in google earth.
    can be used to name a hospital or to show the number of helicopters in a base.
      */
    static void writeKmlPoint(std::ofstream & flux, \
                              const std::string& name, \
                              const std::string& iconFile, \
                              const std::string& coordinates);
    /** "Draw" progressively in time a point using time stamp ; animationRank is the order of display of the point  */
    static void writeKmlPointTime(std::ofstream & flux, \
                              const std::string& name, \
                              const std::string& iconFile, \
                              const std::string& coordinates,\
                              const std::string& animationRank);
    /** "Draw" the flight of an helicopter from base 1 to the patient
    then to the hospital and the destination base 2 : PLN bphb'.
    The mission path is a serie of coordinates lon,lat,alt separated by a space character*/
    static void writeKmlLines(std::ofstream & flux, \
                              const std::string& path, \
                              const std::string& color, \
                              const std::string& width);
    /** Same as writeKmlLines except for the timestamp which is here a simple integer.
    This integer animationRank determine the order in which the flight plans will be displayed.
    it is the same order as the one of the patients.
    Warning : The display of patients and flight plans is in the temporal order of the "patients" call
    not necessarily the real overall time line since a second demand of sanitary transportation can arrive
    before the first mission is completed.
     */
    static void writeKmlLinesTime(std::ofstream & flux, \
                              const std::string& path, \
                              const std::string& color, \
                              const std::string& width,
                              const int animationRank);
private:

};

#endif // KML_H
