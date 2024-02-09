#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Session
{
public:
    Session()
    {
        parseData();
    }
    string getField(const string &line, const string fieldname)
    {
        auto pos = line.find(fieldname);
        if(pos!= std::string::npos)
        {
            cout<<line.substr(fieldname.length()+1,line.length()-fieldname.length());
            return std::move(line.substr(fieldname.length()+1,line.length()-fieldname.length()));
        }
        return "";
    }
    void parseData()
    {
        string myText;
        ifstream m_buffer("data/session_data.txt");
        while (getline (m_buffer, myText)) 
        {
            if(APIKEY.size()==0) APIKEY(std::move(getField(myText,"APIKEY"))); 
            if(SESSION.size()==0) SESSION(std::move(getField(myText,"SESSION")));
            if(SECRETKEY.size()==0) SECRETKEY(std::move(getField(myText,"SECRETKEY")));
            
        }            
        cout<<APIKEY<<endl<<SESSION<<endl<<SECRETKEY<<endl;
    }
    void login()
    {
        
    }

private:
    string APIKEY;
    string SECRETKEY;
    string SESSION;

};

