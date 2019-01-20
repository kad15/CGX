#include "Kml.h"
using namespace std;

Kml::~Kml()
{
    //dtor
}


void Kml::jsonToKmlPoint(ofstream &flux, const string& name, const string& jsonFile,const string& iconFile)
{
    ifstream ifs(jsonFile);
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);
//    cout << "Number of Hospitals: " << obj["Hospitals"].asUInt() << endl;
    string coordinates = "";
    const Json::Value& data = obj["data"]; // array of data
    for (int i = 0; i < (int) data.size(); i++) {
        for (int j = 0; j<2; j++) {
            coordinates+= data[i][j].asString();
            coordinates+=",";
        }
        coordinates+= data[i][2].asString();
        writeKmlPoint(flux, name, iconFile, coordinates);
        coordinates="";
    }
    ifs.close();
}



void Kml::jsonToKmlFlightPlan(ofstream &flux, \
                              const string& jsonFile,const string& iconFilePatient, \
                              const string& color, const string& width)
{
    ifstream ifs(jsonFile);
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);
    string coordinatesHelicopter = "";
    string coordinatesPatient = "";
    string coordinatesHospital = "";
    string coordinatesBaseDestination = "";
    string flightPlan = "";

    /** data: array of flight plans */
    const Json::Value& data = obj["data"];
    /** numberOfMissions is also the number of patients as there is only 1 patient per mission;
    Indeed, an helicopter transports one patient at a time.
    */
    int numberOfMissions = (int) data.size();
    /** i is used to browse the flight plans and
        is the rank of the mission: for the first mission i=0 and so on
        j browse the coordinates in each flight plan
    */
    for (int i = 0; i < numberOfMissions; i++) {
        for (int j = 0; j<2; j++) {
            coordinatesHelicopter += data[i][j].asString();
            coordinatesHelicopter += ",";
        }
        coordinatesHelicopter += data[i][2].asString();
       // cout << "toto :" << coordinatesHelicopter<<endl;

        for (int j = 3; j<5; j++) {
            coordinatesPatient += data[i][j].asString();
            coordinatesPatient += ",";
        }
        coordinatesPatient += data[i][5].asString();

        for (int j = 6; j<8; j++) {
            coordinatesHospital += data[i][j].asString();
            coordinatesHospital += ",";
        }
        coordinatesHospital += data[i][8].asString();

        for (int j = 9; j<11; j++) {
            coordinatesBaseDestination += data[i][j].asString();
            coordinatesBaseDestination += ",";
        }
        coordinatesBaseDestination += data[i][11].asString();
        flightPlan = coordinatesHelicopter + " " + \
                     coordinatesPatient + " " + \
                     coordinatesHospital + " " + \
                     coordinatesBaseDestination;
        /* the first mission 0 is correct as there is only 3 legs, in the flight plan.
         not 4 as it seems,
         it turns out that the helicopter performing the mission 0 fly over an other base
         which can be wrongly seen as a 4-leg flight plan. !!
        cout << "toto :" << flightPlan<<endl;
        */
        writeKmlPointTime(flux, to_string(i), iconFilePatient, coordinatesPatient, to_string(i));
        writeKmlLinesTime(flux, flightPlan, color, width,i);
        coordinatesHelicopter = "";
        coordinatesPatient = "";
        coordinatesHospital = "";
        coordinatesBaseDestination = "";

    }
    ifs.close();
}

void Kml::writeKmlHead(ofstream & flux)
{
    string head = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    head += "<kml xmlns=\"http://www.opengis.net/kml/2.2\" ";
    head += "xmlns:gx=\"http://www.google.com/kml/ext/2.2\" ";
    head += "xmlns:kml=\"http://www.opengis.net/kml/2.2\" ";
    head += "xmlns:atom=\"http://www.w3.org/2005/Atom\">\n";
    head += "<Document>";

    flux<< head <<endl;

}



void Kml::writeKmlPoint(ofstream & flux, const string& name, const string& iconFile, const string& coordinates)
{
    string point = "<Placemark>\n";
    point += "<name>";
    point += name ;
    point +="</name>\n";
    point += "<Style>\n";
    point += "  <IconStyle>\n";
    point += "      <Icon>\n";
    point += "        <href>";
    point += iconFile ;
    point +="</href>\n";
    point += "      </Icon>\n";
    point += "  </IconStyle>\n";
    point += "</Style>\n";
    point += "<Point>\n";
    point += "  <coordinates>";
    point += coordinates ;
    point +="</coordinates>\n";
    point += "</Point>\n";
    point += "</Placemark>\n";
    flux << point << endl;
}

//note: time stamp example value for UTC i.e. zulu time: 1997-07-16T08:30:15Z

void Kml::writeKmlPointTime(ofstream & flux, const string& name, const string& iconFile, const string& coordinates, const string& animationRank)
{
    string point = "<Placemark>\n";

    point += "<name>";
    point += name ;
    point += "</name>\n";
    point += "<TimeStamp><when>" + animationRank +"</when></TimeStamp>\n";
    point += "<Style>\n";
    point += "  <IconStyle>\n";
    point += "      <Icon>\n";
    point += "        <href>";
    point += iconFile ;
    point +="</href>\n";
    point += "      </Icon>\n";
    point += "  </IconStyle>\n";
    point += "</Style>\n";
    point += "<Point>\n";
    point += "  <coordinates>";
    point += coordinates ;
    point +="</coordinates>\n";
    point += "</Point>\n";
    point += "</Placemark>\n";
    flux << point << endl;
}

void Kml::writeKmlLines(ofstream & flux, const string& path,const string& color, const string& width)
{
    string lines = "<Placemark>\n";
    lines += "<Style>\n";
    lines += "  <LineStyle>\n";
    lines += "      <color>";
    lines += color;
    lines += "</color>\n";
    lines += "      <width>";
    lines += width;
    lines += "</width>\n";
    lines += "  </LineStyle>\n";
    lines += "</Style>\n";
    lines += "<LineString>\n";
    lines += "  <coordinates>";
    lines += path ;
    lines +="  </coordinates>\n";
    lines += "</LineString>\n";
    lines += "</Placemark>\n";
    flux << lines << endl;
}

void Kml::writeKmlLinesTime(ofstream & flux, const string& path,const string& color, const string& width, const int animationRank)
{
    string lines = "<Placemark>\n";
    lines += "<TimeStamp><when>" + to_string(animationRank) +"</when></TimeStamp>\n";
    lines += "<Style>\n";
    lines += "  <LineStyle>\n";
    lines += "      <color>";
    lines += color;
    lines += "</color>\n";
    lines += "      <width>";
    lines += width;
    lines += "</width>\n";
    lines += "  </LineStyle>\n";
    lines += "</Style>\n";
    lines += "<LineString>\n";
    lines += "  <coordinates>";
    lines += path ;
    lines +="  </coordinates>\n";
    lines += "</LineString>\n";
    lines += "</Placemark>\n";
    flux << lines << endl;
}


void Kml::writeKmlTail(ofstream & flux)
{
    string tail = "</Document>\n</kml>";
    flux<< tail <<endl;
}

